//Sergio Pérez
#include <iostream>
#include <string>

using namespace std;

int main()  {
    
    int caramelos,numero,regalo;      //bucle termina con 0 (no más datos)
                                        //cada 5 caramelos comprados por persona te regalan 1 
    

    numero=0;
    regalo=0;
    do  {
        cout<<"Caramelos comprados: ";
        cin>>caramelos;
        numero=numero+caramelos;
            
        if (caramelos/5>=1)
            regalo=regalo+(caramelos/5);
    }   while (caramelos!=0);
    
    if (numero%5!=0)
        cout<<"RENTABLE"<<endl;
    
    else
        cout<<"NO RENTABLE"<<endl;
        
    cout<<"Caramelos vendidos: "<<numero<<endl;
    cout<<"Caramelos regalados: "<<regalo<<endl;
    
    return 0;
}