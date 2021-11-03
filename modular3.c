//Sergio Pérez
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void numAleatorios(int& x, int& y, int& z);
void numIntroducidos(int& n1,int& n2, int& n3);
void adivinarNum(char& c1, char& c2, char& c3, int x, int y, int z, int n1, int n2, int n3);
void relacionaColor(char& c1, char& c2, char& c3);


int main()  {
    
    int n1, n2, n3;
    int x, y, z;
    char c1, c2, c3;
    int intentos=0;
    
    numAleatorios(x, y, z);
    
    do  {
        
        numIntroducidos(n1, n2, n3);
        intentos++;
        cout<<n1<<n2<<n3<<endl;
        adivinarNum(c1, c2, c3, x, y, z, n1, n2, n3);
        relacionaColor(c1, c2, c3);
        
        cout<<endl;
        
    }while (((c1!='v')||(c2!='v')||(c3!='v')));   

    cout<<"-----FIN DEL JUEGO-----"<<endl;
    cout<<"--------INFORME--------"<<endl;
    cout<<"Numero de intentos para adivinar los 3 números: "<<intentos<<endl;
    
    return 0;
}

void numAleatorios(int& x, int& y, int& z)   {
    
    do  {
        
        srand(time(NULL));
        x=rand()%10;
        y=rand()%10;
        z=rand()%10;
        
    }while  (((x==y)&&(x==z)&&(y==z)));
    

}

void numIntroducidos(int& n1, int& n2, int& n3)   {
    
    cout<<"Introduce un número (0-9): ";
    cin>>n1;
        
    if (n1>9)   {
        while   (n1>9)  {
        cout<<"El número debe estar entre 0 y 9"<<endl;
        cout<<"Introduce un número (0-9): ";
        cin>>n1;
        }
    }
    cout<<"Introduce un número (0-9): ";
    cin>>n2;
    if ((n2>9)||(n2==n1))   {
        while   ((n2>9)||(n2==n1))  {
        cout<<"El número debe estar entre 0 y 9 y ser distinto de "<<n1<<endl;
        cout<<"Introduce un número (0-9): ";
        cin>>n2;
        }
    }
    cout<<"Introduce un número (0-9): ";
    cin>>n3;
    if (((n3>9)||(n3==n2)||(n3==n1)))   {
        while   (((n3>9)||(n3==n2)||(n3==n1)))   {
        cout<<"El número debe estar entre 0 y 9 y ser distinto de "<<n1<<" y "<<n2<<endl;
        cout<<"Introduce un número (0-9): ";
        cin>>n3;
        }
    }
    
}

void adivinarNum (char& c1, char& c2, char& c3, int x, int y, int z, int n1, int n2, int n3)  {
    
    //condicionales para adivinar el numero x mediante colores
    if (n1==x)  {                       
        c1='v';
    }
    if ((n1==y)||(n1==z))   {
        c1='a';
    }
    if (((n1!=x)&&(n1!=y)&&(n1!=z)))    {
        c1='r';
    }
    
    //condicionales para adivinar el numero y mediante colores
    if (n2==y)   {                          
        c2='v';
    }
    if ((n2==x)||(n2==z))   {
        c2='a';
    }
    if (((n2!=y)&&(n2!=x)&&(n2!=z)))    {
        c2='r';
    }
    
    //condicionales para adivinar el numero z mediante colores
    if (n3==z)  {                             
        c3='v';
    }
    if ((n3==x)||(n3==y))   {
        c3='a';
    }
    if (((n3!=z)&&(n3!=x)&&(n3!=y)))    {
        c3='r';
    }
}

void relacionaColor(char& c1, char& c2, char& c3) {
    
    switch (c1) {
        
        case 'v':
                cout<<"verde \t";
                break;
        case 'a':
                cout<<"amarillo \t";
                break;
        case 'r':
                cout<<"rojo \t";
                break;
    }
    
    switch (c2) {
        
        case 'v':
                cout<<"verde \t";
                break;
        case 'a':
                cout<<"amarillo \t";
                break;
        case 'r':
                cout<<"rojo \t";
                break;
    }
    
    switch (c3) {
        
        case 'v':
                cout<<"verde \t";
                break;
        case 'a':
                cout<<"amarillo \t";
                break;
        case 'r':
                cout<<"rojo \t";
                break;
    }
    
}
