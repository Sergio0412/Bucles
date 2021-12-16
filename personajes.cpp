#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int KMAXIMA = 10;
const char KCARACTERES = 20;

struct TCaracteristicas{

    int vida;
    int sem;
    int e;
    int exp;

};

typedef char TCadena[KCARACTERES];

struct TPersonajes{
    
    TCadena nombre;
    TCaracteristicas stats;

};

typedef TPersonajes TCantidad[KMAXIMA];

int menu(int opc);
void darAlta(TCantidad nombre, int& num_personajes);
void seleccionPersonaje(TCantidad personaje, TCantidad& amigo, int num_personajes);
void recoger(TCantidad amigo, TCantidad personaje, int opc);
void stats_ini(TCantidad amigo);
void actualizarContadores(TCantidad personaje, TCantidad amigo, int num_personajes);
void mostrar(TCantidad personaje, TCantidad amigo, int num_personajes);
void inicial(TCantidad amigos);

int main(){

    srand(time(NULL));

    TCantidad personaje;
    TCantidad amigo;

    int opc, num_personajes;

    num_personajes = 0;

    do{
        
        opc = menu(opc);

        switch (opc){

            case 1: darAlta( personaje, num_personajes);
            break;

            case 2: seleccionPersonaje(personaje, amigo, num_personajes);
            break;

            case 3: recoger(amigo, personaje, opc);
            break;

            case 4: recoger(amigo, personaje, opc);
            break;

            case 5: actualizarContadores(personaje, amigo, num_personajes);
            break;

            case 6: mostrar(personaje, amigo, num_personajes);

            default:
            break;
        }


    } while(opc != 7);

    return 0;
}

// Función menu que muestra todas las opciones de nuestro programa
int menu(int opc){

    cout<<"1. ALTA PERSONAJE"<<endl;
    cout<<"2. Seleccionar personaje"<<endl;
    cout<<"3. Recoger semillas"<<endl;
    cout<<"4. Recoger energía"<<endl;
    cout<<"5. Actualizar contadores"<<endl;
    cout<<"6. Contadores del personaje seleccionado"<<endl;
    cout<<"7. Salir"<<endl;
    cout<<"Opción (1.....7): ";
    cin>>opc;

    return (opc);

}

// Función que utilizaremos para dar de alta nuevos personajes
void darAlta(TCantidad personaje, int& num_personajes){

    TCantidad amigo;
    int i;
    char resp;

    cout<<"Introduzca nombre de personaje: ";
    cin.ignore();
    cin.getline(amigo[0].nombre, KCARACTERES);

    i = 0;
    while ((i < num_personajes) && (strcmp(amigo[0].nombre,personaje[i].nombre) != 0)){

        i++;

    }
    if (i == num_personajes){

        cout<<amigo[0].nombre<< " no esta dado de alta."<<endl;
        cout<<"¿Quiere dar de alta al personaje (S/N): ";
        cin>>resp;

        while ((resp != 'S')&&(resp != 'N')){

            cout<<"¿Quiere dar de alta al personaje (S/N): ";
            cin>>resp;

        }

        if (resp == 'S'){

            strcpy(personaje[i].nombre,amigo[0].nombre);
            cout<<"Personaje dado de alta CORRECTAMENTE"<<endl;
            num_personajes++;

        } else {

            cout<<"Personaje NO dado de alta"<<endl;

        }

    } else if (strcmp(amigo[0].nombre,personaje[i].nombre) == 0){

        cout<<"El personaje "<<amigo[0].nombre<<" ya esta dado de alta"<<endl;

    }
    cout<<endl;

}


//Función que utilizaremos para seleccionar al personaje que queramos
void seleccionPersonaje(TCantidad personaje, TCantidad& amigo, int num_personajes){

    int pos = -1;       //esta variable actua de centinela, si en el bucle for no cambia su valor significa que no hemos encontrado el personaje dado de alta que hemos escrito 

    cout<<"LISTA DE PERSONAJES"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
    for (int i = 0; i < num_personajes; i++){

        cout<< i+1 <<" "<< personaje[i].nombre <<" "<<endl;

    }
    cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Introduzca el nombre del personaje que quiera: ";
    cin.ignore();
    cin.getline(amigo[0].nombre ,KCARACTERES);

    for (int j = 0; j <  num_personajes; j++){

        if (strcmp(amigo[0].nombre, personaje[j].nombre) == 0){

            cout<<"Personaje seleccionado CORRECTAMENTE"<<endl;
            pos = j;

            personaje[j].stats.vida = 10;           //Estadisticas iniciales cuando das de alta un nuevo personaje
            personaje[j].stats.sem = 1;
            personaje[j].stats.e = 0;
            personaje[j].stats.exp = 2;
            
        }
    }
    if (pos == -1){

        cout<<amigo[0].nombre<<" no esta dado de alta en nuestra base datos"<<endl;

    }
    cout<<endl;
}
void inicial(TCantidad amigo){

    amigo[0].stats.vida = 10;           //Estadisticas iniciales cuando das de alta un nuevo personaje
    amigo[0].stats.sem = 1;
    amigo[0].stats.e = 0;
    amigo[0].stats.exp = 2;

}


// Función para recoger semillas o para incrementar la experiencia
void recoger(TCantidad amigo, TCantidad personaje, int opc){


    if (opc == 3){

        cout<<"¿Cuantas semillas quiere recoger ?: ";
        cin>>amigo[1].stats.sem;
        cout<<amigo[1].stats.sem<<" semillas recogidas"<<endl;
        amigo[0].stats.sem = amigo[1].stats.sem + amigo[0].stats.sem;

        
    }
    if (opc == 4){

        amigo[1].stats.e = rand()%100;
        cout<<"Se han añadido "<<amigo[1].stats.e<<" unidades de energía"<<endl;
        amigo[0].stats.e = amigo[0].stats.e + amigo[1].stats.e;

    }
    cout<<endl;
}

// Función con la cual actualizaremos los contadores
void actualizarContadores(TCantidad personaje, TCantidad amigo, int num_personajes){

    while (amigo[0].stats.e > 10){

        amigo[0].stats.exp = amigo[0].stats.exp*amigo[0].stats.exp;
        amigo[0].stats.e = amigo[0].stats.e - 10;

    }
    amigo[0].stats.vida = amigo[0].stats.sem * 10;

    for (int i = 0; i < num_personajes; i++){

        if (strcmp(personaje[i].nombre, amigo[0].nombre) == 0){

            personaje[i].stats.vida = amigo[0].stats.vida;
            personaje[i].stats.sem = amigo[0].stats.sem;
            personaje[i].stats.e = amigo[0].stats.e;
            personaje[i].stats.exp = amigo[0].stats.exp;
            cout<<"Contadores actualizados "<<endl;

        }
    }
    cout<<endl;
}

// Función para mostrar las estadisticas del personaje que tengamos seleccionado
void mostrar(TCantidad personaje, TCantidad amigo, int num_personajes){

    cout<<"~~~ Estadísticas de los personajes~~~"<<endl;

    for (int i = 0; i < num_personajes; i++){

        if (strcmp(personaje[i].nombre, amigo[0].nombre) == 0){

            cout<<personaje[i].nombre<<endl;
            cout<<"Vida : "<<personaje[i].stats.vida<<endl;
            cout<<"Experiencia : "<<personaje[i].stats.exp<<endl;
            cout<<"Semillas : "<<personaje[i].stats.sem<<endl;
            cout<<"Energía : "<<personaje[i].stats.e<<endl;
            cout<<"~~~~~~~~~~~~~~"<<endl;

        }
    }
    cout<<endl;
}

