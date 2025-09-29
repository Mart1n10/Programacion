//Ejercicio1
/*
#include <stdio.h>

int main() {
	for (int i = 0; i <= 100; i = i + 5) {
		printf("Los multiplos de 0 a 100 son: %d\n", i);
	}
}
*/
//Ejercicio2
/*
#include <stdio.h>

int main()
{
	int num = 0;
	while (num < 100) {
		num = num + 5;
		printf("Los multiplos de 0 a 100 son: %d\n", num);
	}
}
*/
//Ejercicio3
/*
#include <stdio.h>

int main()
{
	int num = 0;
	do {
		num = num + 5;
		printf("Los multiplos de 0 a 100 son: %d\n", num);
	} while (num < 100);
}
*/
//Ejercicio4
/*
#include <stdio.h>

int main() {
	for (int i = 320; i >= 160; i = i - 20) {
		printf("%d\n", i);
	}
}
*/
//Ejercicio5
/*
#include <stdio.h>

int main () {
	int num = 320;
	printf(" 320\n");
	while (num > 160) {
		num = num - 20;
		printf(" %d\n", num);
	}
}
*/
//Ejercicio6
/*
#include <stdio.h>

int main() {
	int num = 320;
	do {
		printf(" %d\n", num);
		num = num - 20;
	} while (num > 160);
}
*/
//Ejercicio7
/*
#include <stdio.h>

int main() {
	int control = 3745, numintro;
	do {
		printf("Dime tu clave de acceso para abrir la caja: \n");
		scanf_s(" %d", &numintro);
		
		if (numintro == control) {
			printf("La caja fuerte se ha abierto satisfactoriamente\n");
		} 
		else printf("Lo siento, esa no es la combinacion\n");
	} while (numintro != control);
}
*/
//Ejercicio8
/*
#include <stdio.h>

int main() {
	int control = 3745, numintro, intentos = 0;
	do {
		printf("Dime tu clave de acceso para abrir la caja: \n");
		scanf_s(" %d", &numintro);
		intentos = intentos + 1;
		if (intentos == 4) return 0;
			
			if (numintro == control) {
				printf("La caja fuerte se ha abierto satisfactoriamente\n");
			}	
			else {
				printf("Lo siento, esa no es la combinacion\n");
				printf("Te quedan: %d intentos\n", intentos);
			}
	} while (numintro != control);
}
*/
//Ejercicio9
/*
#include <stdio.h>

int main() {
    int num, original;
    int contador = 0;

    printf("Introduce un numero:\n");
    scanf_s("%d", &num);

    original = num;

    if (num == 0) {
        contador = 1;
    } else {
        if (num < 0) {
            num = -num;
        }
        while (num > 0) {
            num = num / 10; // eliminamos el último dígito
            contador++;
        }
    }
    printf("El numero %d tiene %d digitos\n", original, contador);
}
*/
//Ejercicio10
/*
#include <stdio.h>

int main() {
	int num, intentos = 3;
	do {
		printf("Introduce un numero:\n");
		scanf_s("%d", &num);
		if (num <= 1) {
			intentos--;
			printf("%d no es primo, te quedan %d intentos\n", num, intentos);
		}
		else {
			int i;
			for (i = 2; i <= num / 2; i++) {
				if (num % i == 0) {
					intentos--;
					printf("%d no es primo, te quedan %d intentos\n", num, intentos);
					break;
				}
			}
			if (i > num / 2) {
				printf("Felicidades! %d es primo\n", num);
				break;
			}
		}
	} while (intentos > 0);
}
*/