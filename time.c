#include "user.h"
#include "stat.h"
#include "types.h"

int main(int argc, char *argv[])
{
	int f = fork();
	if(f==0)
	{
		exec(argv[1],argv+1);
	}
	else
	{
		int wtime;
		int rtime;
		waitx(&wtime,&rtime);
		printf(1,"Waiting time of process is %d and running time of process is %d\n",wtime,rtime);
	}
	exit();
}