#include"./include/pro_copy.h"

int check_arg(const char* SFile,int arg_num,int pronum){
	if(access(SFile,F_OK)!=0){
		perror("check_arg error:文件不存在");
		exit(-1);
	}
	if(arg_num < 3){
		printf("check_arg error:参数数量过少\n");
		exit(-1);
	}
	if(pronum < 1 || pronum > 100){
		printf("check_arg error: 进程数量出错\n");
		exit(-1);
	}
	return 0;
}
