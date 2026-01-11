#include <stdio.h>
#include <stdlib.h>

struct Libros {
    int id;
    char isbn[14];
    char nombre[100];
    char autor[100];
    int estado;
};

struct Libros PedirDatos();
void LlenarFichero(struct Libros libro);
void LeerLogs();

int main() {
    int cantidad = 0;

    printf("Cuantos libros quieres introducir: ");
    scanf_s(" %d", &cantidad);
    getchar(); // Limpiamos el enter después de la cantidad

    for (int i = 0; i < cantidad; i++) {
        struct Libros libro;
        printf("\n--- Libro %d ---\n", i + 1);
        libro = PedirDatos();
        LlenarFichero(libro);
    }

    printf("\n\n=== REVISANDO ESTADO DE LOS LIBROS ===\n");
    LeerLogs();

    return 0;
}

struct Libros PedirDatos() {
    struct Libros libro;

    printf("ID: ");
    scanf_s("%d", &libro.id);
    getchar();

    printf("ISBN: ");
    gets_s(libro.isbn, 14);

    printf("Nombre: ");
    gets_s(libro.nombre, 100);

    printf("Autor: ");
    gets_s(libro.autor, 100);

    printf("Estado (0=Devuelto, 1=Prestado): ");
    scanf_s("%d", &libro.estado);
    getchar();

    return libro;
}

void LlenarFichero(struct Libros libr) {
    FILE* f;
    if (fopen_s(&f, "Archivos/logs.txt", "a") != 0) {
        printf("Error al abrir el archivo para escribir\n");
        return;
    }

    fprintf(f, "ID: %d | ISBN: %s | Nombre: %s | Autor: %s | Estado: %s\n",
        libr.id, libr.isbn, libr.nombre, libr.autor,
        (libr.estado == 1 ? "PRESTADO" : "DEVUELTO"));

    fclose(f);
}

void LeerLogs() {
    FILE* f;
    char linea[300];

    if (fopen_s(&f, "Archivos/logs.txt", "r") != 0) {
        printf("No se pudo leer el historial.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), f) != NULL) {
        printf("%s", linea);
    }

    fclose(f);
}