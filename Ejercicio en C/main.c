#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIAS 10

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][50];
    int numMaterias;
};

void mostrarEstudiante(struct Estudiante estudiante);
void agregarMateria(struct Estudiante* estudiante, const char* materia);
void eliminarMateria(struct Estudiante* estudiante, const char* materia);

int main() {
    struct Estudiante estudiante1 = {"Rodrigo", 18, 9.5, {"Matematicas", "Programacion", "Historia"}, 3};

    mostrarEstudiante(estudiante1);

    agregarMateria(&estudiante1, "Fisica y Quimica");
    mostrarEstudiante(estudiante1);

    eliminarMateria(&estudiante1, "Historia");
    mostrarEstudiante(estudiante1);

    return 0;
}

void mostrarEstudiante(struct Estudiante estudiante) {
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %.2f\n", estudiante.promedio);

    printf("Materias inscritas:\n");
    for (int i = 0; i < estudiante.numMaterias; i++) {
        printf("- %s\n", estudiante.materias[i]);
    }

    printf("\n");
}

void agregarMateria(struct Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
    } else {
        printf("No se pueden añadir mas materias.\n");
    }
}

void eliminarMateria(struct Estudiante* estudiante, const char* materia) {
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            // Mover las materias restantes hacia atrás
            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            return;
        }
    }

    printf("La materia no está inscrita.\n");
}
