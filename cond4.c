//Sergio Pérez

#include <iostream>
#include <cmath>

using namespace std;

int main()  {
    int c1,c2,salto,salto2,resta,resta2;
    
    cout<<"Canal actual (1-99)"<<endl;
    cin>>c1;
    cout<<"¿Que canal quiere poner (1-99)?"<<endl;
    cin>>c2;
    
    salto=c2-c1;
    salto2=c1-c2;
    
    if ((c2>c1)&&(salto<50)){
        cout<<salto<<" siguiente"<<endl;
    }
    if ((c2>c1)&&(salto>50)){
        resta=(99-salto);
        cout<<resta<<" anterior"<<endl;
    }
    if ((c1>c2)&&(salto2<50)){
        cout<<salto2<<" anterior"<<endl;
    }
    if ((c1>c2)&&(salto2>50)){
        resta2=(99-salto2);
        cout<<resta2<<" siguiente"<<endl;
    }
    
    return 0;
}