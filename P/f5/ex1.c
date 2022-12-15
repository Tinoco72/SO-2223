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


int main(int argc, char const *argv[]) {
  if(mkfifo(FIFO, 0666) == -1){
    if(errno == EEXIST)
      printf("o programa ja esta a correr\n");
    printf("Erro ao abrir o fifo\n");
    return 1;
  }


  int fd = open(FIFO, O_RDONLY);//O_WRONLY| O_RDWR | O_NONBLOCK
  if(fd < 0){
    printf("Erro abrir ao fifo\n");
    return 0;
    }
  char msg[100];
  int size = read(fd, &msg,sizeof(msg));
  if(size > 0){
    msg[size - 1] = '\0';
    printf("MSG:[%s] co o tamanho [%d]\n", msg, size);
  }
  close(fd);
  unlink(FIFO);//aopagar o fifo do sistem

  //return 0;
}
