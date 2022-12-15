#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char * argv[], char *envp[]){

  printf("\nPID[%d] Ola mundo\n", getpid());

}
/*
int main(){
  printf("\n n Pid:%d\n", getpid());

  execl("/bin/ls", "/bin/ls", "-l", NULL);
  //execlp("ls","ls","ls", "-l", NULL);

  //execl("exemplo2", "exemplo2", "SO-1", "so-2",NULL);
  //execlp("./exemplo2"./exemplo2","ola1", "ola2", NULL);

  printf("chego aqui???");
  return 0;

}
*/
