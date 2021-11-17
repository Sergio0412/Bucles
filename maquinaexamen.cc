
#include <iostream>

using namespace std;

void DepositarMonedas(int cent, int& novalid, int& valid);
void contarMonedas(int valid, int novalid);
int Apagar(int botonapagar);

int main()  {
    
    int cent=0;
    int novalid,valid;
    int botonapagar;
    
    do  {
        
        DepositarMonedas(cent, novalid, valid);
        contarMonedas(valid, novalid);
        botonapagar= Apagar(botonapagar);
    
    }while (botonapagar!=1000);
    
    return 0;

}

void DepositarMonedas(int cent, int& novalid, int& valid) {

    novalid=0;
    valid=0;
    
    cout<<"Deposite moneda (5-10-20-50 céntimos) o pida articulo (tecla 0) ";
    cin>>cent;
    
    while ((cent==0)&&(valid<50))   {
            
        cout<<"Por favor, introduzca más dinero"<<endl;
        cin>>cent;
                
    }   

    do  {
        
        while ((((cent==5)||(cent==10)||(cent==20)||(cent==50)))) {
        
            valid=valid+cent;
            cout<<"Lleva introducido = "<<valid<<endl;
            cin>>cent;
    
        }
      
        while (((((cent!=5)&&(cent!=10)&&(cent!=20)&&(cent!=50)&&(cent!=0)))))  {
            
            novalid=novalid+cent;
            cout<<"Lleva introducido = "<<valid<<endl;
            cin>>cent;

            while ((cent==0)&&(valid<50))    {
            
            cout<<"Por favor, introduzca más dinero"<<endl;
            cin>>cent;
            }
            
        }
    
    }while ((((((cent!= 0)&&(valid<50))||(cent==5)||(cent==10)||(cent==20)||(cent==50)))));
        
    cout<<"Preparando el cafe ..."<<endl;

}
        
void contarMonedas(int valid, int novalid)  {
    
    int cambio;
    int xmonedas;
    
    
    cambio=valid-50;
    cout<<"Aquí tiene su cambio: "<<endl;
    
    if (cambio==0)  {
        
        cout<<"No hay cambio que devolver"<<endl;
        
    }
    
    while (cambio>0)    {

        if ((cambio%5==0)&&(cambio>=50))    {
            
            xmonedas=cambio/50;
            cout<<xmonedas<<" monedas de 50 céntimos"<<endl;
             cambio=cambio-xmonedas*50;
        }

        if ((cambio%5==0)&&(cambio>=20))  {
            
            xmonedas=cambio/20;
            cout<<xmonedas<<" monedas de 20 céntimos"<<endl;
            cambio=cambio-xmonedas*20;
        }
        
        if ((cambio%5==0)&&(cambio>=10))  {
            
            xmonedas=cambio/10;
            cout<<xmonedas<<" monedas de 10 céntimos"<<endl;
            cambio=cambio-xmonedas*10;

        }

        if (cambio%5==0)  {
            
            xmonedas=cambio/5;
            cout<<xmonedas<<" monedas de 5 céntimos"<<endl;
            cambio=cambio-xmonedas*5;

        }
        
    }
    
    cout<<"Recuerde recoger también las monedas por valor de "<<novalid<<" céntimos"<<endl;
    
}

int Apagar(int botonapagar)    {
    
    cout<<"Apagar?"<<endl;
    cin>>botonapagar;
    
    return (botonapagar);
    
}
            
