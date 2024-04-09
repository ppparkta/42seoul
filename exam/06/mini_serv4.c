#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_clients{
    int id;
    char msg[1024];
}t_clients;

int maxfd=0, idnum=0;
fd_set readfds, writefds, active;
char readBuffer[120000], writeBuffer[120000];
t_clients clients[1024];

void fterror(char *msg){
    if (msg==NULL){
        msg="Fatal error";
    }
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
    exit(1);
}

void sendAll(int notFd){
    for(int i=0;i<=maxfd;i++){
        if (FD_ISSET(i, &writefds) && i != notFd){
            send(i, writeBuffer, strlen(writeBuffer), 0);
        }
    }
}

int main(int ac, char **av){
    int sockfd, connfd;

    if (ac!=2){
        fterror("Wrong number of arguments");
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		fterror(NULL);
	} 
    FD_ZERO(&active);
    bzero(&clients, sizeof(clients));
    maxfd=sockfd;
    FD_SET(sockfd, &active);

    struct sockaddr_in servaddr; 
    socklen_t len;

    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		fterror(NULL);
	} 
    if (listen(sockfd, 10) != 0) {
		fterror(NULL);
	}
    while(1){
        readfds=writefds=active;
        if (select(maxfd+1, &readfds, &writefds, NULL, NULL) < 0)
            continue;
        for(int fdI=0;fdI<=maxfd; fdI++){
            if (fdI==sockfd&&FD_ISSET(fdI, &readfds)){
                connfd = accept(sockfd, (struct sockaddr *)&servaddr, (socklen_t*)&len);
                if (connfd<0)
                    continue;
                maxfd = connfd>maxfd?connfd:maxfd;
                FD_SET(connfd, &active);
                clients[connfd].id=idnum++;
                sprintf(writeBuffer, "server: client %d just arrived\n", clients[fdI].id);
                sendAll(connfd);
                break;
            }
            if (fdI!=sockfd&&FD_ISSET(fdI, &readfds)){
                int res = recv(fdI, readBuffer, 65536, 0);
                if (res <= 0){
                    sprintf(writeBuffer, "server: client %d just left\n", clients[fdI].id);
                    sendAll(fdI);
                    FD_CLR(fdI, &active);
                    close(fdI);
                    break;
                } else {
                    for(int i=0,j=strlen(clients[fdI].msg);i<res;i++,j++){
                        clients[fdI].msg[j] = readBuffer[i];
                        if(clients[fdI].msg[j] == '\n'){
                            clients[fdI].msg[j]='\0';
                            sprintf(writeBuffer, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
                            sendAll(fdI);
                            bzero(&clients[fdI].msg, strlen(clients[fdI].msg));
                            j=-1;
                        }
                    }
                    break;
                }
            }
        }
    }
}