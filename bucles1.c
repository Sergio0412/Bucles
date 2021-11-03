//Sergio Pérez
#include <iostream>

using namespace std;

int main(){
    
    char a;
    int w,b;
    
    w=0;           //calcetin blanco(white)
    b=0;            //calcetin negro(black)
    
    while (a!='.')  {
    cout<<"Introduce un calcetin (W/B): ";
    cin>>a;
    if ((a=='W')||(a=='w'))
        w=w+1;
    if ((a=='B')||(a=='b'))
        b=b+1;
    }
    
    if ((((w%2==0)&&(b%2==0)&&(w!=1)&&(b!=1))))
        cout<<"EMPAREJADOS."<<endl;
    if ((w%2!=0)&&(w+b!=2))
        cout<<"BLANCO SOLITARIO"<<endl;
    if ((b%2!=0)&&(w+b!=2))
        cout<<"NEGRO SOLITARIO"<<endl;
    if (w+b==2)
        cout<<"PAREJA MIXTA"<<endl;

    
    return 0;
    
}
    
    
    
    