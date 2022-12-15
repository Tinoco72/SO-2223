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

#define FIFO "meu primeiro programa"

void fim(int sign, siginfo_t *i, void *secret){
  unlink(FIFO);
  exit(1);
}

int main(int argc, char const *argv[]) {

  struct sigaction   sa;
    sa.sa_sigaction = fim;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &sa, NULL);

    char msg[100];

  if(mkfifo(FIFO, 0666) == -1){
    if(errno == EEXIST)
      printf("o programa ja esta a correr\n");
    printf("Erro ao abrir o fifo\n");
    return 1;
  }

  int fd_echo_fifo = open(FIFO, O_RDONLY);//O_WRONLY| O_RDWR | O_NONBLOCK
  if(fd_echo_fifo == -1){
    printf("Erro abrir ao fifo\n");
    return 1;
    }

while(1){
    int size = read(fd_echo_fifo, &msg,sizeof(msg));
    if(size > 0){
      if(strcmp("sair\n",msg) ==0){
        close(fd_echo_fifo);
        unlink(FIFO);
        return -1;
      }
      printf("%s", msg);
    }

}
  unlink(FIFO);//aopagar o fifo do sistem
  //return 0;
}
