#include "types.h"
#include "stat.h"
#include "user.h"

int number_of_processes = 10;
int tw=0;
int main(int argc, char *argv[])
{
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
     
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        {
          sleep(200); //io time
        }
        else
        {
		    volatile float a=0;
		    volatile float b=1.43;
		    volatile float c=1.35;
		    for(volatile int i=0;i<100000000;i++)
		    {
		        a = (a + b * c);
		    }
        }
      }
      exit();
    }
    else{
       set_priority(100-(20+j),pid); 
    	// will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  for (j = 0; j < number_of_processes+5; j++)
  {
  	int wtime=-1;
	int rtime=-1;
	ps();
	waitx(&wtime,&rtime);
	printf(1,"Waiting time of process is %d and running time of process is %d\n",wtime,rtime);
	if(wtime>0)
		tw+=wtime;
  }
  printf(1,"Total waiting time of 10 process parallel processes is %d\n",tw);
  exit();
}

/*
int main(int argc, char *argv[])
{
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
     
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        {
          sleep(200); //io time
        }
        else
        {
          if(j==0 || j==1 || j==2)
          {
            volatile float a=0;
            volatile float b=1.43;
            volatile float c=1.35;
            for(volatile int i=0;i<100000000;i++)
            {
              a = (a + b * c);
            }
          }
          else
          {       
				    volatile int a=1;
				    a++;a++;a++;
          }
        }
      }
      exit();
    }
    else{
       set_priority(100-10*j,pid); 
    	// will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  for (j = 0; j < number_of_processes+5; j++)
  {
  	int wtime=-1;
	int rtime=-1;
	ps();
	waitx(&wtime,&rtime);
	printf(1,"Waiting time of process is %d and running time of process is %d\n",wtime,rtime);
	if(wtime>0)
		tw+=wtime;
  }
  printf(1,"Total waiting time of 10 process parallel processes is %d\n",tw);
  exit();
}
*/