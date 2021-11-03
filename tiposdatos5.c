#include <iostream>
#include <cmath>

using namespace std;

    int main()  {
        int hora;
        int min;
        int hora2;
        int min2;
        int tiempoh;
        int tiempomin;
        int total;
        
        cout<<"Introduce la Hora y los minutos de entrada (separados por un espacio): ";
            cin>>hora>>min;
        cout<<"Introduce la Hora y los minutos de salida (separados por un espacio): ";
            cin>>hora2>>min2;
        
        tiempoh=(hora2-hora)*60;
        tiempomin=min2-min;
        total=tiempoh+tiempomin;
        
        cout<<"Tiempo de permanencia: "<<total<<" minutos."<<endl;
        cout<<"Importe total: "<<((total/30)+1)*0.35<<" euros. "<<endl;
        
        
        return 0;
    }