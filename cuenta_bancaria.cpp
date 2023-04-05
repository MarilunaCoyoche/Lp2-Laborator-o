#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <algorithm>

using namespace std;

class CuentaBancaria{
    private:
        int cantc,pos,cod,cop;
        int opc,cot,i1,i2,i3,i4,i5,tp,tra,ret=1;
        string nom,ape;
        double sal,sum;
        string bank;
        string city;
        list<string> nom_cuenta;
        list<string> ape_cuenta;
        list<int> pos_cuenta;
        list<int> cod_cuenta;
        list<double> saldo_cuenta;
    
    public:
        CuentaBancaria(string,string,list<string>,list<string>,list<int>,list<int>,list<double>);
        void myInput();
        void Agregar();
        void Menu();
};

CuentaBancaria::CuentaBancaria(string bank,string city,list<string>nom_cuenta,list<string>ape_cuenta,list<int>pos_cuenta,list<int>cod_cuenta,list<double>saldo_cuenta){
    this -> bank = bank;
    this -> city = city;
    this -> nom_cuenta = nom_cuenta;
    this -> ape_cuenta =ape_cuenta;
    this -> pos_cuenta = pos_cuenta;
    this -> cod_cuenta = cod_cuenta;
    this -> saldo_cuenta = saldo_cuenta;
}

void CuentaBancaria::myInput(){
    cout<<"Nombre del Banco: "<<endl;
    cin>>bank;
    cout<<"Ciudad: "<<endl;
    cin>>city;
    cout<<"Ingresar cantidad de cuentas: "<<endl;
    cin>>cantc;
}

void CuentaBancaria::Agregar(){
    srand(time(NULL));
    cout<<cantc<<endl;
    nom_cuenta.pop_front();
    ape_cuenta.pop_front();
    pos_cuenta.pop_front();
    cod_cuenta.pop_front();
    saldo_cuenta.pop_front();
    for (int i=0;i<cantc;i++){
        cout<<"Ingrese nombre del propietario: "<<endl;
        cin>>nom;
        nom_cuenta.push_back(nom);
        cout<<"Ingrese apellido del propietario: "<<endl;
        cin>>ape;
        ape_cuenta.push_back(ape);
        cout<<"Creando postal de tarjeta: "<<endl;
        for (pos=222;pos<=333;pos++){
            pos=pos+rand()%(334-222);
        }
        cout<<"Postal creado: "<<pos<<endl;
        pos_cuenta.push_back(pos);
        cout<<"Creando codigo de tarjeta: "<<endl;
        for (cod=9000;cod<=9999;cod++){
            cod=cod+rand()%(10000-9000);
        }
        cout<<"Codigo creado: "<<cod<<endl;
        cod_cuenta.push_back(cod);
        cout<<"Ingrese saldo inicial: S/.";
        cin>>sal;
        saldo_cuenta.push_back(sal);
    }
}

void CuentaBancaria::Menu(){
    cout<<"Bienvenido al Banco: "<<bank<<endl;
    cout<<"Ciudad: "<<city<<endl;
    opc=0;
    while (opc != 4){
        cout<<"--------------"<<endl;
        cout<<"-----MENU-----"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1.Mostrar Cuentas."<<endl;
        cout<<"2.Recargar saldo."<<endl;
        cout<<"3.Transferencia."<<endl;
        cout<<"4.Salir."<<endl;
        cout<<"Seleccione una opcion: "<<endl;
        cin>>opc;
        if (opc == 1){
            cout<<"Ingrese contrasenia de administrador: "<<endl;
            cin>>cot;
            if (cot == 202203){
                for (auto const &i1: nom_cuenta){
                    std::cout<<ret<<"Nombre del propietario: "<<i1<<std::endl;
                    cout<<endl;
                    ret=ret+1;
                }
                for (auto const &i2: ape_cuenta){
                    std::cout<<ret<<"Apellido del propietario: "<<i2<<std::endl;
                    cout<<endl;
                    ret=ret+1;
                }
                for (auto const &i3: pos_cuenta){
                    std::cout<<ret<<"Postal del propietario: "<<i3<<std::endl;
                    cout<<endl;
                    ret=ret+1;
                }
                for (auto const &i4: cod_cuenta){ 
                    std::cout<<ret<<"Codigo del propietario: "<<i4<<std::endl;
                    cout<<endl;
                    ret=ret+1;
                }
                for (auto const &i5: saldo_cuenta){
                    std::cout<<ret<<"Saldo del propietario: "<<i5<<std::endl;
                    cout<<endl;
                    ret=ret+1;
                }
            } 
            else{
                cout<<"Contrasenia incorrecta."<<endl;
            }
        }
        else if (opc == 2){
            cout << "Ingrese codigo de tarjeta: " << endl;
            cin >> cop;
            for (auto const &i4: cod_cuenta){
                if (cop == i4) {
                    cout << "Ingrese monto a sumar: " << endl;
                    cin >> sum;
                    sal=sal+sum;
                    saldo_cuenta.pop_front();
                    saldo_cuenta.push_back(sal);
                } 
                else {
                    cout << "Codigo incorrecto." << endl;
                }
            }
        }
        else if (opc == 3){
            cout << "Ingrese codigo de tarjeta: " << endl;
            cin >> cop;
            for (auto const &i4: cod_cuenta){
                if (cop == i4) {
                    cout<<"Ingrese monto a transferir: "<<endl;
                    cin>>tra;
                    sal=sal-tra;
                    saldo_cuenta.pop_front();
                    saldo_cuenta.push_back(sal);
                    cout<<"Ingrese postal de la cuenta a transferir: "<<endl;
                    cin>>tp;
                    for (auto const &i3: pos_cuenta){
                        if(tp == i3){
                            cout<<"Cuenta encontrada."<<endl;
                            sal=sal+tra;
                            saldo_cuenta.pop_front();
                            saldo_cuenta.push_back(sal);
                            cout<<"..."<<endl;
                            cout<<"Transferencia."<<endl;
                        }
                        else{
                            cout<<"Cuenta incorrecta"<<endl;
                        }
                    }
                } 
                else {
                    cout << "Codigo incorrecto." << endl;
                }
            }
        }
        else if(opc == 4){
            cout<<"Hasta luego."<<endl;
        }
    }
}

int main(void){
    CuentaBancaria CB("","",{""},{""},{0},{0},{0.0});
    CB.myInput();
    cout<<"_________________________"<<endl;
    CB.Agregar();
    cout<<"_________________________"<<endl;
    CB.Menu();
    return 0;
}
//ahora son 189