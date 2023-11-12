#include <stdlib.h>
#include <stdio.h>

#include "soma.h"
#include "subtrai.h"
#include "multiplica.h"
#include "divide.h"
#include "resto.h"

#define VERSAO "1.2"

int main(void)
{
int primeiroNumero = 31;
int segundoNumero = 25;

printf("Programa principal - versao %s\n\n", VERSAO);

printf("A soma resulta em %d\n",soma(primeiroNumero,segundoNumero));
printf("A subtracao resulta em %d\n",subtrai(primeiroNumero,segundoNumero));
printf("A multiplicacao resulta em %d\n",multiplica(primeiroNumero,segundoNumero));
printf("A divisao resulta em %d\n",divide(primeiroNumero,segundoNumero));
printf("O resto resulta em %d\n",resto(primeiroNumero,segundoNumero));

}