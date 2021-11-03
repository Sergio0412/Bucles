//Sergio Pérez
#include <iostream>
#include <math.h>

using namespace std;

void leePar(char& c1, char& c2, int& n)  {
    
        cout<<"Introduce un carácter: ";
        cin>>c1;
        cout<<"Introduce otro carácter (R/V): ";
        cin>>c2;
      
        while   ((((c2!='R')&&(c2!='V')&&(c2!='r')&&(c2!='v'))))   {
            cout<<c2<<" no es un carácter válido"<<endl;
            cout<<"Introduce otro carácter (R/V): ";
            cin>>c2;
        }
    
        cout<<"Introduce un número (entre 4 y 20): ";
        cin>>n;
    
        while ((n<4)||(n>20))   {
            cout<<n<<" no es un número válido"<<endl;
            cout<<"Introduce un número (entre 4 y 20): ";
            cin>>n;
        }  
    
}

void dibujar(int& suma, int& espacios, char c1, char c2, int n)   { 
        
        int i, k, j;
    
        if  ((c2=='R')||(c2=='r'))  { 
            for(i=n; i!=0; i--) {
                for(j=n; j>0; j--)    {
                cout<<c1;
                }
                cout<<endl;
            }
        }
        suma=0;
        espacios=0;
        if ((c2=='V')||(c2=='v'))   {
            for(i=n; i!=0; i--) {
                cout<<c1;
                suma=suma+1;
            }
            cout<<endl;
                for(k=n-1; k>1; k--)  {
                    for(j=n; j>0; j--)    {
                        if  ((j==n)||(j==1))  {
                            cout<<c1;
                            suma=suma+1;
                        }
                        if  ((j!=n)&&(j!=1))   {
                            cout<<" ";
                            espacios=espacios+1;
                        }
                    }
                    cout<<endl;
                }
            for(i=n; i!=0; i--) {
                cout<<c1;
                suma=suma+1;
            }
            cout<<endl;
                
        }      
}

int main()  {
        char c1, c2;
        int n;
        int suma;
        int espacios;
    
        leePar(c1,c2,n);
        dibujar(suma,espacios,c1,c2,n);
    
        if  ((c2=='R')||(c2=='r'))  {
            cout<<"El número de caracteres dibujados es: "<<n*n<<endl;
            cout<<"El tamaño del espacio anterior es 0"<<endl;
        }
        if  ((c2=='V')||(c2=='v'))  {
        cout<<"El número de caracteres dibujados es: "<<suma<<endl;
        cout<<"El tamaño del espacio anterior es: "<<espacios<<endl;
        }
    
    return 0;
}