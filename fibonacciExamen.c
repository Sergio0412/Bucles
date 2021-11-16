///Sergio Pérez Villanueva DNI=46087545F
#include <iostream>

using namespace std;

void leeUsuario(int& ite, char& c1, char& mostrar);
int fibonacci(int ite, char c1, int total);
void dibujaSerie(int ite, char c1, char mostrar);

int main()  {
    
    int ite;                                    //variable que guarda el número de iteraciones
    char c1, mostrar;                           //variables que guardan el carácter a mostrar y si queremos mostrar o no el número de iteraciones
    int total=0;                                   //variable que inicializa el contador total de caracteres escritos
        
    leeUsuario(ite, c1, mostrar);
    dibujaSerie(ite, c1, mostrar);

    total=fibonacci(ite,c1,total);
    
    cout<<"Total: "<<total<<endl;

    return 0;
    
}

void leeUsuario(int& ite, char& c1, char& mostrar)  {           // funcion que pide el numero de iteraciones, el caracter a escribir y si queremos que salga el iterador
    
    cout<<"Iteraciones: ";
    cin>>ite;
    
    while (ite<=0)   {
        
        cout<<"Iteraciones: ";
        cin>>ite;
        
    }
    
    cout<<"Carácter: ";
    cin>>c1;
    cout<<"Mostrar iteración [I/F/N]: ";
    cin>>mostrar;
    
    while (((mostrar!='I')&&(mostrar!='F')&&(mostrar!='N')))    {
        
        cout<<"Mostrar iteración [I/F/N]: ";
        cin>>mostrar;

    }
    
}
    
int fibonacci(int ite,char c1, int total)  {        // funcion que calcula el total de caracteres a escribir 
    
    int x=0; int y=1; int z=1;
    total=0;
    int i,j;
    
    for (i=1; i<=ite; i++)  {
                
        total=total+z;
        
        for (j=0; j<z; j++)    {
            
        }
        
        z = x + y;

        x=y;
        y=z;

    }
    
    return (total);
}

void dibujaSerie(int ite, char c1, char mostrar)  {             // funcion que dibuja la serie de fibonacci con el caracter que hemos puesto en la funcion leeUsuario y donde elegimos tambien si queremos que salgan las iteraciones
    
    int i,j;
    int x=0; int y=1; int z=1;
    int suma=1;
    int total=0;
        
    
    switch (mostrar)    {
        
        case 'I':
        
            for (i=1; i<=ite; i++)  {
                
                total=total+z;
                cout<<"("<<suma<<") ";
        
                for (j=0; j<z; j++)    {
            
                    cout<<c1;
                }
        
                z = x + y;

                x=y;
                y=z;
    
                cout<<endl;
                suma=suma+1;

            }
            
            break;
        
        case 'F':
        
            for (i=1; i<=ite; i++)  {
                
                total=total+z;
            
                for (j=0; j<z; j++)    {
            
                    cout<<c1;
                }
                cout<<"\t";
                cout<<"("<<suma<<")";

                z = x + y;

                x=y;
                y=z;
    
                cout<<endl;
                suma=suma+1;

            }
            
            break;
                
        case 'N':
            
            for (i=1; i<=ite; i++)  {
                
                total=total+z;
            
                for (j=0; j<z; j++)    {
            
                    cout<<c1;
                }

                z = x + y;

                x=y;
                y=z;
    
                cout<<endl;
                suma=suma+1;

            }
            
    }
    
}



















  
        
        
        
    
    

