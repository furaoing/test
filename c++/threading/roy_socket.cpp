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

/*
int roy_memset(char char_arr, int value, int start, int size)
{
    for(int i=0;i)
}
 */

int main()
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFF_SIZE];
    int char_cnt = 0;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        std::cout << "Error opening socket" << std::endl;
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
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
        memset(buffer, 0, BUFF_SIZE);
        while(1) {
            n = recv(newsockfd, buffer, BUFF_SIZE, 0);
            std::cout << n << "##" << std::endl;

            char_cnt += n;
            if (n < 0) {
                std::cout << "Connection Closed" << std::endl;
                close(newsockfd);
                break;
            }
            else {
                printf("Here is the message:");
                std::cout << buffer << "##" << std::endl;


                for (int k=5;k<BUFF_SIZE;k++)
                {
                    if (buffer[k] != 0) {
                        std::cout << "Value Not Zero:" << buffer[k] << "##" << std::endl;
                        sleep(10);
                        break;
                    }
                }

                std::cout << "Current Char Count: " << char_cnt << std::endl;
                //n = send(newsockfd, buffer, BUFF_SIZE, 0);
                //if (n < 0) std::cout << "Error writing" << std::endl;
            }
        }
    }
    close(sockfd);
}