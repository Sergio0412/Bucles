//autor Sergio Pérez
#include <iostream>
#include <math.h>

using namespace std;

int main()  {
    float r,h,peq,med,gran,vol,pi,precio_peque;
    float vol_gran,precio_med,precio_gran,vol_med;
    pi=3.14;
    
    
    cout<<"Indica radio envase pequeño (en cm): ";
        cin>>r;
    cout<<"Indica altura envase pequeño (en cm): ";
        cin>>h;
    cout<<"Indica precio envase pequeño: ";
        cin>>peq;
    cout<<"Indica precio envase mediano: ";
        cin>>med;
    cout<<"Indica precio envase grande: ";
        cin>>gran;
    
    vol=(pi*h*(r*r));                                   //volumen de envase pequeño en cm3
    vol_med=(pi*(h*1.25)*((r*1.25)*(r*1.25)));          //volumen de envase mediano sabiendo que es un 25% más grande respecto al envase pequeño
    vol_gran=(pi*(h*1.5)*((r*1.5)*(r*1.5)));            //volumen de un envase grande sabiendo que es 1.5 veces más grande que el envase pequeño
    precio_peque=peq/vol;                               //precio de envase pequeño por centimetro cúbico
    precio_med=med/vol_med;                             //precio de envase mediano por centimetro cúbico
    precio_gran=gran/vol_gran;                          //precio de envase grande por centimetro cúbico
    
    cout<<precio_peque<<endl;
    cout<<precio_med<<endl;
    cout<<precio_gran<<endl;
    
    if  ((precio_peque<precio_med)&&(precio_peque<precio_gran))    {
        cout<<"Recomendamos PEQUEÑO"<<endl;
    }
    if  ((precio_peque>precio_med)&&(precio_med<precio_gran))   {
        cout<<"Recomendamos MEDIANO"<<endl;
    }
    if  ((precio_gran<precio_peque)&&(precio_gran<precio_med))  {
        cout<<"Recomendamos GRANDE"<<endl;
    }
    

    return 0;
}
