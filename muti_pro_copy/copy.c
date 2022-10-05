#include"./include/pro_copy.h"

int main(int argc,char **argv){
	//argv1:sfile argv2:dfile argv3:blocksize argv4:pos
	int blocksize = atoi(argv[3]);
	int pos = atoi(argv[4]);
	char buf[blocksize];
	bzero(buf,sizeof(buf));
	int sfd = open(argv[1],O_RDONLY);
	int dfd = open(argv[2],O_WRONLY|O_CREAT,0664);
	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);
	printf("Copy pro pid [%d] pos [%d] block [%d]\n",getpid(),pos,blocksize);

	int rsize = read(sfd,buf,sizeof(buf));
	write(dfd,buf,rsize);
	printf("拷贝成功..\n");

	return 0;
}
