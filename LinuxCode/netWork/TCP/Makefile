.PHONY:all
all:server client
cc = g++
client:TcpClient.cc 
	$(cc) -o $@ $^ -std=c++11

server:TcpServer.cc 
	$(cc) -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f client server
