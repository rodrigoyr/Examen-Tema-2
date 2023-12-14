#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIAS 10
#define MAX_ASISTENCIAS 50

struct Asistencia {
    char fecha[20];
    char materia[50];
    char estado[10]; // "asistió", "falta", "tardanza"
};

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][50];
    int numMaterias;
    struct Asistencia asistencias[MAX_ASISTENCIAS];
    int numAsistencias;
};

int agregarMateria(struct Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
        return 0; // Éxito
    } else {
        return -1;
    }
}

void eliminarMateria(struct Estudiante* estudiante, const char* materia) {
    int i, j;

    for (i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            for (j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            return;
        }
    }

    printf("La materia no está inscrita.\n");
}

struct Estudiante* crearEstudiante(const char* nombre, int edad, float promedio) {
    struct Estudiante* estudiante = malloc(sizeof(struct Estudiante));
    if (estudiante != NULL) {
        strcpy(estudiante->nombre, nombre);
        estudiante->edad = edad;
        estudiante->promedio = promedio;
        estudiante->numMaterias = 0;
        estudiante->numAsistencias = 0;
        return estudiante;
    } else {
        return NULL;
    }
}

void destruirEstudiante(struct Estudiante* estudiante) {
    free(estudiante);
}

void mostrarEstudiante(struct Estudiante estudiante) {
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %.2f\n", estudiante.promedio);

    printf("\nMaterias inscritas:\n");
    if (estudiante.numMaterias > 0) {
        for (int i = 0; i < estudiante.numMaterias; i++) {
            printf("- %s\n", estudiante.materias[i]);
        }
    } else {
        printf("(Ninguna)\n");
    }

    printf("\nAsistencias registradas:\n");
    if (estudiante.numAsistencias > 0) {
        for (int i = 0; i < estudiante.numAsistencias; i++) {
            printf("Fecha: %s, Materia: %s, Estado: %s\n", estudiante.asistencias[i].fecha,
                   estudiante.asistencias[i].materia, estudiante.asistencias[i].estado);
        }
    } else {
        printf("(Ninguna)\n");
    }
}

int main() {
    struct Estudiante* estudiante1 = crearEstudiante("Rodrigo", 18, 9.5);
    if (estudiante1 != NULL) {
        // Simulación de asistencias
        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].fecha, "2023-12-14");
        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].materia, "Fisica");
        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].estado, "asistió");
        estudiante1->numAsistencias++;

        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].fecha, "2023-12-14");
        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].materia, "Programacion");
        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].estado, "falta");
        estudiante1->numAsistencias++;

        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].fecha, "2023-12-14");
        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].materia, "Historia");
        strcpy(estudiante1->asistencias[estudiante1->numAsistencias].estado, "tardanza");
        estudiante1->numAsistencias++;

        mostrarEstudiante(*estudiante1);

        if (agregarMateria(estudiante1, "Fisica") == 0) {
            mostrarEstudiante(*estudiante1);

            eliminarMateria(estudiante1, "Historia");

            mostrarEstudiante(*estudiante1);

            // Liberar memoria
            destruirEstudiante(estudiante1);
        } else {
            printf("Error: no se pudo agregar la materia.\n");
        }
    } else {
        printf("Error: no se pudo crear el estudiante.\n");
    }

    return 0;
}
