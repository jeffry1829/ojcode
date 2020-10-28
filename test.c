#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int k = 0;
   pid_t pid;

   do{
     cin>>k;
   }while(k<=0);

   pid = fork();
   //child process
   if (pid == 0){
		printf("Child is working\n");
		printf("%d ",k);

		while (k!=1){
			if(k&1)k=3*k+1;
      else k/=2;
			printf("%d ",k);
			}
			printf("\nChild process is done\n");
		}
   //parent process
   else{
      printf("Parent is waiting for child\n");
      wait(NULL);
      printf("Parent process ends\n");
   }
   return 0;
}