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

// Función para agregar materia con manejo de errores
int agregarMateria(struct Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
        return 0; // Éxito
    } else {
        fprintf(stderr, "Error: No se pudo agregar la materia. Límite alcanzado.\n");
        return -1;
    }
}

// Función para eliminar materia evitando código repetido
void eliminarMateria(struct Estudiante* estudiante, const char* materia) {
    int i;
    for (i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            return;
        }
    }

    fprintf(stderr, "Error: La materia no está inscrita.\n");
}

// Otras funciones...

int main() {
    struct Estudiante* estudiante1 = crearEstudiante("Rodrigo", 18, 9.5);
    if (estudiante1 != NULL) {
        mostrarEstudiante(*estudiante1);

        if (agregarMateria(estudiante1, "Física") == 0) {
            mostrarEstudiante(*estudiante1);

            eliminarMateria(estudiante1, "Historia");

            mostrarEstudiante(*estudiante1);

            // Liberar memoria
            destruirEstudiante(estudiante1);
        } else {
            fprintf(stderr, "Error: no se pudo agregar la materia.\n");
        }
    } else {
        fprintf(stderr, "Error: no se pudo crear el estudiante.\n");
    }

    return 0;
}
