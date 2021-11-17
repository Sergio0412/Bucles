//Sergio Pérez Villanueva   DNI=46087545F
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

void imprimir_caballo(int resultado1, int resultado2, int resultado3);
void caballos_validos(int& caba1, int& caba2, int& caba3);
void pedir_apuesta(float& credito, float& apuesta, int& caba1, int& caba2, int& caba3);
void carrera(int& resultado1, int& resultado2, int& resultado3);
void imprimir_carrera(int resultado1, int resultado2, int resultado3);
void ajustar_credito(float& credito, int apuesta, int caba1, int caba2, int caba3, int resultado1, int resultado2, int resultado3);


int main()  {
    
    srand(time(NULL));
    float apuesta;
    int caba1, caba2, caba3;
    float credito=20;
    int resultado1, resultado2, resultado3;
    
    do  {
        
        cout<<"Tu crédito es "<<credito<<".";
        
        if (credito>0)  {
                
            pedir_apuesta(credito, apuesta, caba1, caba2, caba3);
            
            if (apuesta>0)  {
                
                caballos_validos(caba1, caba2, caba3);
                carrera(resultado1, resultado2, resultado3);
                imprimir_carrera(resultado1, resultado2, resultado3);
                imprimir_caballo(resultado1, resultado2, resultado3);
                ajustar_credito(credito, apuesta, caba1, caba2, caba3, resultado1, resultado2, resultado3);
            }
            
            
        }
    
    }while ((credito>0)&&(apuesta!=0));
    
    cout<<"Gracias por participar, te vas con "<<credito<<" Euros"<<endl;
    
    return 0;
    
}

void imprimir_caballo (int resultado1, int resultado2, int resultado3)   {
    
    cout<<"PODIO DE CABALLOS"<<endl;
    
    switch (resultado1) {
        
        case 1:
            
            cout<<"1º Imperioso"<<endl;
            break;
        
        case 2:
            
            cout<<"1º Herradura"<<endl;
            break;

        case 3:
            
            cout<<"1º Rocinante"<<endl;
            break;
            
        case 4:
            
            cout<<"1º Relincho"<<endl;
            break;
            
        case 5:
            
            cout<<"1º Jamelgo"<<endl;
            break;
            
        case 6:
            
            cout<<"1º Trueno"<<endl;
            break;
            
    }
    
    switch (resultado2) {
        
        case 1:
            
            cout<<"2º Imperioso"<<endl;
            break;
        
        case 2:
            
            cout<<"2º Herradura"<<endl;
            break;

        case 3:
            
            cout<<"2º Rocinante"<<endl;
            break;
            
        case 4:
            
            cout<<"2º Relincho"<<endl;
            break;
            
        case 5:
            
            cout<<"2º Jamelgo"<<endl;
            break;
            
        case 6:
            
            cout<<"2º Trueno"<<endl;
            break;
            
    }
            
    switch (resultado3) {
        
        case 1:
            
            cout<<"3º Imperioso"<<endl;
            break;
        
        case 2:
            
            cout<<"3º Herradura"<<endl;
            break;

        case 3:
            
            cout<<"3º Rocinante"<<endl;
            break;
            
        case 4:
            
            cout<<"3º Relincho"<<endl;
            break;
            
        case 5:
            
            cout<<"3º Jamelgo"<<endl;
            break;
            
        case 6:
            
            cout<<"3º Trueno"<<endl;
            break;
            
    }
    
}

void caballos_validos (int& caba1, int& caba2, int& caba3)   {
    
    while (((caba1==caba2)||(caba1==caba3)||(caba2==caba3)))    {
        
        cout<<"Apuesta de caballos inválida. Elige tres caballos: ";
        cin>>caba1>>caba2>>caba3;
        
    }
        
    while ((((caba1<1)||(caba1>6))&&((caba2<1)||(caba2>6))&&((caba3<1)||(caba3>6))))    {
        
        cout<<"Apuesta de caballos inválida. Elige tres caballos: ";
        cin>>caba1>>caba2>>caba3;

    }

}

void pedir_apuesta (float& credito, float& apuesta, int& caba1, int& caba2, int& caba3)    {
    
    cout<<"¿Cuánto apuestas?: ";
    cin>>apuesta;
    
    if (apuesta>0)  {
    
        while (apuesta>credito) {
        
            cout<<"Créditos insuficientes. ¿Cuánto apuestas?: ";
            cin>>apuesta;
    
        }
    
        while (apuesta<0)   {
        
            cout<<"APUESTA NO VÁLIDA ";
            cin>>apuesta;
    
        }
    
        cout<<"Elige tres caballos: ";
        cin>>caba1>>caba2>>caba3;
    
        caballos_validos(caba1,caba2,caba3);
        
    }
    
}

void carrera (int& resultado1, int& resultado2, int& resultado3)    {
    
    do  {
        
        srand(time(NULL));
        
        resultado1=rand()%(6) + 1;
        resultado2=rand()%(6) + 1;
        resultado3=rand()%(6) + 1;
    
    }while (((resultado1==resultado2)||(resultado1==resultado3)||(resultado2==resultado3)));
    
}

void imprimir_carrera (int resultado1, int resultado2, int resultado3)  {
    
    cout<<"RESULTADOS DE LA CARRERA"<<endl;
    cout<<"Primero: "<<resultado1<<endl; 
    cout<<"Segundo: "<<resultado2<<endl;
    cout<<"Tercero: "<<resultado3<<endl;
    
}
        
void ajustar_credito (float& credito, int apuesta,int caba1, int caba2, int caba3, int resultado1, int resultado2, int resultado3) {
    
    if (caba1==resultado1)   {
        
        cout<<"Enhorabuena, acertaste el primer puesto"<<endl;
        credito=apuesta*5;
        
    }
    
    else if ((caba1==resultado1)&&(caba2==resultado2))   {
        
        cout<<"Enhorabuena, acertaste el primer y el segundo puesto"<<endl; 
        credito=apuesta*7;
        
    }
    
    else if (((caba1==resultado1)&&(caba2==resultado2)&&(caba3==resultado3)))  {
        
        cout<<"Enhorabuena, acertaste los 3 primeros puestos"<<endl;
        credito=apuesta*20;
        
    }
    
    else if ((caba1==resultado1)&&(caba3==resultado3))   {
        
        cout<<"Enhorabuena, acertaste el primer y el tercer puesto"<<endl;
        credito=apuesta*6;
        
    }
        
    else {
            
        credito=credito-apuesta;
        
    }
        
}
        
    

    
