//1. Programação em C com as ferramentas gcc. Ficheiros objecto e executáveis.
//a) Construa um programa que imprime “ola mundo”.

  #include <stdio.h>
  int main(){
    printf("Ola Mundo!\n");
    return 0;
  }

//b) Compile-o com o gcc produzindo o executável. Experimente correr o programa assim feito.
  gcc ex1.c -o ex1
  ./ex1
/*c) Produza apenas o ficheiro objecto (opção -c). Verifique que não o consegue executar, mesmo que
lhe mude os atributos de ficheiro.*/
gcc ex1.c -c ex1
//d) Produza o ficheiro assembly (opção –S). Veja o conteúdo desse ficheiro com um editor de texto.
  gcc ex1.c -s ex1
//e) Partindo do ficheiro objecto, produza o executável.


//2. Debugger gdb.
/*a) Construa um programa que pede um número ao utilizador, de seguida apresenta esse valor
elevado ao quadrado e finalmente pede um conjunto de caracteres ao utilizador apenas para fazer
uma pausa antes de terminar.*/
  #include <stdio.h>
  #include <math.h>
  int main() {
    int num;
    char str[100];

    printf("Numero:");
    scanf("%d", &num);
    num = num * num;
  //num = pow(num, 2);
    printf("Palavra:");
    scanf("%s", str);

    printf("Numero:%d\n Palavra: %s\n",num, str);
    return 0;
  }
//b) Compile-o com o gcc produzindo o executável. Teste o programa com alguns valores.
  gcc -o ex2 ex2.c -lm
  /*-lm por  causa do pow*/
  ./ex2
//c) Utilize o debugger gdb para analisar a execução do +programa e o conteúdo das suas variáveis.
gcc -g ex2.c -o ex2

list        -> lista o programa
break n     -> breakpoint na linha n
run         -> corre o programa
display n   -> mostra o valor de n
continue    ->continua o programa


//3. Programação em C com gcc – projectos com vários ficheiros .h/.c e bibliotecas.
/*a) Construa um programa com uma função “imprime” que imprime “ola mundo”. O programa deve
estar organizado da seguinte forma:*/
  // programa.c – tem a função main e usa a função imprime.
  #include <stdio.h>
  #include "ex3imprime.h"
  int main(){
    char str[10] =  "Ola Mundo!";
    imprime(str);
    imprime("Ola Mundo!");
    return 0;
  }
  // imprime.h – tem o protótipo da função imprime.
  #include <stdio.h>
  void imprime(char *str);
  // imprime.c – tema implementação da função imprime.
  #include "ex3imprime.h"
  void imprime (char* frase){
      printf("\n%s\n", frase);
  }
//b) Compile o programa um ficheiro c de cada vez, gerando o respectivo ficheiro objecto
gcc ex3programa.c -c
gcc ex3imprime.c -c

//c) Obtenha o ficheiro executável partindo dos ficheiros objecto que obteve.
gcc ex3programa.o ex3imprime.o  ex3

//4. Utilitário make.
/*O utilitário make permite automatizar e gerir as tarefas relacionadas com a construção de programas. É
bastante útil quando o projecto envolve vários ficheiros e bibliotecas. Este exercício ilustra muito
brevemente as suas potencialidades.*/
/*a) Usando os ficheiros do exercício 3 construa um ficheiro make para as seguintes opções:
   Construção do programa completo.
   Construção do módulo (ficheiro objecto) programa.
   Construção do módulo imprime.
   Eliminação de ficheiros objecto e executáveis relacionados com o projecto.
*/

all:
	gcc -o ex3programa ex3programa.c ex3imprime.c

ex3programa:
	gcc -c ex3programa.c

ex3imprime:
	gcc -c ex3imprime.c

clean:
	$(RM) programa programa.o imprime.o

  /*nano makefile
    make
    make clean
    make -b
    make -c
  */

/*6. Argumentos de linha de comandos.
Elabore um programa que apresente no ecrã o nome que o programa tem (o nome do ficheiro
executável), ou mais concretamente, o nome que foi usado na linha de comandos para o executar. Se
tiver um IDE, elabore o programa com o editor do IDE. Caso contrário use o editor pico. Em qualquer
dos casos, a execução deverá ser feita a partir da linha de comandos.
a) Faça e execute o programa. Responda à questão “Como sabe o seu programa o nome que tem o
seu ficheiro executável?”
b) Se tiver um IDE, repita o processo, mas lance a execução a partir do IDE. O programa continua a
saber o nome do seu ficheiro executável? Como? Qual a linha de comandos que foi usada?
Averigúe onde pode configurar a linha de comandos no seu IDE para lançar o seu programa.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {

  int i;
  printf("O nome do meu programa e: %s\n", argv[0]);
  return 0;
}


/*7. Argumentos de linha de comandos.
Elabore um programa que escreve no ecrã todas as palavras que foram escritas na linha de comandos à
frente do nome do programa, quando se lança a sua execução. As palavras são escritas uma em cada
linha.
a) Elabore o programa usando argc.
*/
#include<stdio.h>

int main (int argc, char *argv[]){

    int i;

    for(i=1; i<=argc;i++){
        printf("\n%s\n",argv[i]);
    }

    return 0;
}
//b) Elabore o programa sem usar argc.
#include<stdio.h>

int main(int argc, char *argv[]){

    int i=0;

    do{
        printf("\n%s\n", argv[i]);
        i++;
    }while(argv[i] != NULL);

    return 0;
}
