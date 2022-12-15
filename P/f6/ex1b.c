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
  char tipo;//tipo a ou b
  int stop;
  pthread_mutex_t *m;
}TDADOS

void imprime(char letra, int numero){
  for(int i= 0; i < numero; i++){
    printf("%c", letra);
    fflush(stdout);
    sleep(1);
  }
}

void *tarefa(void *dados){
  TDADOS *pdados = (TDADOS *) dados;
  while (pdados -> stop == 1) {
    srand(time(0));
    int t = rand() % (1-6);
    imprime('.', t);//imprimir os pontos
    pthread_mutex_lock(pdados -> m);
    imprime(pdados -> tipo,3);//imprime letras
    pthread_mutex_unlock(pdados -> m);
  }
  pthread_exit(NULL);
}




int main(){
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);


  char buffer[100];
  pthread_t t[2];
  TDADOS valores[2;]
  valores[0].stop = 1;
  valores[0].tipo = 'A';
  valores[0].m = &mutex;
  valores[1].stop = 1;
  valores[1].tipo = 'B';
  valores[1].m = &mutex;

  if(pthread_creat(&t[0],NULL, &tarefa,&valores[0]) != 0)
    retrun -1;
  if(pthread_creat(&t[1],NULL, &tarefa,&valores[1]) != 0)
    retrun -1;

  while (strcmp(buffer, "sair")!= 0)
    scanf("%s",buffer);

  valores[0].stop = 0;
  valores[1].stop = 0;

  pthread_join(t[0], NULL);
  pthread_join(t[1], NULL);
  pthread_mutex_destroy(&mutex);

  retrun 0;
  }























}
