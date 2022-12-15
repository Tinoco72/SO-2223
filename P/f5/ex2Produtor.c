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

#define FIFO "MEUFIFO1"

int main(int argc, char const *argv[]) {
  char msg[20];
  int fd_echo_fifo = open(FIFO, O_WRONLY);
  if(fd_echo_fifo == -1){
    printf("Erro ao abrir o servidor\n");
    return -1;
  }

  printf("O que deseja enviar?\n");
  fgets(msg, sizeof(msg), stdin);
  int size = write(fd_echo_fifo, &msg, strlen(msg));

  if(size <= 0)
    printf("Erro no envio\n");
  close(fd_echo_fifo);
  return 0;
}
