#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Asistencia {
    string fecha;
    string materia;
    string estado; // "asistio", "falta", "tardanza"
};

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<string> materias;
    vector<Asistencia> asistencias; // Lista de asistencias
};

void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;

    cout << "Materias inscritas:" << endl;
    for (const auto& materia : estudiante.materias) {
        cout << "- " << materia << endl;
    }

    cout << "Asistencias registradas:" << endl;
    for (const auto& asistencia : estudiante.asistencias) {
        cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << endl;
    }
}

void agregarMateria(Estudiante& estudiante, const string& materia) {
    estudiante.materias.push_back(materia);
}

void eliminarMateria(Estudiante& estudiante, const string& materia) {
    estudiante.materias.erase(remove(estudiante.materias.begin(), estudiante.materias.end(), materia), estudiante.materias.end());
}

void registrarAsistencia(Estudiante& estudiante, const string& fecha, const string& materia, const string& estado) {
    Asistencia asistencia;
    asistencia.fecha = fecha;
    asistencia.materia = materia;
    asistencia.estado = estado;
    estudiante.asistencias.push_back(asistencia);
}

int main() {
    Estudiante estudiante1;

    estudiante1.nombre = "Juan Perez";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    agregarMateria(estudiante1, "Latin");
    agregarMateria(estudiante1, "Programacion");
    agregarMateria(estudiante1, "Historia");

    mostrarEstudiante(estudiante1);

    registrarAsistencia(estudiante1, "2023-12-15", "Latin", "asistio");
    registrarAsistencia(estudiante1, "2023-12-16", "Programacion", "falta");
    registrarAsistencia(estudiante1, "2023-12-17", "Historia", "retraso");

    mostrarEstudiante(estudiante1);

    return 0;
}
