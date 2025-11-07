#include <stdio.h>

void Ejercicio1();
void Par(int num);

void Ejercicio2();
void Media2(float num1, float num2);

void Ejercicio3();
void Media3(float numR1, float numR2, float numR3);

void Ejercicio4();
void Saludo();

void Ejercicio5();
int Negativo(int numE5);

void Ejercicio6();
void Op(float num1E6, float num2E6);
float Suma(float num1E6, float num2E6);
float Resta(float num1E6, float num2E6);
float Multiplicacion(float num1E6, float num2E6);
float Division(float num1E6, float num2E6);

int main() {
	Ejercicio1();
	Ejercicio2();
	Ejercicio3();
	Ejercicio4();
	Ejercicio5();
	Ejercicio6();
}

void Ejercicio1()
{
	int num;
	printf("EJ1- Introduce un numero y te dire si es par(1) o impar(0): ");
	scanf_s("%d", &num);
	Par(num);
}

void Par(int num) {
	if (num % 2 == 0) printf("1");
	else printf("0");
}

void Ejercicio2() {
	float num1, num2;
	printf("\n\n");
	printf("EJ2- Introduce numeros reales, y te dare la media\n");
	scanf_s("%f", &num1);
	scanf_s("%f", &num2);
	Media2(num1, num2);
}

void Media2(float num1, float num2)
{
	float media2 = (num1 + num2) / 2;
	printf("La media de %.2f y %.2f es: %.2f", num1, num2, media2);
}

void Ejercicio3() {
	float numR1, numR2, numR3;
	printf("\n\n");
	printf("EJ3- Introduce tres numeros reales: \n");
	scanf_s("%f %f %f", &numR1, &numR2, &numR3);
	Media3(numR1, numR2, numR3);
}

void Media3(float numR1, float numR2, float numR3) {
	float media3 = (numR1 + numR2 + numR3) / 3;
	printf("La media de los tres numeros es: %.2f", media3);
}

void Ejercicio4() {
	Saludo();
}

void Saludo() {
	printf("\n\n");
	printf("EJ4- Hola");
}

void Ejercicio5() {
	int numE5;
	printf("\n\n");
	printf("EJ5- Introduce un numero entero, si es (-) devuelve 1, si es (+) devuelve 0: ");
	scanf_s("%d", &numE5);
	Negativo(numE5);
}

int Negativo(int numE5) {
	int cont = 0;
	if (numE5 < 0) printf("1");
	else printf("0");
	return 0;
}

void Ejercicio6() {
	float num1E6, num2E6;
	printf("\n\n");
	printf("EJ6- Calculadora para saber la (+), (-), (*), (/) de dos numeros\n");
	printf("Primer numero: ");
	scanf_s("%f", &num1E6);
	printf("Segundo numero: ");
	scanf_s("%f", &num2E6);
	Op(num1E6, num2E6);
}

void Op(float num1E6, float num2E6) {
	printf("Suma: %.2f\n", Suma(num1E6, num2E6));
	printf("Resta: %.2f\n", Resta(num1E6, num2E6));
	printf("Multiplicacion: %.2f\n", Multiplicacion(num1E6, num2E6));
	if (num2E6 == 0) printf("No se puede dividir entre 0");
	else printf("Division: %.2f", Division(num1E6, num2E6));
}

float Suma(float num1E6, float num2E6) {
	return num1E6 + num2E6;
}

float Resta(float num1E6, float num2E6) {
	return num1E6 - num2E6;
}

float Multiplicacion(float num1E6, float num2E6) {
	return num1E6 * num2E6;
}

float Division(float num1E6, float num2E6) {
	return num1E6 / num2E6;
}