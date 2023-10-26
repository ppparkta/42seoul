# 베이스 이미지로부터 시작합니다.
FROM gcc:latest

# telnet 설치
RUN apt-get update && apt-get install -y telnet

# 작업 디렉토리를 설정합니다.
WORKDIR /usr/src/app

# 소스 코드를 복사합니다.
COPY . .

# 소스 코드를 컴파일합니다.
RUN g++ -o main test.cpp
