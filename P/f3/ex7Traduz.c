#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	setbuf(stdout,NULL);
	char opcao, palavra[100];
	int id;


	printf("Letra: ");
	scanf("%c",&opcao);
	printf("-->%s %c",palavra,opcao);

		if(opcao=='i' || opcao=='f'){
			id=fork();
			printf("\nPalavra: ");
			scanf("%s",palavra);

			if(id<0) printf("Erro");
			if(id==0){//filho
				printf("-->%s %c",palavra,opcao);
				if(opcao=='i')
					execl("./ding","./ding",palavra,NULL);
				if(opcao=='f')
					execl("./dfran","./dfran",palavra,NULL);
			}else if(id>0)//pai
				wait(&id);
			else
				printf("\nErro ao criar fork");
		}


	return 0;
}
