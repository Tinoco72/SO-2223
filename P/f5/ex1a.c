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

int int main(int argc, char const *argv[]) {

  int fd = open(FIFO, O_WRONLY);
  int size = write(fd, "ola",4);
  close(fd);

  return 0;
}
