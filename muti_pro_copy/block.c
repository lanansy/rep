#include"./include/pro_copy.h"

int block(const char* SFile,int pronum){
	int fd = open(SFile,O_RDONLY);
	int Filesize = lseek(fd,0,SEEK_END);
	if(Filesize % pronum == 0)
		return Filesize / pronum;
	else
		return Filesize / pronum + 1;
}
