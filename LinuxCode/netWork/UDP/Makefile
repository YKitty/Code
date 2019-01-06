.PHONY:all
all:server client
cc = g++
client:UdpClient.cc 
	$(cc) -o $@ $^ -std=c++11

server:UdpServer.cc 
	$(cc) -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f client server
