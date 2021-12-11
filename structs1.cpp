//Sergio Pérez Villanueva
#include <iostream>
#include <cstring>
#include <time.h>
#include <stdio.h>
using namespace std;

const int MAX=50; //NUMERO MAXIMO DE CANARIOS QUE PUEDE TENER EL TIO JUAN
const int NOMBRE=20; //MAXIMA CANTIDAD DE CARACTERES PARA LOS NOMBRES DE LOS CANARIOS

typedef char TCadena[10]; 

struct TFecha{
    int dia;
    int mes;
    int anyo;
};

struct TMascota{    
    TCadena nombre;
    TFecha fec;
};

typedef TMascota TCanarios[MAX];

void iniciaCanarios(TCanarios, int &);
int menu(int opcion);
void altaCanarios(TCanarios pajaros, int& canarios);
void mostrarCanarios(TCanarios pajaros, int canarios);
void darVitaminas(TCanarios pajaros, int canarios);

int main(){
    TCanarios pajaros;
    int tam, opcion, canarios;

    canarios=4;

    do  {
        
        iniciaCanarios(pajaros, tam);   
        opcion = menu(opcion);
        switch (opcion) {

            case 1: altaCanarios(pajaros, canarios);
            break;

            case 2: darVitaminas(pajaros, canarios);
            break;

            case 3: mostrarCanarios(pajaros, canarios);
            break;

        }   
        
    }while (opcion!=4);
    
    
    return 0;
}

//Introduce los datos de los cuatro canarios iniciales
void iniciaCanarios(TCanarios pajaros, int &tam){
    strcpy(pajaros[0].nombre,"Piopio");
    pajaros[0].fec.dia=1;
    pajaros[0].fec.mes=1;
    pajaros[0].fec.anyo=2015;
	
    strcpy(pajaros[1].nombre,"Lina");
    pajaros[1].fec.dia=22;
    pajaros[1].fec.mes=12;
    pajaros[1].fec.anyo=2018;
	
    strcpy(pajaros[2].nombre,"Trompetilla");
    pajaros[2].fec.dia=5;
    pajaros[2].fec.mes=3;
    pajaros[2].fec.anyo=2017;
	
    strcpy(pajaros[3].nombre,"Bolita");
    pajaros[3].fec.dia=5;
    pajaros[3].fec.mes=3;
    pajaros[3].fec.anyo=2017;
    tam=4;
}

//Funcion menu que nos muestra todas las opciones de nuestro programa
int menu(int opcion) {

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"1. DAR DE ALTA UN CANARIO"<<endl;
    cout<<"2. COMPROBAR VITAMINAS"<<endl;
    cout<<"3. LISTADO"<<endl;
    cout<<"4. SALIR"<<endl;
    cout<<"OPCION...";
    cin>>opcion;

    return (opcion);

}

//Función en la cual introducimos los datos de cada periquito que queramos dar de alta
void altaCanarios(TCanarios pajaros, int& canarios)  {
    
    int i;
     
    if (canarios<MAX)    {

        for (i=canarios; i<1+canarios; i++)  {

            cout<<"NOMBRE DEL CANARIO...";
            cin.ignore();
            cin.getline(pajaros[i].nombre, NOMBRE);
            cout<<"FECHA DE ADQUISICIÓN"<<endl;
            cout<<"\t"<<"DIA...";
            cin>>pajaros[i].fec.dia;
            cout<<"\t"<<"MES...";
            cin>>pajaros[i].fec.mes;
            cout<<"\t"<<"ANYO...";
            cin>>pajaros[i].fec.anyo;
        }
        canarios=canarios+1;

    }else

        cout<<"Máxima cantidad de periquitos introducida en la base de datos"<<endl; 


}

//Función que nos muestra los nombres y la fecha de adopción de todos los periquitos
void mostrarCanarios(TCanarios pajaros, int canarios)  {

    for (int i=0; i<canarios; i++) {

        cout<<i+1<<" "<<pajaros[i].nombre<<"\t"<<pajaros[i].fec.dia<<"-"<<pajaros[i].fec.mes<<"-"<<pajaros[i].fec.anyo<<endl;

    }

}

void darVitaminas(TCanarios pajaros, int canarios)  {

    time_t t;
    struct tm *tlocal;   
    int dia, mes;

    t=time(NULL);
    tlocal=localtime(&t);
    dia=tlocal->tm_mday;
    mes=tlocal->tm_mon+1;

    for (int i=0; i<canarios; i++)  {

        int actual=2021; //Año actual

        if (actual-pajaros[i].fec.anyo>=1)   {   

            if (mes>pajaros[i].fec.mes)   {

                cout<<"TOCA DAR VITAMINAS A "<<pajaros[i].nombre<<endl;

            }
            if (mes==pajaros[i].fec.mes)   {

                if (dia>pajaros[i].fec.dia)   {
                    
                    cout<<"TOCA DAR VITAMINAS A"<<pajaros[i].nombre<<endl;

                }
            }

        }
    
    }

}