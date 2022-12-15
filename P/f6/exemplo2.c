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

typedef struct{
  int contador;
  pthread_mutex_t *m;
}TDADOS

void imprime(void *dados){
  TDADOS *pdados = (TDADOS*) dados;
  for(int k=0; k< 2000000000000;k++){
    pthread_mutex_lock(pdados -> m);
      pdados -> contador++;
    pthread_mutex_unlock(pdados -> m);
      fflush(stdout);
  }
  pthread_exit(NULL);
}

int main(){
  int i;
  pthread_t t[20];
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);
  TDADOS dados;
  dados.m=&mutex;
  dados.contador=0;

  for(i =0; i<2; i++){
    if(pthread_join(t[i],NULL)!=0)
    retrun -1;
    pthread_mutex_destroy(&mutex);
    printf("\n[%d]", dados.contador);
  }
}





















}
