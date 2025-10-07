//Ejercicio1
/*
#include <stdio.h>

int main() {
	int vect[20];
	int suma = 0, mayor = 0, posicion;
	printf("Buenas, introduce 20 valores de tipo entero, y te dare la suma, el mayor y su posicion\n");
	for (int i = 0; i < 20; i++) {
		printf("Introduce: ");
		scanf_s("%d", &vect[i]);
		suma += vect[i];
		if (vect[i] > mayor) {
			mayor = vect[i];
			posicion = i + 1;
		}
	}
	printf("La suma de todos es: %d, el numero mayor es: %d y su posicion: %d", suma, mayor, posicion);
}
*/

//Ejercicio2
/*
#include <stdio.h>

int main() {
	int v1[12], v2[12], v3[12];
	printf("Introduce 12 numeros enteros\n");
	for (int i = 0; i < 12; i++) {
		printf("Introduce: ");
		scanf_s("%d", &v1[i]);
	}
	
	for (int i = 0; i < 12; i++) {
		if (v1[i] > 5) {
			v3[i] = -1;
		} else v3[i] = v1[i];
	}
	
	for (int i = 0; i < 12; i++) {
		v2[i] = v1[11 - i];
	}

	printf("\n");
	printf("Vector1 = ");
	for (int i = 0; i < 12; i++) {
		printf("%d ", v1[i]);
		if (i < 11) {
			printf(", ");
		}
	}
	printf("\n\n");
	printf("Vector2 = ");
	for (int i = 0; i < 12; i++) {
		printf("%d ", v2[i]);
		if (i < 11) {
			printf(", ");
		}
	}
	printf("\n\n");
	printf("Vector3 = ");
	for (int i = 0; i < 12; i++) {
		printf("%d ", v3[i]);
		if (i < 11) {
			printf(", ");
		}
	}
	printf("\n");
}
*/

//Ejercicio3
/*
#include <stdio.h>

int main() {
	int v1[3];
	int v2[3];
	int resultado = 0;
	printf("Introduce 3 numeros para el primer vector\n");
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &v1[i]);
	}
	printf("Introduce 3 numeros para el segundo vector\n");
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &v2[i]);
	}
	for (int i = 0; i < 3; i++) {
		resultado = resultado + (v1[i] * v2[i]); //tambien se puede hacer: resultado += (v1[i] * v2[i]);
	}
	printf("El resultado del producto a escalar es: %d", resultado);
}
*/

//Ejericio4
/*
#include <stdio.h>

int main() {
	int v1[10], v2[10], v3[10];
	printf("Introduce el primer vector, 10 numeros enteros\n");
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &v1[i]);
	}
	printf("Introduce el segundo vector, 10 numeros enteros\n");
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &v2[i]);
	}
	printf("El resultado de los calculos es: \n");
	for (int i = 0; i < 10; i++) {
		if (v1[i] > v2[i]) {
			v3[i] = v1[i] + v2[i];
		} else v3[i] = v2[i] - v1[i];
		printf("%d, ", v3[i]);
	}
}
*/

//Ejercicio5
/*
#include <stdio.h>

int main() {
	int vect[6];
	int menor, mayor, suma = 0;
	printf("Introduce 5 numeros enteros:\n");
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &vect[i]);
	}
	menor = vect[0]; // inicializa menor y mayor al primer numero
	mayor = vect[0]; // inicializa menor y mayor al primer numero

	for (int i = 1; i < 5; i++) {
		if (vect[i] > mayor) mayor = vect[i];
		if (vect[i] < menor) menor = vect[i];
	}

	suma = mayor + menor;
	vect[5] = suma;

	printf("El vector es: ");
	for (int i = 0; i < 6; i++) {
		printf("%d, ", vect[i]);
	}
	printf("\n");
	printf("El ultimo numero '%d', es la suma del mayor '%d' y el menor '%d'.", suma, mayor, menor);
}
*/

//Ejercicio6
/*
#include <stdio.h>

int main() {
	int vect[4];
	printf("Introduzca 4 valores, si son mayores que 10, lo duplicaremos\n");
	for (int i = 0; i < 4; i++) {
		scanf_s("%d", &vect[i]);
		if (vect[i] > 10) {
			vect[i] *= 2;
		}
	}
	printf("Aqui esta su vector: ");
	for (int i = 0; i < 4; i++) {
		printf("%d, ", vect[i]);
	}
}
*/

//Ejercicio7
/*
#include <stdio.h>

int main() {
	int vect[6];
	int pares = 0;

	printf("Introduce 6 numeros enteros:\n");
	for (int i = 0; i < 6; i++) {
		scanf_s("%d", &vect[i]);
	}

	printf("Vector: ");
	for (int i = 0; i < 6; i++) {
		printf("%d, ", vect[i]);
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {  // Invierte el vector sobre sí mismo hasta la mitad
		int temp = vect[i];
		vect[i] = vect[5 - i];
		vect[5 - i] = temp;
	}

	printf("Vector invertido: ");
	for (int i = 0; i < 6; i++) {
		printf("%d, ", vect[i]);
	}
	printf("\n");

	for (int i = 0; i < 6; i++) {
		if (vect[i] % 2 == 0) {
			pares++;
		}
	}
	printf("Numeros pares: %d\n", pares);
}
*/