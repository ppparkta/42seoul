#include "Server.hpp"

Server::Server(int argc, char **argv) : serverName("poke")
{
	if (argc != 3)
		throw std::invalid_argument("Error: invalid argument");

	portNum = convertPort(argv[1]);
	std::string password(argv[2]);
	this->password = password;

	openServer();
	pushServerPollfd();
}

int Server::convertPort(char *portStr) // port 번호 파싱
{
	for (size_t i = 0; i < strlen(portStr); i++)
		if (!isdigit(portStr[i]))
			throw std::invalid_argument("Error: invalid argument");

	int port = atoi(portStr);

	if (port < 0 || 65535 < port)
		throw std::invalid_argument("Error: invalid argument");

	return port;
}

void Server::openServer()
{
	createSocket();

	try
	{
		// 소켓 포트 연결
		struct sockaddr_in serverAddr;
		setServerAddr(serverAddr, getPortNum()); // socketaddr_in 구조체 초기화

		if (bind(getSocketFd(), reinterpret_cast<const struct sockaddr *>(&serverAddr), sizeof(serverAddr)) == -1) // 소켓에 IP주소와 포트번호 지정
			throw std::runtime_error("Error: bind error");

		if (listen(getSocketFd(), SOMAXCONN) == -1) // 클라이언트의 접속 요청을 기다림 (합리적인 최대 값으로 설정)
			throw std::runtime_error("Error: listen error");
	}
	catch (const std::exception &e)
	{
		close(getSocketFd());

		throw std::runtime_error(e.what());
	}
}

void Server::createSocket()
{
	int socketFd = socket(AF_INET, SOCK_STREAM, 0); // ipv4 통신, TCP 통신, type에서 미리 정해짐

	if (socketFd == -1)
		throw std::runtime_error("socket error");

	setSocketFd(socketFd);
}

// socketaddr_in 구조체 초기화
void Server::setServerAddr(struct sockaddr_in &serverAddr, int portNum)
{
	std::memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;				// ipv4
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // IP 주소 설정 long intger -> byte order
	serverAddr.sin_port = htons(portNum);			// port 번호 설정
}

void Server::pushServerPollfd()
{
	pollfd pollfd;

	pollfd.fd = getSocketFd();
	pollfd.events = POLLIN;
	pollfds.push_back(pollfd);
}

/* getter */
std::string Server::getPassword() const
{
	return password;
}

int Server::getPortNum() const
{
	return portNum;
}

int Server::getSocketFd() const
{
	return socketFd;
}
std::string Server::getServerName() const
{
	return serverName;
}

/* setter */
void Server::setPassword(std::string password)
{
	this->password = password;
}

void Server::setPortNum(int portNum)
{
	this->portNum = portNum;
}

void Server::setSocketFd(int fd)
{
	this->socketFd = fd;
}

void Server::acceptClient()
{
	sockaddr_in client;
	socklen_t clientLen = sizeof(client);

	int clientFd = accept(getSocketFd(), reinterpret_cast<sockaddr *>(&client), &clientLen); // 소켓 연결 허용

	users.insert(std::make_pair(clientFd, UserInfo()));
	users[clientFd].setFd(clientFd);


	// 클라이언트 pollfd 저장
	pollfd newPollfd;
	newPollfd.fd = clientFd;
	newPollfd.events = POLLIN;
	pollfds.push_back(newPollfd);

	std::cout << "new client fd: " << clientFd << std::endl;
}

Command *Server::createCommand(UserInfo &user, std::string recvStr)
{
	Message msg(user.getFd(), recvStr);

	Command *cmd = 0;

	if (msg.getCommand() == "PASS")
		cmd = new Pass(&msg, user, password);
	else if (msg.getCommand() == "NICK")
		cmd = new Nick(&msg, user, users);
	else if (msg.getCommand() == "USER")
		cmd = new User(&msg, user);
	else if (msg.getCommand() == "JOIN")
		cmd = new Join(&msg, user, &this->channels);
	else if (msg.getCommand() == "INVITE")
		cmd = new Invite(&msg, user, &this->channels, &this->users);
	else if (msg.getCommand() == "TOPIC")
		cmd = new Topic(&msg, user, this->channels);
	else if (msg.getCommand() == "QUIT")
		cmd = new Quit(&msg, user, &this->channels, &this->users, &this->pollfds);
	else if (msg.getCommand() == "PRIVMSG")
		cmd = new Privmsg(&msg, user, this->users, this->channels);
	else if (msg.getCommand() == "MODE")
		cmd = new Mode(&msg, user, channels, users);
	else if (msg.getCommand() == "PING")
		cmd = new Ping(&msg, user);
	else if (msg.getCommand() == "KICK")
		cmd = new Kick(&msg, user, &this->users, &this->channels);
	else if (msg.getCommand() == "PART")
		cmd = new Part(&msg, user, &this->users, &this->channels);
	else if (msg.getCommand() == "DINNER")
		cmd = new Bot(&msg, user);
	return cmd;
}

void Server::executeCommand(Command *cmd, UserInfo &user)
{
	if (cmd)
	{
		cmd->execute();

		if (!user.getActive() && (cmd->getCommand() == "NICK" || cmd->getCommand() == "USER"))
			Auth auth(user, users, this->getServerName());

		delete (cmd);
	}
}

UserInfo &Server::getUserInfoByFd(int clientFd)
{
	std::map<int, UserInfo>::iterator it = users.find(clientFd);

	if (it != users.end())
		return it->second;
	else
		throw std::runtime_error("Error: Not find any user");

	return it->second;
}
