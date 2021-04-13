#include "user.h"
#include "stat.h"
#include "types.h"

int main(int argc , char *argv[])
{
	int newp  = atoi(argv[1]);
	int pid = atoi(argv[2]);
	set_priority(newp,pid);
	exit();
}