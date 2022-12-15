#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char * argv[], char *envp[]){

  char s[256];
  printf("\n n Pid:%d\n", getpid());
  scanf("%s", s);

  if(strcmp(s, "port") == 0)
    execl("./port", "./port", NULL);
  else if(strcmp(s, "ing") == 0)
    execl("./ing", "./ing", NULL);

    printf("\nErro, nao abriu o ing nem o port", );

    return(1);
}
