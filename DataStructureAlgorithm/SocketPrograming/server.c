#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void error(const char *msg){
    print("%s",msg);
}

int main(int argc, char *argv){
    if(argc<2){
        error("\n[PORT NUMBER NOT PROVIDED]....\n[TERMINATING]\n");
        exit(0);
    }
    int sockfd, newsockfd, portno, n;
    char buffer[255];
    struct sockaddr_in serv_addr , cli_addr;
    socklen_t clilen;
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    if(sockfd < 0){
        error("\n[ERROR IS FORMATION OF SOCKET]....\n[TERMINATING]....\n");
        exit(0);
    }
    bzero((char *)&serv_addr , sizeof(serv_addr));
    portno = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = portno;

    if(bind(sockfd, (struct sockaddr *)&serv_addr , sizeof(serv_addr)) < 0){
        error("\n[ERROR IN BINDING].....\n[TERMINATING]......\n");
        exit(0);
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if(newsockfd < 0){
        error("\n[ERROR IN ACCEPTING].....\n[TERMINATING]......\n");
        exit(0);
    }

    while(1){
        bzero(buffer, 255);
        n = read(newsockfd,buffer,255);
        if(n < 0){
            error("\n[ERROR IN READING].....\n[TERMINATING]......\n");
            exit(0);
        }
        print("CLIENT: %s\n",buffer);
        bzero(buffer,255);
        fget(buffer,255,stdin);
        n = write(newsockfd,buffer,strlen(buffer));
        if(n < 0){
            error("\n[ERROR IN WRITING].....\n[TERMINATING]......\n");
            exit(0);
        }
        int i = strncmp("bye",buffer,3);
        if(i==0){
            break;  
        }
    }
    close(newsockfd);
    close(sockaddr);
    return 0;

}