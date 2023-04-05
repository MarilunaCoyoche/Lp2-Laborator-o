//Crear una clase de estudiantes: Los estudiantes pueden crear una clase de
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Estudiante {
    private:
        string nombre;
        int edad;
        int grado;
        int calificacion;
    
    public:
        Estudiante(string n, int e, int g) {
            nombre = n;
            edad = e;
            grado = g;
            calificacion = 0;
        }
        
        void tomarExamen(int calif) {
            calificacion = calif;
        }
        
        void mostrarDatos() {
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Grado: " << grado << endl;
            cout << "Calificación: " << calificacion << endl;
        }
};

int main() {
    int numEstudiantes;
    cout << "Ingrese el número de estudiantes: ";
    cin >> numEstudiantes;
    
    vector<Estudiante> estudiantes;
    
    for (int i = 0; i < numEstudiantes; i++) {
        string nombre;
        int edad, grado;
        cout << "Ingrese el nombre del estudiante #" << i+1 << ": ";
        cin >> nombre;
        cout << "Ingrese la edad del estudiante #" << i+1 << ": ";
        cin >> edad;
        cout << "Ingrese el grado del estudiante #" << i+1 << ": ";
        cin >> grado;
        
        Estudiante e(nombre, edad, grado);
        estudiantes.push_back(e);
    }
    
    for (int i = 0; i < estudiantes.size(); i++) {
        int calif;
        cout << "Ingrese la calificación del estudiante #" << i+1 << ": ";
        cin >> calif;
        estudiantes[i].tomarExamen(calif);
    }
    
    cout << "Datos de los estudiantes:" << endl;
    for (int i = 0; i < estudiantes.size(); i++) {
        estudiantes[i].mostrarDatos();
        cout << endl;
    }
    
    return 0;
}