#include <stdio.h>
#include <math.h>
int main() {
  double num;

  char str[100];

  printf("Numero:");
  scanf("%lf", &num);
  //gcc -o ex2 ex2.c -lm
  num = pow(num, 2);
  printf("Palavra:");
  scanf("%s", str);

  printf("Numero:%.2lf\n Palavra: %s\n",num, str);
  return 0;
}
