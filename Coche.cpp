#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;

class Coche{
    double ace,fre;
    public:
        void modelo(string model){
            cout<<"Modelo: "<<model<<endl;
            getch();
        }

        void anio(int anio){
            cout<<"Anio: "<<anio<<endl;
            getch();
        }

        void velocidad(double velI, double velF){
            cout<<"Velocidad Inicial: "<<velI<<"Km/h"<<endl;
            cout<<"Velocidad Final: "<<velF<<"Km/h"<<endl;
            getch();
        }

        void tiempo(double t){
            cout<<"Tiempo de recorrido: "<<t<<" horas"<<endl;
            getch();
        }

        void acelerar(double velI, double velF, double t){
            ace=(velF-velI)/t;
            cout<<"La aceleracion del automovil es: "<<ace<<"km"<<endl;
            getch();
        }

        void frenar(double velI, double velF, double t){
            fre=(pow(velF,2)-pow(velI,2))/2*t;
            cout<<"La distancia del frenado es: "<<fre<<"km"<<endl;
            getch();
        }
};

int main(void){
    int anio,opc;
    string model;
    double velI,velF,t;
    Coche coc;
    cout<<"Ingrese el modelo del automovil: "<<endl;
    cin>>model;
    cout<<"Ingrese el anio del automovil: "<<endl;
    cin>>anio;
    cout<<"Ingrese velocidad inicial en Km/h: "<<endl;
    cin>>velI;
    cout<<"Ingrese velocidad final en Km/h: "<<endl;
    cin>>velF;
    cout<<"Ingrese el tiempo de viaje en horas: "<<endl;
    cin>>t;
    while(opc !=3){
        cout<<"1. Aceleración"<<endl;
        cout<<"2. Distancia de frenado"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese su opcion"<<endl;
        cin>>opc;
        if (opc == 1){
            coc.modelo(model);
            coc.anio(anio);
            coc.velocidad(velI,velF);
            coc.tiempo(t);
            coc.acelerar(velI,velF,t);
        }
        else if (opc == 2){
            coc.modelo(model);
            coc.anio(anio);
            coc.velocidad(velI,velF);
            coc.tiempo(t);
            coc.frenar(velI,velF,t);
        }
        else if (opc == 3){
            cout<<"Hasta luego"<<endl;
        }
    }

    return 0;
}