#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <ctime>
using namespace std;

//Clase Libro
class Libro
{
private:
    int paginas;
    //
    string p2,op1;
    int op,hora;
    //
    string nombre;
    string titulo;
    string autor;
    string genero;
public:
    Libro(string,string,string,string,int);
    void Ingresar();
    void Imprime();
    void Menu();
    void Actualizar();
    void Recuperar();
};

//Variables de ingreso
Libro::Libro(string nombre, string titulo, string autor, string genero, int paginas)
{
    // punteros
    this->nombre=nombre;
    this->titulo=titulo;
    this->autor=autor;
    this->genero=genero;
    this->paginas=paginas;
}

//metodo ingresar
void Libro::Ingresar()
{
    cout<<"---BIENVENIDO(A) AL REGISTRO---"<<endl;
    cout<<"Ingresa tu nombre: ";
    cin >> nombre;
    cout<<"Ingresa el titulo del libro: ";
    cin >> titulo;
    cout<<"Ingresa el autor del libro: ";
    cin >> autor;
    cout<<"Ingresa el genero del libro: ";
    cin >> genero;
    cout<<"Ingresa el numero de paginas: ";
    cin>> paginas;
}

//metodo imprime
void Libro::Imprime()
{
    cout<<"---DATOS INGRESADOS---"<<endl;
    cout<<"Hola "<<nombre<<" :"<<endl;
    cout<<"El libro ingresado es: "<<titulo<<endl;
    cout<<"El autor del libro "<<"*"<<titulo<<"*"<<" es: "<<autor<<endl;
    cout<<"El genero del libro es: "<<genero<<endl;
    cout<<"El numero de paginas del libro es: "<<paginas<<endl;

}

//menu
void Libro::Menu()
{
    cout<<"---MENU DE OPERACIONES---"<<endl;
    op=0;

}


//metodo actualizar
void Libro::Actualizar()
{
    cout<<"---INGRESE LOS DATOS PARA ACTUALIZAR---"<<endl;
    
    cout<<"Ingresa el titulo del libro: ";
    cin >> titulo;
    cout<<"Ingresa el autor del libro: ";
    cin >> autor;
    cout<<"Ingresa el genero del libro: ";
    cin >> genero;
    cout<<"Ingresa el numero de paginas: ";
    cin>> paginas;

    cout<<"---LOS DATOS FUERON GUARDADOS EXITOSAMENTE---";
    
}


//metodo recuperar informacion
void Libro::Recuperar()
{
    cout<<"---INFORMACION ACTUALIZADA---"<<endl;
    cout<<"Tu libro ingresado es: "<<titulo<<endl;
    cout<<"El autor del libro "<<"*"<<titulo<<"*"<<" es: "<<autor<<endl;
    cout<<"El genero del libro es: "<<genero<<endl;
    cout<<"El numero de paginas del libro es: "<<paginas<<endl;
   
}


//Main
int main()
{
    
    Libro Libro1("","","","",0);
    
    //
    string p2,op1;
    int op,hora;
 
    Libro1.Ingresar(); //ingresar
    cout<<"------------------------------------------------------------"<<endl;
    
    Libro1.Imprime(); //imprimir
    cout<<"------------------------------------------------------------"<<endl;
   
    Libro1.Menu(); //menu 

    while(op!=3)
    { 
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Que operacion desea realizar? "<<endl; 
        cout<<"1.Actualizar información del libro "<<endl;
        cout<<"2.Recuperar información ingresada "<<endl;
        cout<<"3.Salir"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            Libro1.Actualizar(); //Actualizar        
            break;
        case 2:
            Libro1.Recuperar(); //recuperar
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
