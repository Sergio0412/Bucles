#include<iostream>

using namespace std;

int main()  {
    
    int a,b,c,aux;
    
    cout<<"Dame un numero A";
    cin>>a;
    cout<<"Dame otro numero B";
    cin>>b;
    cout<<"Dame otro numero C";
    cin>>c;
            
    aux=b;
    b=c;
    c=a;
    a=aux;
        
    cout<<"A="<<aux<<"\t"<<"B="<<b<<"\t"<<"C="<<c<<endl;
      
    return 0;
        
}