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

void mostrarEstudiante(struct Estudiante estudiante);
void agregarMateria(struct Estudiante* estudiante, const char* materia);
void eliminarMateria(struct Estudiante* estudiante, const char* materia);
void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado);
void mostrarAsistencias(struct Estudiante estudiante);

int main() {
    struct Estudiante estudiante1 = {"Rodrigo", 18, 9.5, {"Matematicas", "Programación", "Historia"}, 3, {}, 0};

    mostrarEstudiante(estudiante1);

    agregarMateria(&estudiante1, "Fisica");

    mostrarEstudiante(estudiante1);

    registrarAsistencia(&estudiante1, "2023-12-17", "Matematicas", "asistió");

    mostrarAsistencias(estudiante1);

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
        printf("No se pueden agregar más materias.\n");
    }
}

void eliminarMateria(struct Estudiante* estudiante, const char* materia) {
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            return;
        }
    }

    printf("La materia no está inscrita.\n");
}

void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    if (estudiante->numAsistencias < MAX_ASISTENCIAS) {
        struct Asistencia nuevaAsistencia;
        strcpy(nuevaAsistencia.fecha, fecha);
        strcpy(nuevaAsistencia.materia, materia);
        strcpy(nuevaAsistencia.estado, estado);
        estudiante->asistencias[estudiante->numAsistencias] = nuevaAsistencia;
        estudiante->numAsistencias++;
    } else {
        printf("No se pueden registrar más asistencias.\n");
    }
}

void mostrarAsistencias(struct Estudiante estudiante) {
    printf("Asistencias registradas:\n");
    for (int i = 0; i < estudiante.numAsistencias; i++) {
        printf("Fecha: %s, Materia: %s, Estado: %s\n", estudiante.asistencias[i].fecha,
               estudiante.asistencias[i].materia, estudiante.asistencias[i].estado);
    }
}
