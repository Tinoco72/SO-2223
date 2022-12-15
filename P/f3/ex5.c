#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char * argv[], char *envp[]){
  int a = 10;
  if (fork() == 0)
    a++;
  else
    a--;
  printf("\na = %d\n", a);
  return 0;

  //printf("\nPID[%d] Ola mundo\n", getpid());

}
