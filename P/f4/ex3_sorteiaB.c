#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

int num1;// nao sei onde usa
int numAdivinha=0;

void sair(int s){
	printf("Adeus -Prontos %d", numAdivinha);
	exit(1);
}

void sorteia(){
	srand(time(NULL));
	num1=rand()%100;
  //printf("Numero [%d] \n",num1);
}

void jogo(int s, siginfo_t *i, void *v){

  int n=i->si_value.sival_int;
	if(n > num1)
		printf("Resposta de %d - Demasiado grande\n",i->si_pid);
	else if(n < num1)
		printf("Resposta de %d - Demasiado pequeno\n",i->si_pid);
	else if(n == num1){
		numadivinha ++
		printf("Resposta de %d - Acertou\n",i->si_pid);
    sorteia();
    }

		union sigval val;
		val.sival_int = ;

}

int main(){

	setbuf(stdout, NULL);
	struct sigaction sa;
		sa.sa_sigaction=jogo;//abre funcao jogo
		sa.sa_flags=SA_RESTART|SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);

	struct sigaction sac;
		sac.sa_handler = sair;//
	sigaction(SIGINT,&sac, NULL);//recebe como parâmetro o sinal
	printf("O meu PID %d", getpid());
  sorteia();
	do{
	}while(1);

}
