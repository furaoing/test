/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "config.h"
#include <iostream>

void error(const char *msg)
{
    perror(msg);

}

int main()
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        std::cout << "Error opening socket" << std::endl;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = MY_PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    std::cout << "INADDR_ANY: " << INADDR_ANY << std::endl;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        std::cout << "Error on binding" << std::endl;
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    while(1) {
        newsockfd = accept(sockfd,
                           (struct sockaddr *) &cli_addr,
                           &clilen);
        if (newsockfd < 0)
            std::cout << "Error on accept" << std::endl;
        bzero(buffer, 256);
        while(1) {
            n = read(newsockfd, buffer, 255);
            if (n < 0) {
                std::cout << "Connection Closed" << std::endl;
                close(newsockfd);
                break;
            }
            else {
                printf("Here is the message: %s\n", buffer);
                n = write(newsockfd, "I got your message", 18);
                if (n < 0) std::cout << "Error writing" << std::endl;
            }
        }
    }
    close(sockfd);
}