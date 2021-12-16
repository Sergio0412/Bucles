//Sergio Pérez Villanueva
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int KPESCADORES = 50;
const int KLETRAS = 10;
const int KPESCA = 40;

typedef char TCadena[KLETRAS];
typedef int TLongitud[KPESCA];

struct TPescadores{
    TCadena nombre;
    int capturas;
    TLongitud longitud;
};

typedef TPescadores TCantidad[KPESCADORES];

int menu(int opc);
void valoresIniciales(TCantidad &pescador, int& num_pescadores);
void altaPescadores(TCantidad pescador, TCantidad amigos, int& num_pescadores);
void mostrarLista(TCantidad amigos, int num_pescadores);
void pezPeque(TCantidad amigos, int num_pescadores);

int main(){

    TCantidad pescador;
    TCantidad amigos; 

    int num_pescadores = 2;
    int opc;

    valoresIniciales(amigos,num_pescadores);

    do{

        opc = menu(opc);
        switch(opc){
            case 1: altaPescadores(pescador, amigos, num_pescadores);
            break;

            case 2: mostrarLista(amigos, num_pescadores);
            break;

            case 3: pezPeque(amigos, num_pescadores);
            break;

            case 4:
            break;

            default:    cout<<"Opción inválida"<<endl;
            break;
        }
        cout<<endl;

    } while(opc!=4);

    return 0;
}

//Función menú en el cual tenemos las diferentes opciones que puede realizar nuestro programa
int menu(int opc){
    cout<<"*************************************************"<<endl;
    cout<<"PESCADORES INTREPIDOS"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<"1. Dar de alta una captura"<<endl;
    cout<<"2. Listado de pescadores"<<endl;
    cout<<"3. Mostrar nombre del pescador"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<"Opción (1...4): ";
    cin>>opc;

    return(opc);
}

void valoresIniciales(TCantidad &amigos, int& num_pescadores){

    //Pescador Pole y tamaño de los peces que ha pescado
    strcpy(amigos[0].nombre, "Pole");
    amigos[0].longitud[0] = 15;
    amigos[0].longitud[1] = 4;
    amigos[0].capturas = 2;


    //Pescador Vampi y tamaño del pez que ha pescado
    strcpy(amigos[1].nombre, "Vampi");
    amigos[1].longitud[0] = 35;
    amigos[1].capturas = 1;


    num_pescadores = 2;
}

//Función para dar de alta a los nuevos pescadores o para introducir la longitud de los pescados de los ya dados de alta pescadores
void altaPescadores(TCantidad pescador, TCantidad amigos, int& num_pescadores){

    int posicion; 
    cout<<"Introduzca pescador: ";
    cin>>pescador[0].nombre;

    int i = 0;
    while (strcmp(amigos[i].nombre, pescador[0].nombre)!=0 && i<num_pescadores){

        i++;
    }
    
    
    if (i==num_pescadores){  //el usuario no esta dado de alta

        strcpy(amigos[i].nombre, pescador[0].nombre);
        amigos[i].capturas = 0;
        num_pescadores++;
    }

    cout<<"Longitud del pez: "<<endl;
    posicion = amigos[i].capturas;
    cin>>amigos[i].longitud[posicion];
    amigos[i].capturas++;
    cout<<endl;
}

//Función que muestra el tamaño de los pescados con sus respectivos pescadores
void mostrarLista(TCantidad amigos, int num_pescadores){

    cout<<"*********************************"<<endl;
    cout<<"~~~~~~~~~~~~~LISTADO~~~~~~~~~~~~~"<<endl;
    cout<<"*********************************"<<endl;

    for (int i=0; i<num_pescadores; i++){

        cout<<amigos[i].nombre<<" "<<amigos[i].capturas<<" capturas: ";

        for (int j=0; j<amigos[i].capturas; j++){

            cout<<amigos[i].longitud[j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Función que determina quien es el pescador que ha pescado el pez más pequeño de todos los enlistados
void pezPeque(TCantidad amigos, int num_pescadores){

    int min=500;
    int posicionminima;
    posicionminima = 0;

    cout<<"*********************************"<<endl;
    cout<<"~PESCADOR~CON~EL~PEZ~MAS~PEQUEÑO~"<<endl;
    cout<<"*********************************"<<endl;
    for (int i = 0; i < num_pescadores; i++){

        for (int j = 0; j < amigos[i].capturas; j++){

            if (amigos[i].longitud[j] < min ){

                min = amigos[i].longitud[j];
                posicionminima = i;
            }
        }
    }
    cout<<"El pescado más pequeño lo ha pescado "<<amigos[posicionminima].nombre<<" ."<<endl;
    cout<<"El tamaño del pescado es: "<<min<<endl;
}



