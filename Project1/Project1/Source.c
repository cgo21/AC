#include <stdio.h>
#include <iostream>
#include <time.h>


using namespace std;

const int n = 100;

void numeros_primos(int array[], int n);
void numeros_primos_cc(int array[], int n);

int main() {

	int array[n];

	numeros_primos(array, n);

	for (int i = 0; i < n; i++) {
		printf("%d, ", array[i]);
	}
	int d;
	cin >> d;
	return 0;
}

void numeros_primos_cc(int vector[], int n){
	int contador = 0;
	int numero = 2;
	while (contador < n)
	{
		int es_primo = 0;
		for (int i = 2; i < numero/2 ; i++)
		{
			if (numero%i == 0)
			{
				es_primo = 1;
				break;
			}
		}

		if (es_primo == 0)
		{
			vector[contador] = numero;
			contador++;
		}

		numero++;
	}
}


void numeros_primos(int array[], int n)
{
	_asm
	{
		mov eax, n; n
		mov ecx, 0; contador
		mov ebx, 2; numero

		mov edx, vector


		while:
		cmp ecx, eax; contador < n
			js fin_while

			push ecx; se mete en la pila
			mov ecx, 2;i del for
				
			for:
				cmp ecx, ebx
				js fin_for

				; numero / i
				mov al, ebx
				mov ah, 0
				mov cl, ecx
				div cl

				cmp ah, 0
				js fin_for_no_es_primo


				jmp for

			fin_for:

		; añadir al vector
			pop ecx; ecx es ahora el contador
			inc ecx, 1

			mov [vector], ebx

			inc vector, 4

			fin_for_no_es_primo :

			inc ebx, 1; se incrementa el numero en 1
			
			jmp while
		fin_while:
	}
}