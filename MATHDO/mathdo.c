#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int pid = fork(); // child1
	if (pid==0){ // child 1
		execlp("./add.py",":)",argv[1],argv[2],NULL);

	} else // parent
	{
		int pid2 = fork();
		if (pid2==0){ // child 2
			execlp("./div.sh",":)",argv[1],argv[2],NULL);
		} else // parent
		{
			wait(0);
			wait(0);
			printf("parent: done\n");
		}		
	}
}
