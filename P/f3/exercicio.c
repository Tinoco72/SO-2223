#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  int i;
  char resposta[10];
  int fd[2];
  pipe(fd);
  i=fork();
  if(i<0)
    return -1;
  else if(i == 0){
    close(fd[0]);
    int size = write(fd[1], "ola", 4);
    printf("\n Enviei [%d]\n", size);
  }
  else{
    close(fd[1]);
    int size2 = read(fd[0], resposta, sizeof(resposta));
    printf("\n Eu recebi a palavra %s com tamanho [%d]\n", resposta, size2);
  wait(&i);
  }
}
