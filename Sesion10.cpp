#include <fstream>
#include <string>
using namespace std;

const int MAX_DATA = 100;

class Producto {
private:
    string nombre;
    int precio, cantidad;

public:
    Producto() {}
    ~Producto() {}
    Producto(string nombre, int precio, int cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }
    void ingresar() {
        cout << "Ingrese producto: ";
        cin >> nombre;
        cout << "Ingrese precio: S/.";
        cin >> precio;
        cout << "Ingrese cantidad: ";
        cin >> cantidad;
    }
    string getNom() { return nombre; }
    int getPre() { return precio; }
    int getCant() { return cantidad; }
};

class Gestor {
private:
    Producto inv[MAX_DATA];
    int num, cap, DNI;
    string usu;

public:
    Gestor() {}
    ~Gestor() {}
    Gestor(string usu, int DNI, int cap) {
        this->usu = usu;
        this->DNI = DNI;
        this->cap = cap;
    }
    void ingresar() {
        cout << "Ingrese nombre: ";
        cin >> usu;
        cout << "Ingrese DNI: ";
        cin >> DNI;
        cout << "Ingrese saldo: S/.";
        cin >> cap;
    }
    void ingresarI() {
        cout << "Ingrese numero de productos a agregar: ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            cout << "Producto [" << i + 1 << "]" << endl;
            inv[i].ingresar();
        }
    }
    void mostrar() {
        for (int i = 0; i < num; i++) {
            cout << "Producto [" << i + 1 << "]" << endl;
            cout << "Producto: " << inv[i].getNom() << endl;
            cout << "Precio: S/." << inv[i].getPre() << endl;
            cout << "Cantidad: " << inv[i].getCant() << endl;
        }
    }
    void informe(int m, int a, int n) {
        cout << "\n=================" << endl;
        cout << "=====INFORME=====" << endl;
        cout << "=================" << endl;
        cout << "Nombre: " << usu << endl;
        cout << "DNI: " << DNI << endl;
        cout << "=================" << endl;
        cout << "Producto: " << inv[m].getNom() << endl;
        cout << "Cantidad: " << a << endl;
        cout << "Precio: S/." << inv[m].getPre() * a << endl;
        cout << "Saldo:  S/." << cap << endl;
        cout << "-----------------------" << endl;
        cout << "Vuelto: " << n << endl;
    }
    void venta() {
        mostrar();
        string pro, es;
        int se, ca, tr;
        cout << "Ingrese nombre del producto: ";
        cin >> pro;
        for (int i = 0; i < num; i++) {
            if (pro == inv[i].getNom()) {
                cout << "Producto [" << i + 1 << "]" << endl;
                cout << "Producto: " << inv[i].getNom() << endl;
                cout << "Precio: S/." << inv[i].getPre() << endl;
                cout << "Cantidad: " << inv[i].getCant() << endl;
                cout << "Desea comprarlo? S/N | ";
                cin >> es;
                if (es == "S" || es == "s") {
                    cout << "Cuantos desea comprar? | ";
                    cin >> se;
                    tr = cap - (inv[i].getPre()*se);
                    if (tr > inv[i].getPre()) {
                        ca = inv[i].getCant() - se;
                        inv[i] = Producto(inv[i].getNom(), inv[i].getPre(), ca);
                        informe(i, se, tr);
                    } else {
                        cout << "No tiene suficiente saldo." << endl;
                    }
                } else {
                    break;
                }
            }
        }
    }

    // Función para escribir los productos en un archivo
    void escribirProductos() {
        ofstream archivo("productos.txt");
        if (archivo.is_open()) {
            archivo << num << endl;
            for (int i = 0; i < num; i++) {
                archivo << inv[i].getNom() << endl;
                archivo << inv[i].getPre() << endl;
                archivo << inv[i].getCant() << endl;
            }
            archivo.close();
            cout << "Datos de productos almacenados en el archivo productos.txt." << endl;
        } else {
            cout << "No se pudo abrir el archivo para escritura." << endl;
        }
    }

    // Función para leer los productos desde un archivo
    void leerProductos() {
        ifstream archivo("productos.txt");
        if (archivo.is_open()) {
            archivo >> num;
            for (int i = 0; i < num; i++) {
                string nombre;
                int precio, cantidad;
                archivo >> nombre;
                archivo >> precio;
                archivo >> cantidad;
                inv[i] = Producto(nombre, precio, cantidad);
            }
            archivo.close();
            cout << "Datos de productos recuperados desde el archivo productos.txt." << endl;
        } else {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
    }
};

int main() {
    Gestor get;
    get.leerProductos(); // Leer productos desde el archivo
    get.ingresar();
    get.ingresarI();
    get.venta();
    get.mostrar();
    get.escribirProductos(); // Escribir productos en el archivo
    return 0;
}
