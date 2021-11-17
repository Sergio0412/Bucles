#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

void pideNum(int& usu_num);
void genNum(int& ordenador_num, int usu_num);
void juego (int ordenador_num, int usu_num, int& victorias, int& derrotas, int& empates);

int main() {
    
    char jugar;
    int usu_num;
    int ordenador_num;
    int partidas=0, victorias=0, derrotas=0, empates=0;
    
    do  {
        
        srand(time(NULL));

        pideNum(usu_num);
        genNum(ordenador_num,usu_num);
        juego(ordenador_num,usu_num,victorias,derrotas,empates);
        partidas++; 
        
        
        cout<<"¿Quieres jugar otra partida (s/n)?: ";
        cin>>jugar;
        
        while ((jugar!='s')&&(jugar!='n'))    {
        
            cout<<"Carácter inválido"<<endl;
            cout<<"¿Quieres jugar otra partida (s/n)?: ";
            cin>>jugar;
            
        }
            
    }while (jugar=='s');
    
    cout<<"------------------"<<endl;
    cout<<"VICTORIAS: "<<victorias<<endl;
    cout<<"DERROTAS: "<<derrotas<<endl;
    cout<<"EMPATES: "<<empates<<endl;
    cout<<"TOTAL PARTIDAS: "<<partidas<<endl;

    return 0;

}

void pideNum(int& usu_num)  {
    
    cout<<"Introduce un número: ";
    cin>>usu_num;
    
    while ((usu_num<0)||(usu_num>5))  {
         
        cout<<"Introduce un número: ";
        cin>>usu_num;
        
    }
        
}
    
void genNum(int& ordenador_num, int usu_num){
    
    srand(time(NULL));
    
    ordenador_num = rand()%5 + 1;
    
    cout<<"Ordenador: "<<ordenador_num<<" Jugador: "<<usu_num<<endl;
    
}

void juego (int ordenador_num, int usu_num, int& victorias, int& derrotas, int& empates){
    
    
    int suma;
    suma=usu_num+ordenador_num;
    
    if (((usu_num%2==0)&&(suma%2==0)&&(ordenador_num%2!=0)))  {
        
        cout<<"TU GANAS"<<endl;
        victorias++;
    }
    
    if (((usu_num%2!=0)&&(suma%2==0)&&(ordenador_num%2==0)))  {
        
        cout<<"GANA EL ORDENADOR"<<endl;
        derrotas++;
    }
    
    if (((usu_num%2!=0)&&(suma%2!=0)&&(ordenador_num%2!=0)))  {
        
        cout<<"EMPATE"<<endl;
        empates++;
    }
    
    if (((usu_num%2==0)&&(suma%2==0)&&(ordenador_num%2==0)))  {
        
        cout<<"EMPATE"<<endl;
        empates++;
    }
    
    if (((usu_num%2==0)&&(suma%2!=0)&&(ordenador_num%2!=0)))  {
        
        cout<<"GANA EL ORDENADOR"<<endl;
        derrotas++;
    }
    
    if (((usu_num%2!=0)&&(suma%2!=0)&&(ordenador_num%2==0)))  {
        
        cout<<"TU GANAS"<<endl;
        victorias++;
    }
    
    if (((usu_num%2!=0)&&(suma%2==0)&&(ordenador_num%2!=0)))  {
        
        cout<<"EMPATE"<<endl;
        empates++;
    }
        
}
    