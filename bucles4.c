//Sergio Pérez
#include <iostream>

using namespace std;

int main()  {
    int tipo, filas, i, j;
    
    cout<<"Tipo de triángulo (1,2,3): ";
    cin>>tipo;
    cout<<"Número de filas: ";
    cin>>filas;
    
    switch (tipo)   {
        
        case 1:
            
            for(i=filas; i!=0;  i--) {
                cout<<"*";
                
            }
            cout<<endl;
            
            for(i=filas-1;  i!=0; i--)  {
                
                cout<<"*";
                
                    if (i > 1)  {
                        for(j = i - 2; j!=0; j--)   {
                            cout<<'o';
                        }
                    }
                    if (i>1)    {
                        cout<<"*"<<endl;
                    }
            }
            
            cout<<endl;
            
                break;
        
        case 2:
            
            cout<<'o';
    
            for(i=filas-2; i!=0; i--) {
                cout<<"*";
            }
            cout<<'o'<<endl;
            for(i= filas - 1; i!=1; i--)    {
                for(j=filas-i;  j!=0; j--)  {
                cout<<" ";
                }
            
                for(j=i; j!=0; j--) {
                cout<<"*";
                }
                cout<<endl;

            }
            for (i = filas - 1; i != 0; i--) {
                cout << ' ';
            }
            cout << 'o' << endl;
            
                break;
                
        case 3:
            
            for(i=filas; i!=0; i--) {
                
                for(j=i-1; j>0; j--)   {
                    cout<<" ";
                }
                
                for(j=filas-i; j>0; j--)   {
                    cout<<"*";
                    cout<<'o';
                }
                cout<<"*"<<endl;
            }
                
    }
            
            
            
        return 0;
    }
