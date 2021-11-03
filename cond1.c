#include <iostream>
#include <cmath>

using namespace std;

int main()  {
    char tamano;
    char top;
    float grande;
    float peque;
    float fruta;
    float dulce;
    float sirope;
    
    fruta=0.50;
    dulce=0.35;
    sirope=0.30;
    grande=2.20;
    peque=1.75;
    
    
    cout<<"------ El puesto de Sergio ------"<<endl;
    cout<<"Topping"<<endl;
    cout<<"Fruta \t 0.50"<<endl;
    cout<<"Dulce \t 0.35"<<endl;
    cout<<"Sirope \t 0.30"<<endl;
    
    cout<<"Introduce el tamaño del helado (p/g): ";           //tamaño p permite solo 1 topping, tamaño g 2 topping iguales
        cin>>tamano ;
            if (tamano=='p')   {
                cout<<"Tipo de topping (f/d/s): ";
                    cin>>top ;
               switch (top) {
                    case 'f':cout<<"El precio del helado es: "<<peque+fruta<<" euros";
                        break;
                    case 'd':cout<<"El precio del helado es: "<<peque+dulce<<" euros";
                        break;
                    case 's':cout<<"El precio del helado es: "<<peque+sirope<<" euros";
                        break;
            }
            }
            if (tamano=='g')    {
                cout<<"Tipo de topping (f/d/s): ";
                    cin>>top ;
            
                switch (top) {
                    case 'f':cout<<"El precio del helado es: "<<(grande+(fruta*2))<<" euros";
                        break;
                    case 'd':cout<<"El precio del helado es: "<<(grande+(dulce*2))<<" euros";
                        break;
                    case 's':cout<<"El precio del helado es: "<<(grande+(sirope*2))<<" euros";
                        break;
            }
            }

    return 0;
}