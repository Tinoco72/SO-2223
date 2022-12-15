#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <.h>
int n =20;
int pontuacao = 0;
int perdeu = 0;

void jogo(){
  srand(time(NULL));
  int num1 = rand() % 100;
  int num2 = rand() % 100;

  int soma =  num1 + num2;
  int somaUser;

  printf("%d + %d =  \n", num1, num2);
  if(scanf("%d", somaUser) != 1)
    perroe("nao intruduzio nada - perdeu");

  if(soma == somaUser){
    pontuacao++;
    printf("acertou\n pontuacao = %d\n",pontuacao);
    n--;
  }
  else{
    puts("Perdeu");
    if(++perdeu == 2)
      exit(1);
    }
  else
    printf("\n Tem mais uma tentativa\n");

}

void handler_sigalarm(int s, siginfo_t *i, void *v){
  printf("Acabaou o tempo - perdeu\n");
  exit(1);
}



int int main(int argc, char const *argv[]) {
  int i = 0;
  struct sigaction sa;
    sa.sa_handler = handler_sigalarm;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGALARM,&sa,NULL);

  while (1) {
    if(i == 5)
      exit(1);
    else{
      alarm(n);
      jogo();
    }
    i++;
  }
  return 0;
}
