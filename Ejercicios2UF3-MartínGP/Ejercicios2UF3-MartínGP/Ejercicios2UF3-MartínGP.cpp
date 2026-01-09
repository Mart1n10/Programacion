//Ejercicio 1
/*
#include <stdio.h>

void limpiarArray(int a[4][3]);
void imprimeArray(int a[4][3]);
int rellenarArray(int a[4][3], int* n);

int main() {
    int array[4][3];
    int n;

    limpiarArray(array);
    rellenarArray(array, &n);

    return 0;
}

void limpiarArray(int a[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = 0;
        }
    }
}

void imprimeArray(int a[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int rellenarArray(int a[4][3], int* n) {
    *n = 0;

    printf("Introduce los valores del array de 4 x 3:\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf_s("%d", &a[i][j]);
            if (a[i][j] <= 5) {
                *n = *n + 1;
            }
        }
    }

    printf("Array rellenado:\n");
    imprimeArray(a);

    printf("Total de numeros iguales o menores que 5: % d\n", *n);

    FILE* f;
    if (fopen_s(&f, "resultados.txt", "w") == 0) {
        fprintf(f, "Total de numeros iguales o menores que 5: %d\n", *n);
        fclose(f);
    }
    return *n;
}
*/

//Ejercicio 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int monedaMaquina();
int monedaJugador();
void guardarResultados(int ganadosJugador, int ganadosMaquina);
void cargarDatos(int* ganadosJugador, int* ganadosMaquina);

int main() {
    srand(time(NULL));
    int ganadosJugador = 0, ganadosMaquina = 0;
    char repetir;

    cargarDatos(&ganadosJugador, &ganadosMaquina);

    printf("Bienvenidos al juego de cara o cruz\n");

    do {
        int mM = monedaMaquina();
        int mJ = monedaJugador();

        if (mJ == 2) {
            printf("La apuesta no es valida. Intentalo de nuevo.\n\n");
            continue;
        }

        printf("La maquina saco: %s (%d)\n", mM == 0 ? "CARA" : "CRUZ", mM);

        if (mM == mJ) {
            printf("Has acertado!\n");
            ganadosJugador++;
        }
        else {
            printf("Has fallado.\n");
            ganadosMaquina++;
        }

        printf("\nQuieres jugar otra vez? si (s) no (n): ");
        scanf_s(" %c", &repetir, 1);
        printf("\n");

    } while (repetir == 's' || repetir == 'S');

    guardarResultados(ganadosJugador, ganadosMaquina);

    printf("Juego terminado. Resultados guardados en datos.txt\n");
    printf("Ganados Jugador: %d, Ganados Maquina: %d\n", ganadosJugador, ganadosMaquina);

    return 0;
}

int monedaMaquina() {
    return rand() % 2;
}

int monedaJugador() {
    int mJ;
    printf("Apuesta: cara (0) cruz (1): ");
    scanf_s("%d", &mJ);

    if (mJ >= 0 && mJ <= 1) {
        return mJ;
    }
    else {
        return 2;
    }
}

void guardarResultados(int ganadosJugador, int ganadosMaquina) {
    FILE* f;

    int jugadorPrevio = 0, maquinaPrevio = 0;
    if (fopen_s(&f, "datos.txt", "r") == 0) {
        fscanf_s(f, "Ganados Jugador %d Ganados Maquina %d\n", &jugadorPrevio, &maquinaPrevio);
        fclose(f);
    }

    if (fopen_s(&f, "datos.txt", "w") == 0) {
        fprintf(f, "Ganados Jugador %d Ganados Maquina %d\n",
            ganadosJugador + jugadorPrevio, ganadosMaquina + maquinaPrevio);
        fclose(f);
    }
}

void cargarDatos(int* ganadosJugador, int* ganadosMaquina) {
    FILE* f;
    *ganadosJugador = 0;
    *ganadosMaquina = 0;

    if (fopen_s(&f, "datos.txt", "r") == 0) {
        if (fscanf_s(f, "Ganados Jugador %d Ganados Maquina %d\n",
            ganadosJugador, ganadosMaquina) == 2) {
            printf("Datos cargados - Jugador: %d, Maquina: %d\n\n",
                *ganadosJugador, *ganadosMaquina);
        }
        fclose(f);
    }
}
*/