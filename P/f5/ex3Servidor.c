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
//msg que recebe
//sprintf("CLIENTE_FIFO_FINAL, CLIENT_FIFO,msgRecebida.pd");

typedef struct{
  pid_t pid;
  char operador;
  int num1;
  int num2;
}dataMSG;

typedef struct {
  float res;
}dataRPL;

void handler_sigalarm(int s, siginfo_t *i, void *v){
  unlink(SERVER_FIFO);
  printf("Adeus\n");
  exit(1);
}

int main(int argc, char const *argv[]) {

  //correr em bg d)
/*  int p = fork();
  if(p > 0)
    exit(1);
  */
    struct sigaction   sa;
      sa.sa_sigaction = handler_sigalarm;
    sigaction(SIGINT, &sa, NULL);
    dataMSG msgRecebida;
    dataRPL resposta;

    if(mkfifo(SERV_FIFO, 0666) == -1){
      if(errno == EEXIST)
        printf("o programa ja esta a correr\n");
    printf("Erro ao abrir o fifo\n");
    return 1;
    }

  int fdRecebe = open(SERVER_FIFO, O_RDONLY);
  //int fdRecebe = open(SERVER_FIFO, O_RDWR);
  if(fd_echo_fifo == -1){
    printf("Erro ao abrir o servidor\n");
    return -1;
  }

  do{
    int size = read(fdRecebe, %msgRecebida, sizeof(msgRecebida));
    if(size > 0){
      if(msgRecebida.operador == '+');
      resposta.res=msgRecebida.num1 + msgRecebida.num2;
      else if(msgRecebida.operador == '.')
        kill(getpid(), SIGINT);
      //responder ao meu CLIENTE...
      sprintf(CLIENTE_FIFO_FINAL, CLIENT_FIFO, ,msgRecebida.pid);
      int fdEnvio = open(CLIENTE_FIFO_FINAL, O_WRONLY);
      int size2 =  write(fdEnvio, &resposta, sizeof(resposta));

      close(fdEnvio);
    }
    while (1);
  }



  return 0;
}
