#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
using namespace std;
class PEDIDO
{
private:
    vector<string> productosDisp;
    vector<string> productosAgot;
    vector<string> Inventario1;
    vector<int> Inventario2;
    vector<string> carrito;
    int Inventario,cantidaddp;
    int p1,p3,p4,p5,p6;
    string p2;
    int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13;
    string op1;
    //factura
    int numF;
    int dia;
    int mes;
    int anio;
    int monto;
public:
    PEDIDO( vector<string>,vector<string>, vector<string>, vector<int>);
    void SET();
    void GET();
    void AgregarP();
    void Actualizar();
    void Pedidos();
    void Facturas();
};
PEDIDO::PEDIDO(vector<string>productosDisp,vector<string>productosAgot, vector<string>Inventario1, vector<int> Inventario2)
{
    this->productosDisp = productosDisp;
    this->productosAgot = productosAgot;
    this->Inventario1=Inventario1;
    this->Inventario2=Inventario2;
}
void PEDIDO::SET()
{
    cout<<"Ingresar cantidad de productos: ";
    cin >> Inventario;
    cantidaddp=Inventario;
}
void PEDIDO::GET()
{
    cout<<"Cantidad de productos: "<<cantidaddp<<endl;
    cout<<"Los productos son: "<<endl;
    for (auto const &p1: Inventario1) 
    {  
        std::cout << p1 << std::endl;
    }
    cout<<"La cantidad de cada producto: "<<endl;
    for (auto const &p4: Inventario2) 
    {    
        std::cout << p4 << std::endl;
    }
    cout<<"Los productos DISPONIBLES son: "<<endl;
    for (auto const &p5: productosDisp) 
    {    
        std::cout << p5 << std::endl;
    }
    cout<<"Los productos AGOTADOS son: "<<endl;
    for (auto const &p6: productosAgot) 
    {
        std::cout << p6 << std::endl;
    }
}
void PEDIDO::AgregarP()
{
    cout<<"Ingresar "<<Inventario<<" productos. "<<endl;
    for(int i=0; i<Inventario; i++)
    {
        cout<<"Ingresar productos: ";
        cin>>p2;
        Inventario1.push_back(p2);
    }
    i5=-1;
    for (auto const &i4: Inventario1) 
        {
            i5=i5+1;
            if (i5!=0 )
            {
                productosDisp.push_back(i4);
            }
        }
    cout<<"-------------"<<endl;
    if (Inventario2[0]==1)
    {
        Inventario1.erase(Inventario1.begin());
        productosDisp.erase(productosDisp.begin());
        Inventario2.erase(Inventario2.begin());
        productosAgot.erase(productosAgot.begin());
        cout<<"Ingresar cantidad de cada producto"<<endl;
                for (auto const &i3: Inventario1) 
                    {
                        std::cout << i3 << std::endl;
                        cout<<"Ingresar cantidad: ";
                        cin>>i2;
                        Inventario2.push_back(i2);
                        cout<<"Se ingreso correctamente."<<endl;
                    }
    }
}
void PEDIDO::Actualizar()
{
    cout<<"..."<<endl;
    for ( i7 = 0; i7 < Inventario; i7++)
    {
        if (Inventario2[i7]==0)
        {
            productosDisp.erase(productosDisp.begin()+i7);
            productosAgot.push_back(Inventario1[i7]);
        }
    }
}
void PEDIDO::Facturas()
{
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    cout<<"Fecha: "<<endl;
    std::cout << std::ctime(&t_c);
    cout<<"Artículos comprados: "<<endl;
    for (auto const &i11: carrito) 
    {
        cout << i11 << endl;
    }
    cout<<"Monto: ";


}
void PEDIDO::Pedidos()
{
    cout<<"Bienvenido Cliente "<<endl;
    i8=0;
    while(i8!=10)
    { 
        Actualizar();
        cout<<"________________"<<endl;
        cout<<"Que desea hacer?"<<endl;
        cout<<"1.Ver productos disponibles"<<endl;
        cout<<"2.Ver productos agotados"<<endl;
        cout<<"3.Ver mi carrito"<<endl;
        cout<<"4.Imprimir factura"<<endl;
        cout<<"10.Salir"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>i8;
        switch(i8)
        {
        case 1:
            cout<<"Los productos son: "<<endl;
                for ( i7 = 0; i7 < Inventario; i7++)
                {
                    cout<<productosDisp[i7]<<endl;
                    cout<<"Desea comprarlo?(Ingresar si para aceptar)";
                    cin>>op1;
                    if (op1=="SI" or op1=="si" or op1=="Si" or op1=="sI")
                    {
                        carrito.push_back(productosDisp[i7]);
                        cout<<"Gracias por su compra"<<endl;
                        Inventario2[i7]=Inventario2[i7]-1;
                        Inventario=productosDisp.size();
                    }
                    else
                    {
                        cout<<"";
                    }
                }
            break;
        case 2:
            cout<<"Los productos agotados son: "<<endl;
            for (auto const &i10: productosAgot) 
                {
                    
                    std::cout << i10 << std::endl;
                }
            break;
        case 3:
            cout<<"Los productos que ha comprado son: "<<endl;
            for (auto const &i9: carrito) 
                {
                    std::cout << i9 << std::endl;
                }
            break;
        case 4:
            cout<<"Su factura es: "<<endl;
            cout<<"----------------"<<endl;
            Facturas();
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
    PEDIDO Pedido1({"1"},{"1"},{"1"},{1});
    Pedido1.SET();
    cout<<"---------------"<<endl;
    Pedido1.AgregarP();
    cout<<"---------------"<<endl;
    Pedido1.Actualizar();
    cout<<"---------------"<<endl;
    Pedido1.Pedidos();
    cout<<"---------------"<<endl;
    Pedido1.GET();
    cout<<"---------------"<<endl;
    return 0;
}
