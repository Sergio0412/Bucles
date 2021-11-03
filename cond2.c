#include <iostream>
#include <cmath>

using namespace std;

int main()  {
    float dis;
    float km;
    float vel_max;
    float tiempo;
    
    
    cout<<"Distancia entre las dos cámaras (en metros) : ";
        cin>>dis    ;
    cout<<"Indica velocidad máxima permitida (km/h) : ";
        cin>>vel_max    ;
    cout<<"Tiempo tardado en recorrer tramo (en segundos): ";
        cin>>tiempo ;
        
    km=dis/1000;           //pasar distancia a km
    tiempo=tiempo/3600;     //pasar segundos a horas
        
    if ((km/tiempo)<=vel_max)   {
        cout<<"OK"<<endl;
    }
    if (((km/tiempo)>(vel_max*1) && (km/tiempo)<=(vel_max*1.2))) {
        cout<<"MULTA"<<endl;
    }
    if  ((km/tiempo)>(vel_max*1.2)) {
        cout<<"PUNTOS"<<endl;
    }
        
    return 0;
    }   