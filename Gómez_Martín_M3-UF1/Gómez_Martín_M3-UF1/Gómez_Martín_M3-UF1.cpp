//Ejercicio 1
/* 
#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Buenas, dame dos numeros, para ver lo que hacemos \n");
    printf("Numero 1: \n");
    scanf_s("%d", &num1);
    printf("Numero 2: \n");
    scanf_s("%d", &num2);
    if (num1 == num2) {
        printf("La multiplicacion de los numeros es: %d", num1 * num2);
    }
    else if (num1 > num2) {
        printf("La resta de los numeros es: %d", num1 - num2);
    } else printf("La suma de los numeros es: %d", num1 + num2);
} 
*/
//Ejercicio 2
/*
#include <stdio.h>

int main() {
    float num1, num2, num3;
    printf("Dame tres numeros diferentes, y te devolvere el numero mas grande\n");
    printf("Numero 1: ");
    scanf_s("%f", &num1);
    printf("Numero 2: ");
    scanf_s("%f", &num2);
    printf("Numero 3: ");
    scanf_s("%f", &num3);
    if (num1 == num2 || num1 == num3 || num2 == num3) {
        printf("No puede haber numeros repetidos, vuelve a repetirlo");
        return 0;
    }
    if (num1 > num2 && num1 > num3) {
        printf("El numero mas grande es el primero, el: %.2f", num1);
    } 
    else if (num2 > num1 && num2 > num3) {
        printf("El numero mas grande es el segundo, el: %.2f", num2);
    }else printf("El numero mas grande es el tercero, el: %.2f", num3);
}
*/
//Ejercicio 3
/*
#include <stdio.h>

int main() {
    float horasTrabajadas, horasExtra;
    printf("Dime tus horas trabajadas\n");
    scanf_s("%f", &horasTrabajadas);
    if (horasTrabajadas <= 40 && horasTrabajadas > 0) {
        printf("Tu salario es de: %.2f euros", horasTrabajadas * 20);
    }
    else if (horasTrabajadas > 40) {
        horasExtra = horasTrabajadas - 40;
        horasTrabajadas = horasTrabajadas - horasExtra;
        printf("Tu salario es de: %.2f euros\n", (horasTrabajadas * 20) + (horasExtra * 40));
    }
    else printf("Asi va Espania");
}
*/
//Ejercicio 4
/*
#include <stdio.h>
int main() {
    int edad, sexo;
    printf("Buenas, vamos a calcular tu numero de pulsaciones cada 10 segundos, te hare unas cuantas preguntas\n");
    printf("Eres hombre o mujer?\n");
    printf("1 --> Eres hombre ");
    printf("2 --> Eres Mujer ");
    scanf_s("%d", &sexo);
    if (sexo == 1) {
        printf("Vale, eres hombre, ahora dime tu edad ");
        scanf_s("%d", &edad);
        printf("Tu numero de pulsaciones cada 10 segundos es de: %.2d", (210 - edad)/10);
    }
    else if (sexo == 2) {
        printf("Vale, eres mujer, ahora dime tu edad ");
        scanf_s("%d", &edad);
        printf("Tu numero de pulsaciones cada 10 segundos es de: %.2d", (220 - edad) / 10);
    }
    else printf("Respuesta incorrecta");
}
*/
//Ejercicio 5
/*
#include <stdio.h>
int main() {
    float totalC;
    int bolita;
    printf("Buenas, cual es el total de su compra?\n");
    scanf_s("%f", &totalC);
    if (totalC >=0.1) {
        printf("Y que bolita le ha tocado?\n");
        printf("Escriba el numero segun la siguente tabla\n");
        printf("1 - blanco\n");
        printf("2 - verde\n");
        printf("3 - amarilla\n");
        printf("4 - azul\n");
        printf("5 - roja\n");
        scanf_s("%d", &bolita);
        
        switch (bolita)
        {
        case 1:
            printf("Que mala suerte! su bolita es blanca, no tiene descuento, tendra que pagar: %.2f euros", totalC);
            break;

        case 2:
            printf("No esta mal, su bolita es verde, tiene un descuento del 10 porciento, tendra que pagar: %.2f euros", totalC - (totalC * 0.10));
            break;

        case 3:
            printf("Bastante bien!, su bolita es amarilla, tiene un descuento del 25 porciento, tendra que pagar: %.2f euros", totalC - (totalC * 0.25));
            break;

        case 4:
            printf("Muy bien!!, su bolita es azul, tiene un descuento del 50 porciento, tendra que pagar: %.2f euros", totalC - (totalC * 0.50));
            break;

        case 5:
            printf("QUE SUERTEE!!! su bolita es ROJA, tiene un descuento del 100 porciento, se puede llevar su compra por 0 euros");
            break;

        default:
            printf("Esa bolita no existe, vaya a sacar una");
            break;
        }
    } else printf("Para venir a caja tiene que comprar al menos 1 producto");
}
*/