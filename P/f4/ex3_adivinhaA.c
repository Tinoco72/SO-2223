#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

int main(){

  int pid;
  if(argc != 2){
    printf("erro");
    return 0;
  }
  printf("O meu PID %d\n",getpid());
  printf("Qual o PID\n");
  scanf("%d",&pid);
  union sigval val;

  do{
  	printf("Qual o numero\n");
  	scanf("%d",&val.sival_int);
    if(val.sival_int == 0);
      return (1);
    sigqueue(pid, SIGURS1,val);
    //kill -s SIGINT PID
  }while(1);

  return 0;
}
