#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "soma.h"

#define LIMITE_TESTE 20

void ValidaResultado(bool testeValido, int primeiroNumero, int segundoNumero)
{
if (testeValido == true)
printf("Teste realizado com SUCESSO para os numeros %d e %d\n", primeiroNumero, segundoNumero);
else
printf("Teste realizado com FALHA para os numeros %d e %d\n", primeiroNumero, segundoNumero);
}

bool TesteSoma(int primeiroNumero, int segundoNumero)
{
int resultado = soma(primeiroNumero,segundoNumero);
int operacaoEsperada = primeiroNumero + segundoNumero;

bool testeValido = false;

if (resultado == operacaoEsperada)
	testeValido = true;
else 
	testeValido = false;

return testeValido;

}

void ExecutaTesteSoma(int primeiroNumero, int segundoNumero)
{
bool testeValido = false;
testeValido = TesteSoma(primeiroNumero,segundoNumero);
ValidaResultado(testeValido,primeiroNumero,segundoNumero);
}

void ExecutaPrimeiroLoteTeste()
{
int primeiroNumero = 4;
int segundoNumero = 2;

printf("Teste de soma do primeiro lote somente com numeros positivos\n\n");
for (int i = 0; i < LIMITE_TESTE; i++)
{
	ExecutaTesteSoma(primeiroNumero,segundoNumero);
	primeiroNumero++;
	segundoNumero++;
}

}

void ExecutaSegundoLoteTeste()
{
printf("\nTeste de soma do segundo lote com numeros positivos e negativos\n\n");

int primeiroNumero = 4;
int segundoNumero = 2;

for (int i = 0; i < LIMITE_TESTE; i++)
{
	ExecutaTesteSoma(primeiroNumero,segundoNumero);
	primeiroNumero--;
	segundoNumero--;
}

}

int main(void)
{
ExecutaPrimeiroLoteTeste();
ExecutaSegundoLoteTeste();
return 0;
}