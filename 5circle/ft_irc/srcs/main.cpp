#include "Server.hpp"
int main(int argc, char **argv)
{
	try
	{
		Server server(argc, argv);

		std::cout << server.getPortNum() << ", " << server.getPassword() << std::endl;

		while (1)
		{
			int resultFd = poll(server.pollfds.data(), server.pollfds.size(), 36000); // pollfd 구조체 포인터, fds 배열의 크기, timeout

			if (resultFd == -1)
				throw std::runtime_error("Error: poll error");

			if (resultFd > 0)
			{
				if (server.pollfds[0].revents & POLLIN) // 서버 fd로 읽을 수 있는 이벤트 발생
				{
					std::cout << "클라이언트가 서버에 접근\n";

					server.acceptClient();
					continue;
				}

				for (size_t i = 1; i < server.pollfds.size(); i++) // 클라이언트 fd 확인
				{
					if (server.pollfds[i].revents == 0) // 이벤트 없을 때
						continue;

					if (server.pollfds[i].revents & POLLHUP || server.pollfds[i].revents & POLLERR) // 클라이언트 연결 종료
					{
						ft_quit(server, i);

						std::cout << "클라이언트가 연결을 끊음\n";
					}
					else if (server.pollfds[i].revents & POLLIN) // 클라이언트 신호 발생
					{
						int fd = server.pollfds[i].fd;
						char buffer[512];

						memset(buffer, 0, sizeof(buffer));
						ssize_t recvByte = recv(fd, buffer, sizeof(buffer), 0);

						if (recvByte < 0)
							throw std::runtime_error("Error: Fail read");
						else
						{
							std::strcat(server.clientBuffer[fd], buffer);
							std::string recvStr(server.clientBuffer[fd]);

							if (recvStr.find("\r\n") == std::string::npos) // crlf 아닐 때 문자열 저장 후 continue
								continue ;

							std::vector<std::string> commands = splitByCRLF(recvStr);
							std::string strBuffer(server.clientBuffer[fd]);
							std::size_t lastCRLFPos = strBuffer.rfind("\r\n");

							if (lastCRLFPos != std::string::npos)
								strBuffer.erase(0, lastCRLFPos + 2);

							for (size_t i = 0; i < commands.size(); i++)
							{
								std::cout << "보낸 사람 fd : " << fd << std::endl;
								std::cout << "들어온 메세지 : " << commands[i] << std::endl;

								try {
									UserInfo &user = server.getUserInfoByFd(fd);
									Command *cmd = server.createCommand(user, commands[i]);

									server.executeCommand(cmd, user);
								}
								catch (const std::exception &e)
								{
									std::cerr << e.what() << std::endl;
									continue;
								}
							}
							std::strcpy(server.clientBuffer[fd], strBuffer.c_str());
						}
					}
				}
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::vector<std::string> splitByCRLF(std::string &input)
{
	std::vector<std::string> result;
	size_t start = 0;
	size_t found = input.find("\r\n");

	while (found != std::string::npos)
	{
		result.push_back(input.substr(start, found - start));
		start = found + 2; 
		found = input.find("\r\n", start);
	}

	return result;
}

void ft_send(int fd, std::string str)
{
    str += "\r\n";
	const char *reply = str.c_str();

	std::cout << str;

	int result = send(fd, const_cast<char *>(reply), strlen(reply), 0); // socket, 보낼 문자열, 문자열 길이, flags

	if (result == -1)
		throw std::runtime_error("Error: send error");
}

void ft_quit(Server &server, size_t i)
{
	UserInfo &user = server.getUserInfoByFd(server.pollfds[i].fd);
	std::map<std::string, bool>::iterator chan = user.channels.begin();

	for (; chan != user.channels.end(); chan++)
	{
		std::string chanName = chan->first;
		std::map<std::string, Channel>::iterator chanIt = server.channels.find(chanName);

		// 채널에서 유저 삭제
		Channel &channel = chanIt->second;
		channel.users.erase(user.getNickname());
		channel.operators.erase(user.getNickname());
		channel.invite.erase(user.getNickname());

		// 채널에 속한 유저들에게 퇴장 메세지 전송
		std::map<std::string, UserInfo>::iterator userIt = channel.users.begin();
		for (; userIt != channel.users.end(); userIt++)
		{
			UserInfo &thisUser = userIt->second;

			if (thisUser.getFd() == user.getFd())
				continue;

			std::string chanMsg = ":" + user.getNickname() + "!" + user.getUsername() + "@" + user.getServername() + " QUIT :Quit: leaving";
			ft_send(thisUser.getFd(), chanMsg);
		}
	}

	// 유저 삭제
	server.users.erase(user.getFd());
	close(user.getFd());
	server.pollfds.erase(server.pollfds.begin() + i);
}