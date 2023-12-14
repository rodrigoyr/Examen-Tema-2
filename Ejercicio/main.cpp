#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<string> materias;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;

    cout << "Materias inscritas:" << endl;
    for (const auto& materia : estudiante.materias) {
        cout << "- " << materia << endl;
    }
}

void agregarMateria(Estudiante& estudiante, const string& materia) {
    estudiante.materias.push_back(materia);
}

void eliminarMateria(Estudiante& estudiante, const string& materia) {
    estudiante.materias.erase(remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                                        [&materia](const string& mat) { return mat == materia; }),
                              estudiante.materias.end());
}

int main() {
    Estudiante estudiante1;

    estudiante1.nombre = "Juan Perez";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    agregarMateria(estudiante1, "Matemáticas");
    agregarMateria(estudiante1, "Programación");
    agregarMateria(estudiante1, "Historia");

    mostrarEstudiante(estudiante1);

    eliminarMateria(estudiante1, "Historia");

    mostrarEstudiante(estudiante1);

    return 0;
}
