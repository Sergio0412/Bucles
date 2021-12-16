//Sergio Pérez VIllanueva
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

const char KCARACTERES = 25;
const int KMAXIMA = 150;

typedef char TCadena[KCARACTERES];

typedef int TOpiniones[10];

struct TFecha{
    
    int mes;
    int anyo;
    
};

struct TVideojuego{
    
    TCadena titulo;
    char genero;
    TFecha fec;
    int num_opiniones; 
    TOpiniones opiniones;
    int clasificacion;
    
};

typedef TVideojuego TAlmacen[KMAXIMA];

int menu(int opc);
void darAlta(TAlmacen juegos, int& num_juegos, int& num_opiniones);
void darClasificacion(TAlmacen juegos, int num_juegos);
void listaClasificados(TAlmacen juegos, int num_juegos);

int main(){
    
    TAlmacen juegos;
    
    int opc, num_juegos, num_opiniones;
    
    num_juegos = 0;
    
    do{
        
        opc = menu(opc);
        
        switch (opc){
            
            case 1: darAlta(juegos, num_juegos, num_opiniones);
            break;
            
            case 2: darClasificacion(juegos, num_juegos);
            break;
            
            case 3: listaClasificados(juegos, num_juegos);
            break;
            
            case 4: 
            break;
            
            default:    cout<<"Opción incorrecta"<<endl;
            break;
        }
        cout<<endl;
        
    }while (opc!=4);
    
    
    
    return 0;
}

int menu(int opc){
    
    cout<<"********** TIENDAS FRIQUIGAME *********"<<endl;
    cout<<"Seleccione una opción del menú"<<endl;
    cout<<"1. Introducir un nuevo videojuego"<<endl;
    cout<<"2. Clasificar un videojuego por edad"<<endl;
    cout<<"3. Listar los videojuegos ya clasificados"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"Opción: "<<endl;
    cin>>opc;
    
    return (opc);
    
}

void darAlta(TAlmacen juegos, int& num_juegos, int& num_opiniones){
    
    cout<<"***** ALTA DE VIDEOJUEO *****"<<endl;
    cout<<"Título: ";
    cin.ignore();
    cin.getline(juegos[num_juegos].titulo, KCARACTERES);
    cout<<"Género (A/C/D): "; 
    cin>>juegos[num_juegos].genero;
    cin.get();
    
    juegos[num_juegos].num_opiniones = 0;
    juegos[num_juegos].clasificacion = 0;

    
    while (((juegos[num_juegos].genero != 'A')&&(juegos[num_juegos].genero != 'C')&&(juegos[num_juegos].genero != 'D'))){
    
        cout<<"Género (A/C/D): "; 
        cin>>juegos[num_juegos].genero;
        
    }
    cout<<"Fecha de lanzamiento (MM AAAA): ";
    cin>>juegos[num_juegos].fec.mes>>juegos[num_juegos].fec.anyo;
    cin.get();
    
    cout<<"Número de opiniones de revistas a introducir (1..10): ";
    cin>>num_opiniones;
    cin.get();
    
    while ((num_opiniones < 1 ) || (num_opiniones > 10)){
        
        cout<<"Número de opiniones de revistas a introducir (1..10): ";
        cin>>num_opiniones;
        cin.get();
    }
    for (int j = 0; j < num_opiniones; j++){
        
        cout<<"Opinión "<< j+1 << "(3,12,18): ";
        cin>>juegos[num_juegos].opiniones[j];
        cin.get();
        
        while (((juegos[num_juegos].opiniones[j]!= 3)&&(juegos[num_juegos].opiniones[j]!= 12)&&(juegos[num_juegos].opiniones[j]!= 18))){
            
            cout<<"Opinión "<< j+1 << "(3,12,18): ";
            cin>>juegos[num_juegos].opiniones[j];
            cin.get();
            
        }
        if (((juegos[num_juegos].opiniones[j] == 3) || (juegos[num_juegos].opiniones[j] == 12) || (juegos[num_juegos].opiniones[j] == 18))){
            
            juegos[num_juegos].num_opiniones++;
            
        }
        
    }
    num_juegos++;
    cout<<"ALTA DE VIDEOJUEGO CORRECTA"<<endl;
    
}
    
// Función para clasificar los videojuegos segun la nota media de las opiniones dadas
void darClasificacion(TAlmacen juegos, int num_juegos){
    
    TAlmacen clasificar;
    float suma = 0;
    float media;
    int pos = -1;           //centinela, si este valor no cambia en el bucle for, es que no hemos encontrado el videojuego en la lista
    
    cout<<"***** CLASIFICAR UN VIDEOJUEGO POR EDAD *****"<<endl;
    cout<<"Introduce el título del videojuego a clasificar: ";
    cin.ignore();
    cin.getline(clasificar[0].titulo, KCARACTERES);
    
    for (int i = 0; i < num_juegos && pos == -1; i++){
        
        if (strcmp(juegos[i].titulo , clasificar[0].titulo) == 0){
            
            pos = i;
            
        }
    }
    
    for (int j = 0; j < juegos[pos].num_opiniones; j++){
            
        suma = suma + juegos[pos].opiniones[j];
            
    }
    
         
    if (pos == -1){
        
        cout<<"El videojuego "<<clasificar[0].titulo<<" NO se ha introducido todavía"<<endl;
        
    }
    
    if (pos != -1){
    
        media = (suma / juegos[pos].num_opiniones);
    
        if (media < 12 ){
            
            juegos[pos].clasificacion = 3;
         
        } 
        if ((media < 18) && (media >= 12 )){
        
            juegos[pos].clasificacion = 12;
        
        } 
        if (media >= 18){
        
            juegos[pos].clasificacion = 18;
        
        }
        cout<<"* El videojuego "<<juegos[pos].titulo<< " obtiene una clasificación de "<<  juegos[pos].clasificacion <<endl;
    
    }
    
}
            
void listaClasificados(TAlmacen juegos, int num_juegos){
    
    int pos = -1; //centinela
    
    cout<<"***** VIDEOJUEGOS YA CLASIFICADOS POR EDAD *****"<<endl;
    
    for (int i = 0; i < num_juegos; i++){
        
        if (juegos[i].clasificacion != 0){
            
            pos = i;
            cout<<"Título: "<<juegos[pos].titulo<<endl;
            cout<<"Fecha de lanzamiento: "<<juegos[pos].fec.mes<<"/"<<juegos[pos].fec.anyo<<endl;
            cout<<"Clasificación: Mayores de "<<juegos[pos].clasificacion<<" años"<<endl;
            cout<<"*****"<<endl;
        }
    }
    
    if (pos == -1)  {
        
        cout<<"NO HAY VIDEOJUEGOS CLASIFICADOS TODAVÍA"<<endl;
    }
}

    
    
    
            



