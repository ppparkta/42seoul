#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

typedef struct s_clients {
    int id;
    char msg[1024];
} t_clients;

t_clients clients[1024];
int maxfd=0, idnumber=0;
fd_set readfds, writefds, active;
char readBuffer[120000], writeBuffer[120000];

void fterror(char *msg){
    if (msg==NULL){
        msg="Fatal error";
    }
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
    exit(1);
}

void sendAll(int not){
    for(int i=0;i<=maxfd;i++){
        if(FD_ISSET(i, &writefds) && i!=not){
            send(i, writeBuffer, strlen(writeBuffer), 0);
        }
    }
}

int main(int ac, char **av){
    int sockfd, connfd;
    struct sockaddr_in servaddr;
    socklen_t len;
    if(ac!=2){
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
        readfds = writefds = active;
        if (select (maxfd + 1, &readfds, &writefds, NULL, NULL)<0)
            continue;
        for(int fdI=0;fdI<=maxfd;fdI++){
            if (FD_ISSET(fdI, &readfds) && fdI == sockfd){
                int connfd = accept(sockfd, (struct sockaddr *)&servaddr, (socklen_t*)&len);
                if (connfd<0)
                    continue;
                maxfd=connfd>maxfd?connfd:maxfd;
                clients[connfd].id=idnumber++;
                FD_SET(connfd, &active);
                sprintf(writeBuffer, "server: client %d just arrived\n", clients[connfd].id);
                sendAll(connfd);
                break;
            }
            if (FD_ISSET(fdI, &readfds) && fdI != sockfd){
                int res=recv(fdI, readBuffer, 65536, 0);
                if (res<=0){
                    sprintf(writeBuffer, "server: client %d just left\n", clients[fdI].id);
                    sendAll(fdI);
                    FD_CLR(fdI, &active);
                    close(fdI);
                    break;
                } 
                else {
                    for(int i=0,j=strlen(clients[fdI].msg); i<res;i++,j++){
                        clients[fdI].msg[j]=readBuffer[i];
                        if (clients[fdI].msg[j]=='\n'){
                            clients[fdI].msg[j]='\0';
                            sprintf(writeBuffer, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
                            sendAll(fdI);
                            bzero(clients[fdI].msg, strlen(clients[fdI].msg));
                            j=-1;
                        }
                    }
                    break;
                }
            }
        }
    }

}