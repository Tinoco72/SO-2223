#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>


void recebe(int s, siginfo_t *i, void *v){
  int n = i -> si_value.sival_int;
	if(n == 1)
		printf("Resposta de %d - Demasiado grande\n",i->si_pid);
	else if(n == 2)
		printf("Resposta de %d - Demasiado pequeno\n",i->si_pid);
	else if(n == 3){
		numadivinha ++
		printf("Resposta de %d - Acertou\n",i->si_pid);
}


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
  struct sigaction =  sa;
    sa.sa_sigaction = recebe;
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
    sigaction(SIGUSR1, &a, NULL);
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
