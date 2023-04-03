#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Qué métodos son necesarios para vender y agregar productos a las tiendas?
//Cómo se pueden crear diferentes objetos para representar diferentes tiendas?
class Tienda
{
private:
    int cantidaddeproductos;
    string p2,op1;
    int i1,i4,i5;
    list<string> productos;
    string nombre;
    string dirección;
    string tipodetienda;
    list<string> carrito;
public:
    Tienda(string, string,string, list<string>,int,list<string> );
    void myInput();
    void myPrint();
    void AgregarP();
    void Vender();
};
Tienda::Tienda(string nombre , string dirección, string tipodetienda,list<string>productos, int cantidaddeproductos, list<string> carrito)
{
    this->nombre = nombre;
    this->dirección = dirección;
    this->tipodetienda=tipodetienda;
    this->productos=productos;
    this->cantidaddeproductos=cantidaddeproductos;
    this->carrito=carrito;
}
void Tienda::myInput()
{
    cout<<"Ingresar nombre de la tienda: ";
    cin >> nombre;
    cout<<"Ingresar direccion de la tienda: ";
    cin >> dirección;
    cout<<"Ingresar tipo de tienda: ";
    cin >> tipodetienda;
    cout<<"Ingresar cantidad de productos: ";
    cin>> cantidaddeproductos;
}
void Tienda::myPrint()
{
    cout<<"Nombre de la tienda: "<<nombre<<endl;
    cout<<"Dirección de la tienda: "<<dirección<<endl;
    cout<<"Tipo de tienda: "<<tipodetienda<<endl;
    cout<<"Cantidad de productos: "<<cantidaddeproductos<<endl;
    cout<<"Los productos son: ";
    while( !productos.empty() )
    {
        p2 = productos.front();
        cout << setw(10) << p2 << endl;
        productos.pop_front();
    }
    
}
void Tienda::AgregarP()
{
    cout<<cantidaddeproductos<<endl;
    for(int i=0; i<cantidaddeproductos; i++)
    {
        cout<<"Ingresar productos: ";
        cin>>p2;
        productos.push_back(p2);
    }
    
}
void Tienda::Vender()
{
    cout<<"Bienvenido Cliente a la tienda "<<nombre<<endl;
    i1=0;
    while(i1!=10)
    { 
        cout<<"Que desea hacer?"<<endl;
        cout<<"1.Ver productos"<<endl;
        cout<<"2.Ver mi carrito"<<endl;
        cout<<"10.Salir"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>i1;
        switch(i1)
        {
        case 1:
            cout<<"Nuestros productos son: ";
            i4=-1;
            for (auto const &i3: productos) 
                {
                    std::cout << i3 << std::endl;
                    i4=i4+1;
                    if (i4!=0 )
                    {
                        cout<<"Desea comprarlo?(Ingresar SI para comprarlo)";
                        cin>>op1;
                        if (op1=="SI" or op1=="si" or op1=="Si" or op1=="sI")
                        {
                            carrito.push_back(i3);
                            cout<<"Gracias por su compra"<<endl;
                        }
                        else
                        {
                            cout<<"";
                        }
                    }
                    
                } 
            break;
        case 2:
            for (auto const &i5: carrito) 
                {
                    std::cout << i5 << std::endl;
                }
            break;
        case 10:
            break;
        default:
            cout<<"No ingreso ninguna opcion";
        }
    }
}
int main()
{
    Tienda Tienda1("","","",{""},0,{""});
    Tienda1.myInput();
    cout<<"---------------"<<endl;
    Tienda1.AgregarP();
    cout<<"---------------"<<endl;
    Tienda1.Vender();
    return 0;
}