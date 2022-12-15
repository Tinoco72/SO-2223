#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
##include <pthread.h>

void acorda(int s, siginfo_t *info, void *c){}

typedef struct{
  int a;
  int b;
  int stop;
}TDADOS

void imprime(void *dados){
  TDADOS *pdados = (TDADOS*) dados;
  do{
    printf("Ola da thread [%d] [%d]\n",pdados->a, pdados->b);
    sleep(5);
    //read(fd, )....
  }while(pdados->, stop == 1);
  pthread_exit(NULL);
}

int main(){
  struct sigaction act;
  act.sa_sigaction = acorda;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &act, NULL);
  int i;
  pthread_t a;
  TDADOS val;
  val.a = 10;
  val.b = 10;
  val.stop = 1;

  if(pthread_creat (&a, NULL, &imprime, &val) !=0)
  retrun 0;
  scanf("%d", &i);
  val.stop = 1;
  pthread_join(a, NULL);
}





















}
