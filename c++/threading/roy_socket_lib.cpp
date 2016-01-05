#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * handleecho( void * param )
{
    char buffer[1024];
    int count;
    pthread_detach( pthread_self() );
    int s = (int)param;
    while ( count = read( s, buffer, 1023 ) > 0 )
    {
        buffer[count] = 0;
        printf( "Received %s \n", buffer );
        write( s, buffer, count );
    }
    close( s );
}

int main()
{
    int newsocket;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 7779;
    bind(s, (struct sockaddr*)&server, sizeof(server));
    listen(s, 5);
    while(newsocket=accept(s,0,0))
    {
        pthread_t thread;
        pthread_create (&thread, 0, handleecho, (void*)newsocket);
    }
}