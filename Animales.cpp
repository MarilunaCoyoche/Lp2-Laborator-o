#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <ctime>
using namespace std;
//Mariluna Coyoche
//Clase Animales
class Animales
{
private:
    int edad;
    //
    string p2,op1;
    int op,son,hora;
    //
    string especie;
    string nombre;
    string sexo;
public:
    Animales(string,string,string,int);
    void Ingresar();
    void Imprime();
    void Menu();
};

//Variables de ingreso
Animales::Animales(string especie, string nombre, string sexo, int edad)
{
    this->especie=especie;
    this->nombre=nombre;
    this->sexo=sexo;
    this->edad=edad;
}

//ingresar
void Animales::Ingresar()
{
    cout<<"Ingresar especie del animal: ";
    cin >> especie;
    cout<<"Ingresar nombre del animal: ";
    cin >> nombre;
    cout<<"Ingresar el sexo del animal: ";
    cin >> sexo;
    cout<<"Ingresar edad del animal: ";
    cin>> edad;
}

//imprime
void Animales::Imprime()
{
    cout<<"---DATOS DEL ANIMAL INGRESADO---"<<endl;
    cout<<"La especie del animal es: "<<especie<<endl;
    cout<<"El nombre del animal es: "<<nombre<<endl;
    cout<<"El sexo del animal es: "<<sexo<<endl;
    cout<<"La edad del animal es: "<<edad<<" años"<<endl;

}
    
//menu
void Animales::Menu()
{
    cout<<"---BIENVENIDO AL ASISTENTE DE ANIMALES---"<<endl;
    op=0;
    while(op!=3)
    { 
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Que necesita el "<<nombre<<"?"<<endl; 
        cout<<"1.Alimentar al "<<nombre<<endl;
        cout<<"2.Escuchar el sonido que hace el "<<nombre<<endl;
        cout<<"3.Salir"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            cout<<"Se le dió de comer al "<<nombre<<endl;
            cout<<"Ingresar hora actual: ";
            cin>>hora;
            cout<<"La hora registrada es: "<<hora<<" hrs"<<endl; 
            break;
        case 2:
            cout<<"---MENU DE SONIDOS------------------------"<<endl;
            cout<<"Elige la opción con tu animal registrado: "<<endl;
            son=0;
            while(son!=8)
            { 
                cout<<"1.Perro "<<endl;
                cout<<"2.Gato "<<endl;
                cout<<"3.Cerdo "<<endl;
                cout<<"4.Pollito "<<endl;
                cout<<"5.Vaca "<<endl;
                cout<<"6.Oso "<<endl;
                cout<<"7.OTRO "<<endl;
                cout<<"8.SALIR AL MENU PRINCIPAL "<<endl;

                cout<<"Ingresar opcion: ";
                cin>>son;
                switch(son)
                {
                case 1:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Guau!!! "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                case 2:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Miau!!! "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                case 3:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Oinck!!! "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                case 4:
                    
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Piopio!!! "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                case 5:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Mu!!! "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                case 6:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Garrrr!!! "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                case 7:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"Sonido no encontrado"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                case 8:
                    break;
                }
            }
            break;
        case 3:
            break;

        }
    }

}

//Main
int main()
{
    Animales Animales1("","","",0);
    Animales1.Ingresar(); //ingresar
    cout<<"------------------------------------------------------------"<<endl;
    
    Animales1.Imprime(); //imprimir
    cout<<"------------------------------------------------------------"<<endl;
   
    Animales1.Menu(); //menu 
    
    //hora
    cout<<"Hora y fecha - fin del registro:"<<endl;
    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);
    
    return 0;
 
}
