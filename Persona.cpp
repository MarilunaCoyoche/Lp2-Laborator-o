//librerias

#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <ctime>
using namespace std;


//definir la clase Persona
class Persona
{
//atributos    
private:
    int edad;
    string nombre;
    string sexo;
    string p2,op1;
    int op,hora;
//metodos
public:
    Persona(int,string,string);
    void Ingresar();
    void Imprime();
    void Menu();
    void Actualizar();
    void Recuperar();

};

//Variables de ingreso con los punteros

Persona::Persona(int edad, string nombre, string sexo)
{
    //punteros
    this->edad=edad;
    this->nombre=nombre;
    this->sexo=sexo;
}


//metodo de ingreso
void Persona::Ingresar()
{
    cout<<"Ingresar su nombre: ";
    cin >> nombre;
    cout<<"Ingresar el genero con el cual se identifica: ";
    cin >> sexo;
    cout<<"Ingresar edad : ";
    cin>> edad;
}


//metodo que imprime
void Persona::Imprime()
{
    cout<<"---DATOS PERSONALES---"<<endl;
    cout<<"Su nombre es: "<<nombre<<endl;
    cout<<"Su genero con el cual se identifica: "<<sexo<<endl;
    cout<<"Su edad es: "<<edad<<" años"<<endl;
    
}


//menu
void Persona::Menu()
{
    cout<<"---MENU DE OPERACIONES---"<<endl;
    op=0;

}




//metodo actualizar
void Persona::Actualizar()
{
    cout<<"---INGRESE LOS DATOS PARA ACTUALIZAR---"<<endl;
    
    cout<<"Ingresar su nombre: ";
    cin >> nombre;
    cout<<"Ingresar el genero con el cual se identifica: ";
    cin >> sexo;
    cout<<"Ingresar edad : ";
    cin>> edad;

    cout<<"---LOS DATOS FUERON GUARDADOS EXITOSAMENTE---";
    
}


//metodo recuperar informacion
void Persona::Recuperar()
{
    cout<<"---INFORMACION ACTUALIZADA---"<<endl;
    cout<<"Su nombre es: "<<nombre<<endl;
    cout<<"Su genero con el cual se identifica: "<<sexo<<endl;
    cout<<"Su edad es: "<<edad<<" años"<<endl;
    
   
}




//Main
int main()
{
    
    Persona Persona1(0,"","");
    //
    string p2,op1;
    int op,hora;
 
    Persona1.Ingresar(); //ingresar
    cout<<"------------------------------------------------------------"<<endl;
    
    Persona1.Imprime(); //imprimir
    cout<<"------------------------------------------------------------"<<endl;
   
    Persona1.Menu(); //menu 

    while(op!=3)
    { 
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Que operacion desea realizar? "<<endl; 
        cout<<"1.Actualizar información del usuario "<<endl;
        cout<<"2.Recuperar información ingresada "<<endl;
        cout<<"3.Salir"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            Persona1.Actualizar(); //Actualizar        
            break;
        case 2:
            Persona1.Recuperar(); //recuperar
            break;
        case 3:
            break;
        }
    }


    
    //hora
    
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Hora y fecha - fin del registro:"<<endl;
    char tt[100];
    time_t now = time(nullptr);
    auto tm_info = localtime(&now);
    strftime(tt, 100, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(tt);
    
    return 0;
 
}
