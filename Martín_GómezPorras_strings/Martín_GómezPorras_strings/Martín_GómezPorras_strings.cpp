//Ejercicio1
/*
#include <stdio.h>
#include <string.h>
#define nums 90

int main() {
    char palabra[nums];
    char reves[nums];

    printf("Introduce una palabra y te digo si es palindroma: ");
    gets_s(palabra, nums);

    int tamanio = strlen(palabra);

    for (int i = 0; i < tamanio; i++) {
        reves[i] = palabra[tamanio - 1 - i];
    }
    reves[tamanio] = '\0';

    printf("Tu palabra es: %s\n", palabra);
    printf("Tu palabra al reves es: %s\n", reves);

    for (int i = 0; i < tamanio; i++) {
       for (int j = 0; j < tamanio; j++) {
           if (palabra[i] == reves[j]) {
               printf("%s es palindroma", palabra);
               return 0;
           }
           else printf("%s no es palindroma", palabra);
           return 0;
       }
    }
}
*/

//Ejercicio2
/*
#include <stdio.h>
#include <string.h>
#define fras 100

int main() {
    char frase[fras];
    int a = 0, e = 0, i_ = 0, o = 0, u = 0;

    printf("Introduce una frase: \n");
    gets_s(frase, fras);
    int tamanio = strlen(frase);
    printf("La frase es de tamanio %d\n", tamanio);

    for (int i = 0; i < tamanio; i++) {
        switch (frase[i]) {
        case 'A': {
            a += 1;
            break;
        }
        case 'a': {
            a += 1;
            break;
        }
        case 'E': {
            e += 1;
            break;
        }
        case 'e': {
            e += 1;
            break;
        }
        case 'I': {
            i_ += 1;
            break;
        }
        case 'i': {
            i_ += 1;
            break;
        }
        case 'O': {
            o += 1;
            break;
        }
        case 'o': {
            o += 1;
            break;
        }
        case 'U': {
            u += 1;
            break;
        }
        case 'u': {
            u += 1;
            break;
        }
            default:
                break;
            }
    }
    if (a > 0) {
        printf("Tu frase tiene %d letras a\n", a);
    }
    if (e > 0) {
        printf("Tu frase tiene %d letras e\n", e);
    }
    if (i_ > 0) {
        printf("Tu frase tiene %d letras i\n", i_);
    }
    if (o > 0) {
        printf("Tu frase tiene %d letras o\n", o);
    }
    if (u > 0) {
        printf("Tu frase tiene %d letras u\n", u);
    }
    else if (a == 0 && e == 0 && i_ == 0 && o == 0 && u == 0) {
        printf("Tu frase no tiene vocales");
    }
}
*/

//Ejercicio3
/*
#include <stdio.h>
#include <string.h>
#define cadena 100

int main() {
    char intro[cadena];

    printf("Introduce una cadena de texto, cambiare las vocales por .\n");
    gets_s(intro, cadena);
    int tamanio = strlen(intro);
    for (int i = 0; i < tamanio; i++) {
        if (intro[i] == 'a' || intro[i] == 'e' || intro[i] == 'i' || intro[i] == 'o' || intro[i] == 'u') {
            intro[i] = '.';
        }
        else if (intro[i] == 'A' || intro[i] == 'E' || intro[i] == 'I' || intro[i] == 'O' || intro[i] == 'U') {
            intro[i] = '.';
        }
    }
    printf("La cadena de texto es: %s", intro);
}
*/

//Ejercicio4
/*
#include <stdio.h>
#include <string.h>
#define numP 100

int main() {
    char intro[numP];
    int vocales = 0, consonantes = 0, especiales = 0;
    printf("Escribe una cadena de texto:\n");
    gets_s(intro, numP);
    int tamanio = strlen(intro);

        for (int i = 0; i < tamanio; i++) {
            if (intro[i] == 'a' || intro[i] == 'e' || intro[i] == 'i' || intro[i] == 'o' || intro[i] == 'u' || intro[i] == 'A' || intro[i] == 'E' || intro[i] == 'I' || intro[i] == 'O' || intro[i] == 'U') {
                vocales++;
            }
            else if (intro[i] == ' ' || intro[i] == ',' || intro[i] == '.' || intro[i] == '?' || intro[i] == '¿' || intro[i] == '!' || intro[i] == '¡') {
                especiales++;
            }
            else consonantes++;
        }
        printf("Tiene %d vocales, %d consonantes y %d signos especiales", vocales, consonantes, especiales);
}
*/

//Ejercicio5
/*
#include <stdio.h>
#include <string.h>
#define numL 100

int main() {
    char frase[numL];
    printf("Escribe una frase, te dare cada palabra seguida del numero de letras:\n");
    gets_s(frase, numL);

    int tamano = strlen(frase);
    int letras = 0;

    printf("\n");
    for (int i = 0; i <= tamano; i++) {
        if (frase[i] != ' ' && frase[i] != '\0') { // '\0' si frase[i] no es el final de la cadena
            printf("%c", frase[i]);
            letras++;
        } else {
            if (letras > 0) {
                printf(" = %d letras\n", letras);
                letras = 0;
            }
        }
    }
}
*/

//Ejercicio6
/*
#include <stdio.h>
#include <string.h>
#define numM 100

int main() {
        char frase[numM];
        char resultado[numM];
        int j = 0;

        printf("Introduce una frase y los espacios multiples se reduciran a solo uno:\n");
        gets_s(frase, numM);
        int len = strlen(frase);

        for (int i = 0; i < len; i++) {
            if (!(frase[i] == ' ' && frase[i + 1] == ' ')) { // ! = invierte el if = El código dentro del if se ejecuta cuando: NO hay dos espacios seguidos
                resultado[j] = frase[i];
                j++;
            }
        }
        resultado[j] = '\0'; // marca el final de la cadena

        printf("Frase corregida: \n%s", resultado);
}
*/