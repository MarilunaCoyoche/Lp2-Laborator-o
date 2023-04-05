#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <algorithm>

using namespace std;

class Avion{
    private:
        int cantA=0;
        string av="";
        double velI=0.0,velF=0.0,timea=0.0,ma=0.0,presa=0.0;
        list<string> lav;
        list<double> codvi;
        list<double> codvf;
        list<double> codta;
        list<double> codma;
        list<double> codpa;
    public:
        Avion(list<string>,list<double>,list<double>,list<double>,list<double>,list<double>);
        void myInput();
        void AgregarA();
};

Avion::Avion(list<string>lav,list<double>codvi,list<double>codvf,list<double>codta,list<double>codma,list<double>codpa){
    this -> lav = lav;
    this -> codvi = codvi;
    this -> codvf = codvf;
    this -> codta = codta;
    this -> codma = codma;
    this -> codpa = codpa;
}

void Avion::myInput(){
    cout<<"Ingrese cuantos aviones existen en el escuadron: ";
    cin>>cantA;
}

void Avion::AgregarA(){
    cout<<"El numero de aviones en el escuadron es: "<<cantA<<endl;
    lav.pop_front();
    codvi.pop_front();
    codvf.pop_front();
    codta.pop_front();
    codma.pop_front();
    codpa.pop_front();
    for (int p=0;p<cantA;p++){
        cout<<"Ingrese code_name del avion: ";
        cin>>av;
        lav.push_back(av);
        cout<<"Ingrese metros de altitud del avion: ";
        cin>>ma;
        cout<<"Ingrese velocidad inicial y velocidad final del avion: ";
        cin>>velI;
        cin>>velF;
        cout<<"Ingrese tiempo de vuelo del avion: ";
        cin>>timea;
        cout<<"Ingrese precision del avion: ";
        cin>>presa;
        codvi.push_back(ma);
        codvf.push_back(velI);
        codta.push_back(velF);
        codma.push_back(timea);
        codpa.push_back(presa);
    }
}

class Mision{
    private:
        int opc,i1,i2,i3,i4,i5,i6,i11,i12,i13,i14,i15,i16,rema=0,rema1=0;
        string nom;
        string obj;
        double time;
        double m,velm,velx,pres;
        list<string> lobj;
        list<double> condm;
        list<double> condvm;
        list<double> condvx;
        list<double> condps;
        list<double> condt;
    public:
        Mision(list<string>,list<double>,list<double>,list<double>,list<double>,list<double>);
        void menu();
};

Mision::Mision(list<string>lobj,list<double>condm,list<double>condvm,list<double>condvx,list<double>condps,list<double>condt){
    this -> lobj = lobj;
    this -> condm = condm;
    this -> condvm = condvm;
    this -> condvx = condvx;
    this -> condps = condps;
    this -> condt = condt;
}

void Mision::menu(){
    Avion avion({""},{0.0},{0.0},{0.0},{0.0},{0.0});
    list<string> lav;
    list<double> codvi;
    list<double> codvf;
    list<double> codta;
    list<double> codma;
    list<double> codpa;
    int cantA=0;
    while(opc !=3){
        cout<<"__________________________"<<endl;
        cout<<"------------------"<<endl;
        cout<<"-------MENU-------"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Ver mision."<<endl;
        cout<<"2.Agregar aviones"<<endl;
        cout<<"3.Ver resultados"<<endl;
        cout<<"4.Salir"<<endl;
        cout<<"__________________________"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc;
        if (opc == 1){
            for(auto const &i1: lobj){
                std::cout<<"Mision: "<<i1<<std::endl;
            }
            for(auto const &i2: condm){
                std::cout<<"Metros de altitud: "<<i2<<std::endl;
            }
            for(auto const &i3: condvm){
                std::cout<<"Velocidad minima: "<<i3<<"km/h"<<std::endl;
            }
            for(auto const &i4: condvx){
                std::cout<<"Velocidad maxima: "<<i4<<"km/h"<<std::endl;
            }
            for(auto const &i5: condps){
                std::cout<<"Precision: "<<i5<<"%"<<std::endl;
            }
            for(auto const &i6: condt){
                std::cout<<"Tiempo de mision: "<<i6<<" minutos"<<std::endl;
            }
        }
        else if (opc == 2){
            cout<<"__________________________"<<endl;
            avion.myInput();
            cout<<"__________________________"<<endl;
            avion.AgregarA();
            cout<<"__________________________"<<endl;
        }
        else if (opc == 3){
            for (auto const &i1: lobj){
                std::cout<<"Mision: "<<i1<<std::endl;
                for (auto const &i11: lav){
                    std::cout<<"avion: "<<i11<<std::endl;
                }
                for (auto const &i2: condm){
                    for (auto const &i12: codma){
                        if (i12 == i2){
                            rema=rema+1;
                        }
                    }
                }
                for(auto const &i3: condvm){
                    for(auto const &i13: codvi){
                        if (i13 >= i3 && i13<=3000){
                            rema=rema+1;
                        }
                    }
                }
                for(auto const &i5: condps){
                    for(auto const &i15: codpa){
                        if (i15>= i5){
                            rema=rema+1;
                        }
                    }
                }
                for(auto const &i6: condt){
                    for(auto const &i16: codta){
                        if (i16<=i6){
                            rema=rema+1;
                        }
                    }
                }
                if (rema == 4){
                    cout<<"mision exitosa."<<endl;
                    rema1=rema1+1;
                }
                else{
                    cout<<"mision fallida."<<endl;
                }
            }
            if (rema1 == cantA){
                cout<<"Exito rotundo."<<endl;
            }
            else if(rema1 > 0 && rema1 < cantA){
                cout<<"Exito moderado."<<endl;
            }
            else{
                cout<<"Mision fallida."<<endl;
            }
        }
        else if(opc == 4){
            cout<<"Cerrando mision"<<endl;
            break;
        }
        else{
            cout<<"Opcion invalida."<<endl;
        }
    }
    
}

int main(void){
    int opc1;
    Mision mision1({"Iceman"},{500},{1000.0},{3000.0},{50.0},{5.0});
    Mision mision2({"Goose"},{340},{2300.0},{3000.0},{75.0},{4.0});
    Mision mision3({"Maverick"},{204},{2980.0},{3000.0},{100.0},{3.0});
    while(opc1 !=4){
        cout<<"__________________________"<<endl;
        cout<<"Bienvenido al simulador de exito."<<endl;
        cout<<"__________________________"<<endl;
        cout<<"------------------"<<endl;
        cout<<"-------MENU-------"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Mision uno."<<endl;
        cout<<"2.Mision dos."<<endl;
        cout<<"3.Mision tres."<<endl;
        cout<<"4.Salir"<<endl;
        cout<<"__________________________"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc1;
        if (opc1 == 1){
            cout<<"__________________________"<<endl;
            mision1.menu();
            cout<<"__________________________"<<endl;
        }
        else if (opc1 == 2){
            cout<<"__________________________"<<endl;
            mision2.menu();
            cout<<"__________________________"<<endl;
        }
        else if (opc1 == 3){
            cout<<"__________________________"<<endl;
            mision3.menu();
            cout<<"__________________________"<<endl;
        }
        else if (opc1 == 4){
            cout<<"Muchas gracias por jugar."<<endl;
            cout<<"__________________________"<<endl;
            break;
        }
        else{
            cout<<"Opcion no valida, intente otra vez."<<endl;
        }
    }
    return 0;
}