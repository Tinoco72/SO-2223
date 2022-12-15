#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){

	setbuf(stdout,NULL);
	char* dicIng[]={"chien","eau","table","chat","anglais"};
	char* dicPort[]={"cao","agua","mesa","gato","ingles"};
	char palavra[20];
	printf("\nIntroduza uma palavra: ");
	scanf("%s",palavra);

	for(int i=0;i<5;i++){
	if(strcmp(palavra,dicPort[i])==0){
		printf("A palavra em frances e: %s\n",dicIng[i]);
		return 0;
	}}

	printf("A palvra em frances e: unknown\n");
	return 0;
}
