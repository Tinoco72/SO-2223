#include<stdio.h>

int main(int argc, char *argv[]){

    int i=0;
    do{
        printf("\n%s\n", argv[i]);
        i++;
    }while(argv[i] != NULL);

    return 0;
}
