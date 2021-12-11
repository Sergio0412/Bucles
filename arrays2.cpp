//Sergio Pérez Villanueva
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

const int CANTIDAD=6;

typedef char Tpalabras[20];
typedef Tpalabras Tcantidad[CANTIDAD];

void leeLetra(char& letra, int fallos);
void muestraMuneco(int fallos);
void palabraAleatoria(Tpalabras& oculta, Tcantidad palabras);
void palabraEscondida(Tpalabras oculta, int& longitud, Tpalabras palabra);
void comprobarPalabra(char letra, Tpalabras oculta, Tpalabras& palabra, int longitud, bool& ok, bool& adivinada);
void mostrarPalabra(Tpalabras palabra, int longitud);

int main()  {
    
    Tcantidad palabras = {"HOMBRE", "PERSONA", "MUJER", "SACACORCHOS", "ARMARIO", "TABLON"};
    Tpalabras oculta, palabra; 
    char letra;
    int longitud;
    int fallos=0;
    bool adivinada,ok;

    palabraAleatoria(oculta, palabras);
    palabraEscondida(oculta, longitud, palabra);

    adivinada=false;
    do{
        
        mostrarPalabra(palabra, longitud);
        cout<<"Puedes equivocarte "<< 4 - fallos <<" veces. Introduzca una letra: ";
        leeLetra(letra, fallos);
        comprobarPalabra(letra, oculta, palabra, longitud, ok, adivinada);
        if (!ok)    {

            fallos++;

        }
        muestraMuneco(fallos);    

    }while ((fallos<5)&&(!adivinada));

    mostrarPalabra(palabra, longitud);

    if (adivinada)  {

        cout<<"Has adivinado la palabra. ¡¡HAS GANADO!!"<<endl;
    
    }
    if (!adivinada)   {

        cout<<"No has adivinado la palabra, por lo tanto has perdido"<<endl;

    }

    return 0;
    
}

//Función que nos pide una letra y que identifica si es un carater alfanumerico 
//Tambien nos permite convertir caracteres en minúscula a mayúscula 
void leeLetra(char& letra, int fallos) {
    
    do  {
        
        cin>>letra;
        
        if  (!isalpha(letra)) {
            
            cout<<"No has introducido una letra. Introduce una letra: ";

        }   else if (islower(letra))    {

                letra=toupper(letra);
          
            }
    }while (!isalpha(letra));
        
}

//dibuja el muñeco del juego en base a los fallos cometidos. Si no hay ningún fallo no muestra nada
void muestraMuneco(int fallos){
    
    cout << endl;
    switch (fallos){
        case 1: cout << " \u263A" << endl;
                break;
        case 2: cout << " \u263A" << endl;
                cout << " \u2571" << endl; 
                break;
        case 3: cout << " \u263A" << endl;
                cout << " \u2571" << "\u2572" << endl;
                break;
        case 4: cout << " \u263A" << endl;
                cout << " \u2571" << "\u2572" << endl;
                cout << " \u2571" << endl;
                break;
        case 5: cout << " \u263A" << endl;
                cout << " \u2571" << "\u2572" << endl;
                cout << " \u2571" << "\u2572" << endl;
    }
    cout << endl;
}

//Función que elige una de las palabras guardadas y la guarda en una cadena de carácteres 
//que vamos a ocultar
void palabraAleatoria(Tpalabras& oculta, Tcantidad palabras)   {
    
    int num;
    
    srand(time(NULL)); 
    num=rand()%CANTIDAD;

    strcpy(oculta, palabras[num]);

}

//Esta función obtiene la palabra oculta y la escribe con "_"
void palabraEscondida(Tpalabras oculta, int& longitud, Tpalabras palabra) {
    
    int i;
    longitud=strlen(oculta);

    for (i=0; i<longitud; i++){

        palabra[i]='_';

    }
    cout<<endl;

}

//Función que comprueba que la letra que hemos escrito concuerda con alguna de las letras de nuestra palabra oculta
//Si concuerda, se sustituira "_" con la letra escrita, si no coincide, se sumara un fallo al contador
void comprobarPalabra(char letra, Tpalabras oculta, Tpalabras& palabra, int longitud, bool& ok, bool& adivinada) {

    ok=false;
    for (int i=0; i<longitud; i++){

        if (oculta[i]==letra)   {

            palabra[i]=letra;
            ok=true;

        }
        
    }
    if (strcmp (palabra,oculta)==0)   {

        adivinada=true;

    }
    
}

//Función que va mostrando la palabra que estamos formando
void mostrarPalabra(Tpalabras palabra, int longitud)   {
    
    for (int i=0; i<longitud; i++)  {

        cout<<palabra[i]<<" ";

    }
    cout<<endl;
    
}