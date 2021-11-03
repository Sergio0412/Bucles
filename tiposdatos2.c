#include <iostream>
#include <cmath>

using namespace std;

int main()  {
    int dinero;
    int numero;
    int hermanos;
    int hermanas;
    
    cout<<"Anota el dinero que llevas: "<< "\t (Pulsa una tecla para continuar)";
        cin>>dinero;
        cin.get();
    cout<<"Multiplica ese numero por 10"<< "\t (Pulsa una tecla para continuar)";
        cin.get();
        numero=dinero*10;
    cout<<"Suma 25"<< "\t\t\t\t (Pulsa una tecla para continuar)";
        cin.get();
        numero=numero+25;
        cin.get();
    cout<<"Suma el número de hermanas"<< "\t (Pulsa una tecla para continuar)";
        cin>>hermanas;
        numero=numero+hermanas;
        cin.get();
    cout<<"Multiplica ese numero por 10"<< "\t (Pulsa una tecla para continuar)";
        cin.get();
        numero=numero*10;
        cin.get();
    cout<<"Suma el número de hermanos"<< "\t (Pulsa una tecla para continuar)";
        cin>>hermanos;
        numero=numero+hermanos;
        cin.get();
    cout<<"Resta 250"<< "\t\t\t (Pulsa una tecla para continuar)";
        cin.get();
        numero=numero-250;
    cout<<"El resultado es: "<<numero<<endl;
    
    cout<<"Tienes "<<hermanos<<" hermanos, "<<hermanas<<" hermanas y llevas "<<dinero<< " euros."<<endl;

    return 0;
    }
    