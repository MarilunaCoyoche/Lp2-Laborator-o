/* Crea una clase "Carrera" y la clase “Auto” que permita a los jugadores competir
contra la computadora. La clase debe tener atributos como la distancia total de la carrera y la
dificultad del oponente de la computadora. Los estudiantes deben crear métodos para simular la
carrera y determinar el ganador */
#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <ctime>
using namespace std;

//Clase Auto

class Auto 
{
private:
    string nombre;
    int velocidad_maxima;
    int distancia_recorrida;
    int velocidad_actual;
public:
    Auto(string nombre, int velocidad_maxima) : nombre(nombre), velocidad_maxima(velocidad_maxima) {
        distancia_recorrida = 0;
        velocidad_actual = 0;
    }

    void acelerar() {
        velocidad_actual += rand() % 10 + 1; // Incrementa la velocidad de manera aleatoria
        if (velocidad_actual > velocidad_maxima) {
            velocidad_actual = velocidad_maxima; // No se puede superar la velocidad máxima
        }
        distancia_recorrida += velocidad_actual; // Incrementa la distancia recorrida
    }

    int getDistanciaRecorrida() {
        return distancia_recorrida;
    }

    string getNombre() {
        return nombre;
    }

};


//Clase carrera


class Carrera 
{
private:
    int distancia_total;
    int dificultad_oponente;
public:
    Carrera(int distancia_total, int dificultad_oponente) : distancia_total(distancia_total), dificultad_oponente(dificultad_oponente) {
        srand(time(nullptr)); // Inicializa el generador de números aleatorios
    }

    void iniciar() {
        Auto jugador("Jugador", rand() % 10 + 1); // Velocidad máxima del jugador aleatoria entre 1 y 10
        Auto computadora("Computadora", rand() % dificultad_oponente + 1); // Velocidad máxima de la computadora aleatoria entre 1 y la dificultad elegida
        cout<<"-----------------------------------------------------"<<endl;
        cout << "COMIENZA LA CARRERA DE: " << distancia_total << " METROS!" << endl;
        while (jugador.getDistanciaRecorrida() < distancia_total && computadora.getDistanciaRecorrida() < distancia_total) {
            jugador.acelerar();
            computadora.acelerar();
            cout<<"-----------------------------------------------------"<<endl;
            cout << jugador.getNombre() << " ha recorrido " << jugador.getDistanciaRecorrida() << " metros." << endl;
            cout << computadora.getNombre() << " ha recorrido " << computadora.getDistanciaRecorrida() << " metros." << endl;
            cout<<"-----------------------------------------------------"<<endl;
        }
        if (jugador.getDistanciaRecorrida() >= distancia_total && computadora.getDistanciaRecorrida() >= distancia_total) {
            cout<<"-----------------------------------------------------"<<endl;
            cout << "EMPATEEE!" << endl;
        }
        else if (jugador.getDistanciaRecorrida() >= distancia_total) {
            cout<<"-----------------------------------------------------"<<endl;
            cout << "EL JUGADOR ES EL GANADOR" << endl;
        }
        else {
            cout<<"-----------------------------------------------------"<<endl;
            cout << "LA COMPUTADORA ES LA GANADORA" << endl;
        }
    }


};



//MAIN

int main() {
    Carrera carrera(100, 5); // Carrera de 100 metros con dificultad de la computadora en 5
    carrera.iniciar();
    
    //hora
    
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"HORA Y FECHA REGISTRADOS - FIN DE LA CARRERA:"<<endl;
    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);
    
    
    return 0;
}
