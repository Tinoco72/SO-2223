#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
void funcSignal(int sign){
    printf("\nrecebi o sinal %d\n", sign);
    exit(1);
}*/

void funcSignal(int sign, siginfo_t *info, void *old){
    printf("\n recebi o sinal [%d]", sign);
    printf("\n o autor do envio foi o [%d] pid", info->si_pid);
    printf("\n o valor recebido foi [%d]\n", info->si_value.sival_int);
}

int main(){
    int i;
    printf("\no meu pid [%d]\n", getpid());
    struct sigaction sa;
        //sa.sa_handler = funcSignal; //para a primeira funcao
        sa.sa_sigaction = funcSignal; //para a segunda funcao
        sa.sa_flags = SA_SIGINFO;
        //sigaction(SIGINT,&sa,NULL); //para a primeira funcao
        sigaction(SIGUSR1,&sa,NULL); //para a segunda funcao
        scanf("%d",&i);
        return 0;
}