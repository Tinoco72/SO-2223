#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char * argv[], char *envp[]){

  printf("\nPID[%d] Hello Word\n", getpid());

}
