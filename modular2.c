#include <iostream>
#include <math.h>

using namespace std;

void obtieneAnyo(int& anyo, int& intentos) {
    
    
    cout<<"Introduce el año de nacimiento (1920-2022): ";
    cin>>anyo;
    intentos++;
    
    while ((anyo<1920)||(2022<anyo))    {
        cout<<"No es un año válido"<<endl;
        cout<<"Introduce el año de nacimiento (1920-2022): ";
        cin>>anyo;
        intentos++;
    }
    
}

int sumaCifrasPares(int& sumap, int anyo)   {
    
    sumap=0;
    
    while   (anyo>0)   {
        if ((anyo%10)%2==0)    {
            sumap +=anyo%10;
        }
        anyo=anyo/10;
    }
    
    return(sumap);
}

int sumaCifrasImpares(int& sumai, int anyo) {
    
    sumai=0;
    
    while (anyo>0)    {
        if ((anyo%10)%2!=0) {
            sumai +=anyo%10;
        }
        anyo=anyo/10;
    }
    
    return(sumai);
    
}
int calculaColor(int sumap, int sumai, char& color)  {
    
    if (sumap==sumai){
        color='r';  
    }
    if (sumap<sumai){
        color='v';
    }    

    if (sumap>sumai){
        color='a';
    }
    return(color);
}
int main()  {
    int anyo, intentos, validos;
    char a, color;
    int sumap, sumai;
    int rojo,verde,azul;
    
    rojo=0;
    verde=0;
    azul=0;
    intentos=0;
    
    do  {
        obtieneAnyo(anyo,intentos);
        sumaCifrasPares(sumap,anyo);
        sumaCifrasImpares(sumai,anyo);
        calculaColor(sumap,sumai,color);
        
        
        if (color=='r'){
            cout<<"Tu color es el rojo"<<endl;
            rojo++;
        }
        if (color=='v'){
            cout<<"Tu color es el verde"<<endl;
            verde++;
        }   
        if (color=='a'){
            cout<<"Tu color es el azul"<<endl;
            azul++;
        }
            
        cout<<"¿Quieres continuar (s/n)? ";
        cin>>a;
        
        if ((a!='s')&&(a!='n')) {
            do  {
                
            cout<<"Carácter inválido"<<endl;
            cout<<"¿Quieres continuar (s/n)? ";
            cin>>a;
            }
            while ((a!='s')&&(a!='n'));
        }
    }
    while (a!='n');
    
    validos=rojo+verde+azul;
    
    cout<<"----------INFORME----------"<<endl;
    cout<<"Intentos totales: "<< intentos <<endl;
    cout<<"Intentos válidos: "<< validos <<endl;
    cout<<"Número de rojos: "<< rojo <<endl;
    cout<<"Número de verdes: "<< verde <<endl;
    cout<<"Número de azules: "<< azul <<endl;
    
}