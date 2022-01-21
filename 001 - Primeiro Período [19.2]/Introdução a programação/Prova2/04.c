#include <stdio.h>

int main(){
  char operador;
  int num1, num2, resultado;
  do{
    scanf("%c", &operador);
    scanf("%d", &num1);
    scanf("%d", &num2);

    switch (operador) {
      case '+':
        resultado = num1 + num2;
        break;
      case '-':
        resultado = num1 - num2;
        break;
      case '*':
        resultado = num1 * num2;
        break;
      case '/':
        resultado = num1 / num2;
        break;
      default:
        operador = '!';
    }
    if(operador != '!')
      printf("%d\n", resultado);
  }while(operador != '!');

  return 0;
}
