#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class MateriaNoEncontradaException : public exception {
public:
    const char* what() const throw() {
        return "Error: La materia no se encuentra en la lista.";
    }
};

class AsistenciaDuplicadaException : public exception {
public:
    const char* what() const throw() {
        return "Error: Ya se registró asistencia para esta fecha y materia.";
    }
};

struct Asistencia {
    string fecha;
    string materia;
    string estado; // "asistió", "falta", "tardanza"
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
    estudiante.materias.erase(estudiante.materias.begin());
}

void registrarAsistencia(Estudiante& estudiante, const string& fecha, const string& materia, const string& estado) {
    auto duplicado = find_if(estudiante.asistencias.begin(), estudiante.asistencias.end(),
                             [&fecha, &materia](const Asistencia& a) { return a.fecha == fecha && a.materia == materia; });

    Asistencia asistencia;
    asistencia.fecha = fecha;
    asistencia.materia = materia;
    asistencia.estado = estado;
    estudiante.asistencias.push_back(asistencia);
}

int main() {
    Estudiante estudiante1;

    try {
        estudiante1.nombre = "Juan Perez";
        estudiante1.edad = 20;
        estudiante1.promedio = 8.5;

        agregarMateria(estudiante1, "Latin");
        agregarMateria(estudiante1, "Programacion");
        agregarMateria(estudiante1, "Historia");

        mostrarEstudiante(estudiante1);

        try {
            eliminarMateria(estudiante1, "Biologia");
        } catch (const MateriaNoEncontradaException& e) {
            cerr << "Error: " << e.what() << endl;
        }

        try {
            registrarAsistencia(estudiante1, "2023-12-17", "Historia", "asistio");
        } catch (const AsistenciaDuplicadaException& e) {
            cerr << "Error: " << e.what() << endl;
        }

        mostrarEstudiante(estudiante1);

    } catch (const exception& e) {
        cerr << "Error general: " << e.what() << endl;
    }

    return 0;
}
