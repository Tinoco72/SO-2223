#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[], char *envp[]){

    int num, tempo, i;

    //verificar n. args
    if(argc! = 4){
        printf("\n[ERRO] Nr. de arguntos!\n");
        return 1;
    }

    //converter para inteiro (num, tempo)
    num = atoi(argv[1]);
    tempo = atoi(argv[3]);

    //motra inicio ...
    printf("INICIO...\n");

    //ciclo
    for(i=0; i<num; i++){
        //mostra texto (argv[2])
        printf("%s", argv[2]);
        //forçar saida stdout
        fflush(stdout);
        // pausa de um segundo
        sleep(tempo);
    }

    //mostra fim!
    printf("\nFIM!\n");
    return 0;
}
