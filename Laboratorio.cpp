// PracticaLab02-Oct

#include <iostream>
#include <string>

using namespace std;

struct Nodo{

    int cant_pupusas;
    string tip_pupusas;
    string si_coca;
    string ingredientes;
    
    Nodo *sig; 

};

class Orden
{
private:
    
    Nodo *pInicio;

public:

    Orden();
    ~Orden();
    Orden(int, string, string, string);
    
    void insInicio(int, string, string, string);
    void mostrarLista();
  
};

Orden::Orden(void)
{
    pInicio = NULL; 
}

Orden::Orden(int cant_pupusas, string tip_pupusas, string si_coca, string ingredientes){

    pInicio = NULL; 
    insInicio(cant_pupusas, tip_pupusas, si_coca, ingredientes);
}

Orden::~Orden(){

    Nodo *p;
    while (pInicio)
    {
        p = pInicio;
        pInicio = pInicio -> sig;
        delete p;

    }
}

void Orden::insInicio(int c, string tipo, string coca, string ing)
{
    Nodo *nuevo, *saltarin;
    nuevo = new Nodo;

    nuevo -> cant_pupusas = c;
    nuevo ->tip_pupusas = tipo;
    nuevo -> si_coca = coca;
    nuevo -> ingredientes = ing;

    nuevo -> sig = pInicio;
    pInicio = nuevo;
    
}

void Orden::mostrarLista()
{
    cout << ".... DATOS DE SU ORDEN: ...." << endl;
    Nodo *saltarin;
    saltarin = pInicio;
    
    while (saltarin != NULL)
    {
        cout << saltarin -> cant_pupusas << " PUPUSAS DE " << saltarin -> tip_pupusas << "." << endl;
        cout << saltarin -> si_coca << " QUIERE AGREGAR COCA-COLA A SU ORDEN." << endl;
        cout << "LOS INGREDIENTES SERIAN: " << saltarin -> ingredientes << "." << endl;
        saltarin = saltarin -> sig; 

    }
    
}

int menu(){

    int opcion = 0;
    cout << endl;
    cout << "1) CREAR UNA NUEVA ORDEN." << endl;
    cout << "2) MOSTRAR NUEVAMENTE SU ORDEN." << endl;
    cout << "3) TERMINAR." << endl << endl;
    cout << "OPCION: ";
    cin >> opcion; cin.ignore();
    cout << endl;
    return opcion;
}

int main(void)
{
    Orden orden1;

    int nump = 0;
    string tipo = "", coca = "", ingr = "";
    bool continuar = true;

    cout << endl;
    cout << ".... BIENVENIDO AL SERVICIO DE ORDENES ...." << endl << endl;
    cout << "NUESTRAS ESPECIALIDADES SON LAS SIGUIENTES: " << endl << endl;
    cout << "FRIJOL CON QUESO [F/Q], REVUELTAS [R], QUESO [Q], QUESO CON LOROCO [Q/L]" << endl;

    do
    {
        
        switch (menu())
        {
        case 1:
            

            cout << "CANTIDAD DE PUPUSAS: ";
            cin >> nump; cin.ignore();

            cout << "PUPUSAS HECHAS DE: [ARROZ/MAIZ]: ";
            getline(cin,tipo);

            cout << "DESEA ACOMPAÃ‘AR SU ORDEN CON UNA COCACOLA [SI/NO]: " ;
            getline(cin,coca);

            cout << "INGREDIENTES DE SUS PUPUSAS: (REVISE EL MENU): ";
            getline(cin,ingr);

            orden1.insInicio(nump, tipo, coca, ingr);
            cout << endl;
            orden1.mostrarLista();
            break;
        
        case 2:
            
            orden1.mostrarLista();
            break;

        case 3:
        
            continuar = false;
            break;
        
        default:
            break;
        }
    } while (continuar);

    return 0;

}
