#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 3

void AsignarMapa(char mapa[Size][Size]);
void MostrarMapa(char mapa[Size][Size]);
void Juego(char mapa[Size][Size], int* terminarJuegoJugador, int* terminarJuegoMaquina, int* intentos);
void Comprobacion(char mapa[Size][Size], int* terminarJuegoJugador, int* terminarJuegoMaquina);
void Resultado(int terminarJuegoJugador, int terminarJuegoMaquina, int* ganadas, int* perdidas, int* empates);
int PreguntarContinuar();
void MostrarHistorial(int ganadas, int perdidas, int empates);

int main()
{
    srand(time(NULL));
    char mapa[Size][Size];
    int terminarJuegoMaquina = 0;
    int terminarJuegoJugador = 0;
    int intentos = 9;
    int continuar = 1;
    int ganadas = 0, perdidas = 0, empates = 0;

    printf("3 en raya\n");

    do {
        terminarJuegoMaquina = 0;
        terminarJuegoJugador = 0;
        intentos = 9;

        // Iniciar juego
        AsignarMapa(mapa);
        Juego(mapa, &terminarJuegoJugador, &terminarJuegoMaquina, &intentos);
        Resultado(terminarJuegoJugador, terminarJuegoMaquina, &ganadas, &perdidas, &empates);

        continuar = PreguntarContinuar();

    } while (continuar);

    MostrarHistorial(ganadas, perdidas, empates);
    return 0;
}

void AsignarMapa(char mapa[Size][Size])
{
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            mapa[i][j] = '-';
        }
    }
    printf("\nTablero inicial\n");
    MostrarMapa(mapa);
}

void MostrarMapa(char mapa[Size][Size])
{
    printf("\n");
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            printf(" %c ", mapa[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Juego(char mapa[Size][Size], int* terminarJuegoJugador, int* terminarJuegoMaquina, int* intentos)
{
    int posJugador[2], posMaquina[2];

    while (*intentos > 0 && *terminarJuegoJugador == 0 && *terminarJuegoMaquina == 0)
    {
        // Turno del jugador
        printf("Tu turno (X)\n");

        int movimientoValido = 0;
        do {
            printf("Introduce fila y columna (0-2): ");
            if (scanf_s("%d %d", &posJugador[0], &posJugador[1]) != 2) {
                printf("Entrada invalida. Intenta de nuevo.\n");
                fflush(stdin); //Sirve para limpiar el buffer(Lo he buscado) :)
            }
            else if (posJugador[0] < 0 || posJugador[0] >= Size || posJugador[1] < 0 || posJugador[1] >= Size) {
                printf("Posicion fuera de rango. Usa numeros entre 0 y 2.\n");
            }
            else if (mapa[posJugador[0]][posJugador[1]] != '-') {
                printf("Esa casilla ya esta ocupada. Intenta de nuevo.\n");
            }
            else {
                movimientoValido = 1;  // Entrada válida
            }
        } while (!movimientoValido);

        mapa[posJugador[0]][posJugador[1]] = 'X';
        (*intentos)--;

        MostrarMapa(mapa);
        Comprobacion(mapa, terminarJuegoJugador, terminarJuegoMaquina);
        if (*terminarJuegoJugador == 1 || *intentos == 0) break;

        printf("Turno de la maquina (O)\n");
        do {
            posMaquina[0] = rand() % Size;
            posMaquina[1] = rand() % Size;
        } while (mapa[posMaquina[0]][posMaquina[1]] != '-');

        mapa[posMaquina[0]][posMaquina[1]] = 'O';
        printf("La maquina juega en: [%d][%d]\n", posMaquina[0], posMaquina[1]);
        (*intentos)--;

        MostrarMapa(mapa);
        Comprobacion(mapa, terminarJuegoJugador, terminarJuegoMaquina);
    }
}

void Comprobacion(char mapa[Size][Size], int* terminarJuegoJugador, int* terminarJuegoMaquina)
{
    // Filas
    for (int i = 0; i < Size; i++)
    {
        if (mapa[i][0] == 'X' && mapa[i][1] == 'X' && mapa[i][2] == 'X') {
            *terminarJuegoJugador = 1;
        }
        if (mapa[i][0] == 'O' && mapa[i][1] == 'O' && mapa[i][2] == 'O') {
            *terminarJuegoMaquina = 1;
        }
    }

    // Columnas
    for (int i = 0; i < Size; i++)
    {
        if (mapa[0][i] == 'X' && mapa[1][i] == 'X' && mapa[2][i] == 'X') {
            *terminarJuegoJugador = 1;
        }
        if (mapa[0][i] == 'O' && mapa[1][i] == 'O' && mapa[2][i] == 'O') {
            *terminarJuegoMaquina = 1;
        }
    }

    // Diagonal principal
    if (mapa[0][0] == 'X' && mapa[1][1] == 'X' && mapa[2][2] == 'X') {
        *terminarJuegoJugador = 1;
    }
    if (mapa[0][0] == 'O' && mapa[1][1] == 'O' && mapa[2][2] == 'O') {
        *terminarJuegoMaquina = 1;
    }

    // Diagonal secundaria
    if (mapa[2][0] == 'X' && mapa[1][1] == 'X' && mapa[0][2] == 'X') {
        *terminarJuegoJugador = 1;
    }
    if (mapa[2][0] == 'O' && mapa[1][1] == 'O' && mapa[0][2] == 'O') {
        *terminarJuegoMaquina = 1;
    }
}

void Resultado(int terminarJuegoJugador, int terminarJuegoMaquina, int* ganadas, int* perdidas, int* empates)
{
    printf("\n");
    if (terminarJuegoJugador) {
        printf("Has ganado!\n");
        (*ganadas)++;
    }
    else if (terminarJuegoMaquina) {
        printf("Has perdido\n");
        (*perdidas)++;
    }
    else {
        printf("Empate\n");
        (*empates)++;
    }
    printf("\n");
}

int PreguntarContinuar()
{
    char respuesta;
    printf("Quieres jugar otra partida? (s/n): ");
    scanf_s(" %c", &respuesta, 1);

    fflush(stdin);
    
    system("cls");
    return (respuesta == 's' || respuesta == 'S');
}

void MostrarHistorial(int ganadas, int perdidas, int empates)
{
    printf("\n");
    printf("HISTORIAL DE PARTIDAS\n");
    printf("\n");
    printf("Partidas ganadas:  %d\n", ganadas);
    printf("Partidas perdidas: %d\n", perdidas);
    printf("Empates:           %d\n", empates);
    printf("Total jugadas:     %d\n", ganadas + perdidas + empates);
    printf("\nGracias por jugar!\n");
}