#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()  {
    
    int n1;
    float compra,total,descuento;
   
    cout<<"BIENVENIDO AL SORTEO DE BOLAS"<<endl;
    cout<<"****************************"<<endl;
    cout<<"COLOR \t\t\t DESCUENTO"<<endl;
    cout<<"Blanca \t\t\t 0%"<<endl;
    cout<<"Amarilla \t\t 5%"<<endl;
    cout<<"Azul \t\t\t 7%"<<endl;
    cout<<"Roja \t\t\t 10%"<<endl;
    cout<<"****************************"<<endl;

    total=0;
    descuento=0;

    while (compra!=-1)  {
    cout<<"Introduce una venta :";
    cin>>compra;
    if (compra!=-1) 
    srand(time(NULL));
    n1=rand()%4; 
    
    

    if ((n1==0)&&(compra!=-1))  {
        cout<<"Ha salido una bola blanca"<<endl;
        descuento=compra*1;
    }
    
    if ((n1==1)&&(compra!=-1))  {
        cout<<"Ha salido una bola amarilla"<<endl;
        descuento=compra*0.95;
    }

    if ((n1==2)&&(compra!=-1))  {
        cout<<"Ha salido una bola azul"<<endl;
        descuento=compra*0.93;
    }

    if ((n1==3)&&(compra!=-1))  {
        cout<<"Ha salido una bola roja"<<endl;
        descuento=compra*0.90;
    }

    total=total+descuento;
    }

    cout<<"Total= "<<total-descuento<<endl;
    
    return 0;
}