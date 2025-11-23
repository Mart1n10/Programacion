#include <stdio.h>
#include <math.h>

void operacion(int n1, int n2, char oper, float* resul, int* error);
int menu();

void Ejercicio1();
void Ejercicio2();
void Ejercicio3();

int main() {
    Ejercicio1();
    printf("\n");
    Ejercicio2();
    printf("\n");
    Ejercicio3();
    return 0;
}

int menu() {
    char opcion;
    int ej;
    do {
        printf("Que ejercicio esta haciendo? 2 o 3\n");
        scanf_s("%d", &ej);
        if (ej == 2 || ej == 3) {
            printf("\nMENU\n");
            printf("+ --> Sumar\n");
            printf("- --> Restar\n");
            printf("* --> Multiplicar\n");
            printf("/ --> Dividir\n");
            printf("^ --> Potencia\n");
            if (ej == 3) {
                printf("! --> Factorial (Solo puede calcular hasta el num 12)\n");
            }
            printf("s --> Salir\n");

            printf("Elija opcion: ");
            scanf_s(" %c", &opcion, 1);

            return opcion;
        }
        else {
            printf("Ejercicio no existente\n");
        }
    }
    while (!(ej == 2 || ej == 3));
}

void operacion(int n1, int n2, char oper, float* resul, int* error) {
    *error = 1;

    switch (oper) {
    case '+': 
        *resul = n1 + n2; 
        break;
    case '-': 
        *resul = n1 - n2; 
        break;
    case '*': 
        *resul = n1 * n2; 
        break;
    case '/':
        if (n2 == 0) {
            *error = -1;
        }
        else {
            *resul = (float)n1 / n2;
        }
        break;
    case '^':
        *resul = pow(n1, n2);
        break;

    case '!':
        // se calcula en ej3
        break;

    case 's':
        printf("Has escogido salir\n");
        break;

    default:
        *error = -1;
    }
}

void Ejercicio1() {
    int n1, n2;
    float resultado;
    int error;
    char oper;

    printf("EJ1 - Introduce dos numeros enteros:\n");
    scanf_s("%d %d", &n1, &n2);

    printf("\nMENU\n");
    printf("+ --> Sumar\n");
    printf("- --> Restar\n");
    printf("* --> Multiplicar\n");
    printf("/ --> Dividir\n");
    printf("^ --> Potencia\n");
    printf("s --> Salir\n");
    printf("Elija opcion: ");
    scanf_s(" %c", &oper, 1);
    
    if (oper == '!') {
        printf("Factorial no disponible en este ejercicio\n");
        return;
    }

    operacion(n1, n2, oper, &resultado, &error);

    if (error == 1 && oper != 's') {
        printf("Resultado: %.2f\n", resultado);
    }
    else if (error == -1) {
        printf("Error en la operacion.\n");
    }
}

void Ejercicio2() {
    int n1, n2;
    float resultado;
    int error;
    char oper;

    printf("EJ2 - Introduce dos numeros enteros:\n");
    scanf_s("%d %d", &n1, &n2);

    oper = menu();

    if (oper == '!') {
        printf("Factorial no disponible en este ejercicio\n");
        return;
    }

    operacion(n1, n2, oper, &resultado, &error);

    if (error == 1 && oper != 's') {
        printf("Resultado: %.2f\n", resultado);
    }
    else if (error == -1) {
        printf("Error en la operacion.\n");
    }
}

void Ejercicio3() {
    int n1, n2;
    float resultado;
    int error;
    char oper;

    printf("EJ3 - Introduce dos numeros enteros:\n");
    scanf_s("%d %d", &n1, &n2);

    oper = menu();

    if (oper == '!') {
        //n1
        if (n1 >= 0 && n1 <= 12) {
            int fact1 = 1;
            for (int i = 1; i <= n1; i++) {
                fact1 *= i;
            }
            printf("El factorial de %d es %d\n", n1, fact1);
        }
        else printf("Numero 1, no esta entre el 0 y el 12\n");

        //n2
        if (n2 >= 0 && n2 <= 12) {
            int fact2 = 1;
            for (int i = 1; i <= n2; i++) {
                fact2 *= i;
            }
            printf("El factorial de %d es %d\n", n2, fact2);
        }
        else printf("Numero 2, no esta entre el 0 y el 12\n");
        return;
    }

    operacion(n1, n2, oper, &resultado, &error);

    if (error == 1 && oper != 's') {
        printf("Resultado: %.2f\n", resultado);
    }
    else if (error == -1) {
        printf("Error en la operacion.\n");
    }
}