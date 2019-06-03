#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <cstdio>


int main()
{
    struct hostent* host = gethostbyname("www.baidu.com");
    if (!host)
    {
        std::cout << "gethostbyname error!" << std::endl;
        exit(1);
    }

    for (int i = 0; host->h_aliases[i]; i++)
    {
        std::cout << "Alias " << i + 1 << host->h_aliases[i] << std::endl; 
    }

    //std::cout << "Address type: " << (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6" << std::endl;
    printf("Address type: %s\n", (host->h_addrtype==AF_INET) ? "AF_INET": "AF_INET6");

    for(int i=0; host->h_addr_list[i]; i++){
        printf("IP addr %d: %s\n", i+1, inet_ntoa( *(struct in_addr*)host->h_addr_list[i] ) );
    }
    return 0;
}
