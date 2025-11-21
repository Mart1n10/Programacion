#include <stdio.h>
#include <math.h>

float suma(float a, float b);
float resta(float a, float b);
float multi(float a, float b);
float division(float a, float b, int* error);
float potencia(float a, float b);
int factorial(int n);
void operacion(int n1, int n2, char oper, float* resultado, int* error);
char menu(int ejercicio, int* error);

// Ejercicio 1
/*
int main() {
    int n1, n2;
    char oper;
    float resultado = 0;
    int error = 0;

    printf("Introduce dos numeros enteros: \n");
    scanf_s("%d %d", &n1, &n2);

    printf("MENU\n");
    printf("+ --> Sumar\n");
    printf("- --> Restar\n");
    printf("* --> Multiplicar\n");
    printf("/ --> Dividir\n");
    printf("^ --> Potencia\n");
    printf("s --> Salir\n");
    printf("Elija opcion: \n");
    scanf_s(" %c", &oper, 1);
    if (!(oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == 's')) {
        printf("Error: opcion invalida en el menu\n");
        error = -1;
        return 0;
    }
    else {
        error = 1;
    }
    operacion(n1, n2, oper, &resultado, &error);

    if (error == 1 && oper != 's') {
        printf("Resultado: %.2f\n", resultado);
    }
    else if (error == -1) {
        printf("Error: operación no válida.\n");
    }
    else if (oper == 's') {
        printf("Has escogido salir.\n");
    }
    return 0;
}
*/

// Ejercicio 2
/*
int main() {
    int n1, n2;
    char oper;
    float resultado = 0;
    int error = 0;
    int error_menu = 0;

    printf("Introduce dos numeros enteros: \n");
    scanf_s("%d %d", &n1, &n2);

    oper = menu(2, &error_menu);
    if (error_menu == -1) {
        printf("Error: opcion invalida en el menu\n");
        return 1;
    }

    operacion(n1, n2, oper, &resultado, &error);

    if (error == 1 && oper != 's') {
        printf("Resultado: %.2f\n", resultado);
    }
    else if (error == -1) {
        printf("Error: operacion no valida.\n");
    }
    else if (oper == 's') {
        printf("Has escogido salir.\n");
    }
    return 0;
}
*/

// Ejercicio 3
/*
int main() {
    int n1, n2;
    char oper;
    float resultado = 0;
    int error = 0;
    int error_menu = 0;

    printf("Introduce dos numeros enteros: \n");
    scanf_s("%d %d", &n1, &n2);

    oper = menu(3, &error_menu);
    if (error_menu == -1) {
        printf("Error: opcion invalida en el menu\n");
        return 1;
    }

    operacion(n1, n2, oper, &resultado, &error);

    if (error == 1 && oper != '!' && oper != 's') {
        printf("Resultado: %.2f\n", resultado);
    }
    else if (error == -1) {
        printf("Error: operacion no valida.\n");
    }
    else if (oper == 's') {
        printf("Has escogido salir.\n");
    }
    return 0;
}
*/

char menu(int ejercicio, int* error) {
    char opcion;
    printf("MENU\n");
    printf("+ --> Sumar\n");
    printf("- --> Restar\n");
    printf("* --> Multiplicar\n");
    printf("/ --> Dividir\n");
    printf("^ --> Potencia\n");
    if (ejercicio == 3) {
        printf("! --> Factorial\n");
    }
    printf("s --> Salir\n");
    printf("Elija opcion: \n");
    scanf_s(" %c", &opcion, 1);

    if (ejercicio != 3 && opcion == '!') {
        printf("Respuesta invalida\n");
        *error = -1;
    }
    else {
        *error = 0;
    }

    return opcion;
}

void operacion(int n1, int n2, char oper, float* resultado, int* error) {
    int f1, f2;
    switch (oper) {
    case '+':
        *resultado = suma(n1, n2);
        *error = 1;
        break;
    case '-':
        *resultado = resta(n1, n2);
        *error = 1;
        break;
    case '*':
        *resultado = multi(n1, n2);
        *error = 1;
        break;
    case '/':
        if (n2 == 0)
            *error = -1;
        else {
            *resultado = division(n1, n2, error);
            *error = 1;
        }
        break;
    case '^':
        *resultado = potencia(n1, n2);
        *error = 1;
        break;
    case '!':
        if (n1 < 0 || n2 < 0) {
            *error = -1;
        }
        else {
            f1 = factorial(n1);
            f2 = factorial(n2);
            printf("Factorial de %d = %d\n", n1, f1);
            printf("Factorial de %d = %d\n", n2, f2);
            *error = 1;
        }
        break;
    case 's':
        *error = 1;
        break;
    default:
        *error = -1;
        break;
    }
}

float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multi(float a, float b) {
    return a * b;
}

float division(float a, float b, int* error) {
    return a / b;
}

float potencia(float a, float b) {
    return pow(a, b);
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int r = 1;
    for (int i = 1; i <= n; i++) {
        r *= i;
    }
    return r;
}