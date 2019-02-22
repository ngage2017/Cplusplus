#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define SERV_PORT 6666

int main()
{
	int sfd,cfd;
	int len;
	char buf[1024];
	struct sockaddr_in serv_addr,client_addr;
	socklen_t client_len;

	sfd = socket(AF_INET,SOCK_STREAM,0);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(SERV_PORT);
	
    
	bind(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));


	listen(sfd,128);
	client_len = sizeof(client_addr);

	cfd = accept(sfd,(struct sockaddr*)&client_addr,&client_len);
	len = read(cfd,buf,sizeof(buf));

    printf("%s",buf);
	return 0;
}
