#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define NAVES 3
#define LARGO_NAVE 3

int main() {
    char mapa[TAM][TAM];
    int navesRestantes = NAVES * LARGO_NAVE;
    int fila, columna;
    int intentos = 0;

    // Inicializar el mapa vacio
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            mapa[i][j] = '.';
        }
    }

    srand(time(NULL));

    // Colocar naves aleatoriamente
    for (int n = 0; n < NAVES; n++) {
        int colocada = 0;
        int intentosMax = 100;

        while (!colocada && intentosMax > 0) {
            int x = rand() % TAM;
            int y = rand() % TAM;
            int direccion = rand() % 4;

            int puedoColocar = 1;
            for (int k = 0; k < LARGO_NAVE; k++) {
                int nx = x, ny = y;

                if (direccion == 0) ny += k;      // Horizontal derecha
                else if (direccion == 1) nx += k; // Vertical abajo
                else if (direccion == 2) { nx += k; ny += k; } // Diagonal
                else if (direccion == 3) { nx += k; ny -= k; } // Diagonal

                // Verificar limites
                if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM) {
                    puedoColocar = 0;
                    break;
                }

                // Verificar si ya hay una nave
                if (mapa[nx][ny] == '#') {
                    puedoColocar = 0;
                    break;
                }
            }

            // Si puede colocar, colocar la nave
            if (puedoColocar) {
                for (int k = 0; k < LARGO_NAVE; k++) {
                    int nx = x, ny = y;

                    if (direccion == 0) ny += k;
                    else if (direccion == 1) nx += k;
                    else if (direccion == 2) { nx += k; ny += k; }
                    else if (direccion == 3) { nx += k; ny -= k; }

                    mapa[nx][ny] = '#';
                }
                colocada = 1;
            }
            intentosMax--;
        }
    }

    printf("    HUNDIR LA FLOTA    \n");
    printf("Mapa de 10x10 (coordenadas: fila X, columna Y)\n");
    printf("Tienes que encontrar %d naves de %d posiciones.\n\n", NAVES, LARGO_NAVE);

    while (navesRestantes > 0) {
        // Mostrar el mapa
        printf("    ");//4
        for (int j = 0; j < TAM; j++) printf("%d ", j);
        printf("\n");

        for (int i = 0; i < TAM; i++) {
            printf("%2d  ", i);
            for (int j = 0; j < TAM; j++) {
                if (mapa[i][j] == '#' || mapa[i][j] == '.')
                    printf(". ");
                else
                    printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }

        printf("\nIntroduce las coordenadas (entre 0 y 9)");
        printf("\nFila (X): ");
        scanf_s("%d", &fila);
        printf("Columna (Y): ");
        scanf_s("%d", &columna);

        if (fila < 0 || fila >= TAM || columna < 0 || columna >= TAM) {
            printf("Ese punto esta fuera del mapa.\n\n");
            continue;
        }

        intentos++;

        if (mapa[fila][columna] == '#') {
            printf("¡Tocado!\n");
            mapa[fila][columna] = 'X';
            navesRestantes--;
        }
        else if (mapa[fila][columna] == '.') {
            printf("Agua\n");
            mapa[fila][columna] = 'O';
        }
        else {
            printf("Ya habias disparado ahi.\n");
        }

        printf("Partes de nave restantes: %d\n\n", navesRestantes);
    }

    printf("Has destruido todas las naves en %d intentos!\n", intentos);

    // Mostrar el mapa completo
    printf("\nMapa completo (revelado):\n");
    printf("    ");
    for (int j = 0; j < TAM; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
    return 0;
}