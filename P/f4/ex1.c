#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int conta=0;

void funcSignal(int sign){
    printf("\nrecebi o sinal %d\n", sign);
    if(conta < 5){
        printf("\nai\n");
        conta++;
    }
    else if(conta==5){
        printf("\nok,pronto\n");
        exit(1);
    }
}

void funcSinal(int signum, siginfo_t *info, void *secret/* arguments */) {
  /* code */
    printf("\nai\n");
    if(++conta==5){
      printf("\nok,pronto\n");
      exit(1);
    }
}

int main(){
    char nome [10];
    struct sigaction sa;
    sa.sa_handler = funcSignal;
    sigaction(SIGINT,&sa,NULL);

    do{
    printf("\nNome: ");
    scanf("%s", nome);
    puts(nome);

  }while(strcmp(nome,"sair")!=0);

    return 0;
}

int main1(){
    char nome [10];
    printf("PID:%d\n", getpid());
    struct sigaction sa;
      sigaction = funcSinal;
      sa.sa_flags = SA_SIGINFO;
    sigaction(SIGINT,&sa,NULL);

    do{
    printf("\nNome: ");
      if(scanf("%s\n",nome ) != 1)
        printf("Nao introduziu nome\n", );
      else
        if(strcmp(nome, "sair")!= 0)
            printf("OLA [%s]\n", nome);

  }while(strcmp(nome,"sair")!=0);

    return 0;
}
