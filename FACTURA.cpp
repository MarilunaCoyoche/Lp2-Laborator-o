#include <string>
#include <iostream>
using namespace std;
class Factura
{
private:
    int numF;
    string fecha;
    int monto;
public:
    Factura(int numF , string fecha, int monto)
    {
        this->numF = numF;
        this-> fecha=fecha;
        this->monto=monto;
    }
    void setNumeroFactura()
    {
        this->numF=numF;
        cout<<"Ingrese el numero de factura: ";
        cin>>numF;  
    }
    int getNumeroFactura()
    {
        return numF;
    }
    void setFecha()
    {
        this->fecha=fecha;
        cout<<"Ingrese la fecha Ejem(04/04/2023): ";
        cin>>fecha;
    }
    string getFecha()
    {
        return fecha;
    }
    void setMonto()
    {
        this->monto=monto;
        cout<<"Ingrese el monto: "<<endl;
        cout<<"S/ ";
        cin>>monto;
    }
    double getMonto()
    {
        return monto;
    }
    void imprimirFactura() {
        cout<<">>==========FACTURA==========<<"<<endl;
        cout << "Factura #" << numF << endl;
        cout << "Fecha de emision: " << fecha << endl;
        cout << "Monto: S/. " << monto << endl;
    }
};
int main()
{
    Factura factura1(12345, "05/04/2023", 500.50);
    Factura factura2(0, " ", 0);
    factura1.imprimirFactura();
    cout << endl;
    factura2.imprimirFactura();
    return 0;
}