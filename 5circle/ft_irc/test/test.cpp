#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <vector>
#include <poll.h>

int main(int argc, char **argv)
{
    char buffer[1024] = {0};
    std::vector<int> client_sockets;
    int port_num = std::stoi(argv[1]);
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        std::cerr << "socket error" << std::endl;
        return -1;
    }
    std::cout << "created socket! \n";
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;

    // 주소 초기화 후 ip & port 설정
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;                // ipv4 타입 설정
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // ip주소
    server_addr.sin_port = htons(port_num);          // port주소

    // 생성한 소켓과 ip&port 연결
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        std::cerr << "bind error" << std::endl;
        return -1;
    }
    std::cout << "binded socket! \n";

    // 연결 대기열 5개 생성
    if (listen(sock_fd, 5) == -1)
    {
        std::cerr << "listen error" << std::endl;
        return -1;
    }
    std::cout << "listen client! \n";

    struct pollfd poll_fds[1024];
    poll_fds[0].fd = sock_fd;
    poll_fds[0].events = POLL_IN;

    int num_fds = 1;

    while (1)
    {
        // poll 함수 사용하여 소켓 디스크립터 상태 모니터링
        int poll_count = poll(poll_fds, num_fds, -1);
        if (poll_count == -1)
        {
            std::cerr << "poll error" << std::endl;
            return -1;
        }
        for (int i = 0; i < num_fds; i++)
        {
            // 클라이언트 디스크립터 상태 확인
            if (poll_fds[i].revents & POLL_IN)
            {
                // 소켓 디스크립터 읽기 가능한 경우
                if (poll_fds[i].fd == sock_fd)
                {
                    // 새로운 클라이언트가 서버에 연결 요청한 경우
                    int client_sock = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_size);
                    if (client_sock == -1)
                    {
                        std::cerr << "accept error" << std::endl;
                        return -1;
                    }
                    else
                    {
                        client_sockets.push_back(client_sock);
                        std::cout << "client " << client_sock << " connected.\n";
                        poll_fds[num_fds].fd = client_sock;
                        poll_fds[num_fds].events = POLL_IN;
                        num_fds++;
                    }
                }
                else
                {
                    // 기존 클라이언트 소켓이 데이터 보낸 경우
                    int client_sock = poll_fds[i].fd;
                    int valread = read(client_sock, buffer, sizeof(buffer));
                    if (valread <= 0)
                    {
                        std::cerr << "client read error\n";
                        close(client_sock);
                        for (int j = i; j < num_fds; j++)
                        {
                            poll_fds[j] = poll_fds[j + 1];
                        }
                        num_fds--;
                        i--;
                    }
                    else
                    {
                        // 어떤 클라이언트 소켓으로부터 읽은 데이터를 다른 클라이언트 소켓에 다시 전송
                        for (int j = 0; j < num_fds; j++)
                        {
                            if (poll_fds[j].fd != sock_fd && j != i)
                            {
                                send(poll_fds[j].fd, "anonymous: ", sizeof("anonymous: "), 0);
                                send(poll_fds[j].fd, buffer, valread, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << "close server~!\n";
    close(sock_fd);
    for (int i = 0; i<client_sockets.size();i++)
    {
        close(client_sockets.at(i));
    }

    return 0;
}
