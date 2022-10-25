#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void *thread_job(void *arg){
	pthread_t tid;
	int err = pthread_detach(pthread_self());
	if(err > 0){
		printf("pthread_detach call failed:%s\n",strerror(err));
	}else
		printf("普通线程设置为分离态，参数:%ld\n",(long int)arg);
	sleep(3);
	pthread_exit((void*)8);
}


int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,thread_job,(void*)100);
	int err;
	void *reval = NULL;
	//sleep(0);
	err = pthread_join(tid,&reval);
	printf("main err:%s\n",strerror(err));
	if(err > 0){
		printf("pthread_join call failed:%s\n",strerror(err));
		exit(-1);
	}else
		printf("回收成功，退出码:%ld\n",(long int)reval);

	return 0;
}
