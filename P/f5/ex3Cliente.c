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

#define SERVER_FIFO "SERVIDOR"
#define CLIENT_FIFO "CLIENTE%d" //CLIENTE123
char CLIENTE_FIFO_FINAL[100];//CLIENTE123

typedef struct{
  pid_t pid;
  char operador;
  int num1;
  int num2;
}dataMSG;

typedef struct {
  float res;
}dataRPL;


int main(int argc, char const *argv[]) {

  dataMSG msg;
  dataRPL resposta;

  msg.pid = getpid();
  int fd_envio, fd_resposta;
  sprintf(CLIENTE_FIFO_FINAL, CLIENT_FIFO, getpid());
  if(mkfifo(CLIENTE_FIFO_FINAL, 0666)){
    if(errno == EEXIST)
      printf("o programa ja esta a correr\n");
  printf("Erro ao abrir o fifo\n");
  return 1;
  }

  do{
    prinft("Introduza o operador\n");
    scanf(" %c", &msgRec);
    if(msg){

    }
  }



}
