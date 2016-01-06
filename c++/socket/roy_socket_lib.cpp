/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "config.h"
using namespace std;

int roy_socket()
{
    int host_port = MY_PORT;
    string host_ip = MY_HOST;
    int s_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    // create a socket

    /*
      Choose socket communications family/domain:
        Internet IPV4: AF_INET
        Internet IPV6: AF_INET6
        Unix path name (communicating processes are on the same system): AF_UNIX
      Choose socket type:
        TCP: SOCK_STREAM
        UDP: SOCK_DGRAM
        Raw protocol at network layer: SOCK_RAW
      Choose socket protocol: (See /etc/protocols)
        Internet Protocol (IP): 0 or IPPROTO_IP
        ICMP: 1
     */

    if(s_fd < 0)
    {
        perror("Cannot create socket");
        close(s_fd);
        exit(EXIT_FAILURE);
    }
    else{
        std::cout << "Socket created" << endl;
    }
    // If failed to create a socket, close the socket and exit with a error code

    struct sockaddr_in host;
    bzero(&host, sizeof(sockaddr_in));
    // Clear structure memory

    host.sin_family = AF_INET;
    host.sin_port = htons(host_port);
    host.sin_addr.s_addr = htonl(INADDR_ANY);

    int bind_res = bind(s_fd, (struct sockaddr *)&host, sizeof(host));
    if ( bind_res == -1){
        perror("Bind failed");
        close(s_fd);
        exit(EXIT_FAILURE);
    }


    int listen_res = listen(s_fd, 5);
    if (listen_res == -1){
        perror("Listen failed");
        close(s_fd);
        exit(EXIT_FAILURE);
    }

    while(1) {
        int con = accept(s_fd, NULL, NULL);

        if (con < 0) {
            perror("Accept failed");
            close(s_fd);
            exit(EXIT_FAILURE);
        }


        else
        {
            std::cout << "Connection Established" << endl;
        }
        close(con);
        std::cout << "Connection Closed" << endl;
        close(s_fd);
    }


}

