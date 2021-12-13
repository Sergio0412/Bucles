//Sergio Pérez Villanueva
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int MAX=20;
const int CANTIDAD=20;

typedef char TCadena[CANTIDAD];

struct TLista{

    TCadena nombre;
    int precio;

};

typedef TLista TCantidad[MAX];

void mostrarObjetos(TCantidad objetos, int numero, int recom);
void altaObjeto(TCantidad objetos, int& numero);
void bajaObjeto(TCantidad objetos, TCantidad baja, int& numero, int& recom);
void cambiaPrecio(TCantidad productos, int numero);
int menu(int opc);

int main()  {

    TCantidad objetos, baja;

    int opc, numero, recom;

    numero=0;
    recom=0;

    do  {

        opc = menu(opc);
        switch (opc)    {

        case 1: altaObjeto(objetos, numero);
        break;
 
        case 2: bajaObjeto(objetos, baja, numero, recom);
        break;

        case 3: cambiaPrecio(objetos, numero);
        break;
        
        case 4: mostrarObjetos(objetos, numero, recom);
        break;

        break;

        }

    }while (opc!=5);

    return 0;

}

//Función menu que no
int menu(int opc) {

    cout<<"Mercadillo de Lucas"<<endl;
    cout<<"*********************"<<endl;
    cout<<"1. Alta de objeto"<<endl;
    cout<<"2. Baja de producto"<<endl;
    cout<<"3. Modificación del precio de un objeto"<<endl;
    cout<<"4. Lista de objetos"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"¿Opción (1...5)? ";
    cin>>opc;

    return (opc);

}

//Función en la cual damos de alta objetos con sus nombres y sus precios
void altaObjeto(TCantidad objetos, int& numero)   {

    char resp;
    int aux; 

    if (numero<MAX)   {

        do  {

            aux=numero;

            for (int i=aux; i<aux+1; i++) {

                cout<<"Nombre del objeto: ";
                cin.ignore();
                cin.getline(objetos[i].nombre, CANTIDAD);
                cout<<"Precio: ";
                cin>>objetos[i].precio;

            }
            numero++;

            cout<<"Quieres introducir otro objeto(s/n)?";
            cin>>resp;

            while ((resp!='s')&&(resp!='n'))    {

                cout<<"Respuesta no válida."<<endl;
                cout<<"Quieres introducir otro objeto(s/n)?";
                cin>>resp;

            }

        }while (resp=='s');

    }

}

//Función para dar de baja objetos y eliminarlos de la lista de objetos
void bajaObjeto(TCantidad objetos, TCantidad baja, int& numero, int& recom)   {

    char resp;

    cout<<"Nombre del objeto vendido: ";
    cin.ignore();
    cin>>baja[0].nombre;

    for (int i=0; i<numero; i++)  {

        if (strcmp(objetos[i].nombre, baja[0].nombre)==0)  {

            cout<<"Confirmar venta (s/n): ";
            cin>>resp;

            while ((resp!='s')&&(resp!='n'))    {

                cout<<"Respuesta inválida"<<endl;
                cout<<"Confirmar venta (s/n): ";
                cin>>resp;
                
            }
            if (resp=='s')  {

                recom = recom + objetos[i].precio;

                for (int j=i; j<numero; j++)  {

                    objetos[j] = objetos[j+1];
            
                }
                numero--;
            }

        }

    }

}

//Función que nos muestra la lista de los objetos y sus precios
void mostrarObjetos(TCantidad objetos, int numero, int recom)   {

    int suma=0;    
    cout<<"LISTA DE OBJETOS"<<endl;
    cout<<"~~~~~~~~~~~~~~~~"<<endl;

    for (int i=0; i<numero; i++)  {
        
        cout<<objetos[i].nombre<<"\t"<<objetos[i].precio<<endl;
        suma=suma+objetos[i].precio;

    }

    cout<<"El valor total de los productos es: "<<suma<<endl;
    cout<<"El beneficio total de las ventas es: "<<recom<<endl;

}

//Función para cambiar los precios de los producotos
void cambiaPrecio(TCantidad objetos, int numero) {

    TCantidad nuevo;

    cout<<"Nombre del objeto a modificar: ";
    cin.ignore();
    cin.getline(nuevo[0].nombre, CANTIDAD);

    for (int i=0; i<numero; i++)    {

        if (strcmp(objetos[i].nombre, nuevo[0].nombre)==0) {

            cout<<"Precio: "<<objetos[i].precio<<endl;
            cout<<"Nuevo precio: ";
            cin>>objetos[i].precio;
            cout<<"El precio se ha actualizado"<<endl;

        } 

    }

}