
#include <iostream>

using namespace std;
const int n = 100;

void numeros_primos(int array[], int n);
void numeros_primos_cc(int array[], int n);

int main() {

	int array[n];

	for (int i = 0; i < n; i++)
	{
		array[i] = 0;
	}

	numeros_primos(array, n);

	
	for (int i = 0; i < n; i++) {
		cout << array[i] << ", ";
	}
	int d;
	cout << "parar" << endl;
	cin >> d;
	return 0;
}

void numeros_primos_cc(int vector[], int n) {
	int contador = 0;
	int numero = 2;
	while (contador < n)
	{
		int es_primo = 0;
		for (int i = 2; i < numero / 2; i++)
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


void numeros_primos(int arra[], int n)
{
	__asm
	{
		mov eax, n; n
		mov ebx, 1; numero
		mov ecx, 0; contador

		mov edx, arra;edx contiene la direccion del arra


		while:
		cmp ecx, eax; contador > n
			ja fin_while

			push ecx			; se mete en la pila contador
			mov ecx, 2			; i del for

			push eax; se mete n en la pila

			inc ebx; se incrementa el numero en 1


			for:
		cmp ecx, ebx;   i del for < numero
			jb fin_for


			; numero / i
					mov ax, bx; mover a al la parte baja de el numero
					mov ah, 0
				
					div cx

					cmp ah, 0
					jnb fin_for_no_es_primo


			jmp for
			fin_for:


			; a�adir al vector
			pop eax;
			pop ecx; ecx es ahora el contador
				
				mov [edx], ebx
				
				inc ecx; incrementar uno a la variable


				add arra,4

				mov edx, arra

			jmp while

			fin_for_no_es_primo :
			pop eax;
			pop ecx; ecx es ahora el contador

			


			jmp while
			fin_while:
	}
}