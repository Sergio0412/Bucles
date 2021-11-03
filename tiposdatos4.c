#include <iostream>
#include <cmath>

using namespace std;

int main()  {
    int maxgotas;
    int h;
    int min;
    int s;
    
    cout<<"¿Cuantas gotas caben en el cubo?"<<endl;
        cin>>maxgotas;
        h=maxgotas/3600;
        min=maxgotas/60;
        s=maxgotas%60;
        
        
        if (min>=60)
                min=min%60;
            
        cout<<"Puedes estar un máximo de "<<h<<" horas, "<<min<<" minutos y "<<s<<" segundos sin cambiar el cubo"<<endl;

    return 0;
    }