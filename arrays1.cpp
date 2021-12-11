#include <iostream>
#include <cstdlib>

using namespace std;

void crearNum (float numero[],int& c1, int& c2, int&  c3, int&  c4, int& c5, int&  c6, int&  c7, int&  c8, int& c9);
void dibujarHistoriograma (int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9);



int main()  {

    srand(time(NULL));
    float numero[100];
    int c1,c2,c3,c4,c5,c6,c7,c8,c9;

    crearNum (numero,c1,c2,c3,c4,c5,c6,c7,c8,c9);
    dibujarHistoriograma (c1,c2,c3,c4,c5,c6,c7,c8,c9);    

    return 0;

}

void crearNum (float numero[], int& c1, int& c2, int&  c3, int&  c4, int& c5, int&  c6, int&  c7, int&  c8, int& c9) {

    c1=0;
    c2=0;
    c3=0;
    c4=0;
    c5=0;
    c6=0;
    c7=0;
    c8=0;
    c9=0;

    for (int i=0; i<=99; i++)  {
                
        numero[i]=rand()%9 + 1;
        
        if (numero[i]==1)   {

            c1++;

        }
        if (numero[i]==2)   {

            c2++;

        }
        if (numero[i]==3)   {

            c3++;

        }
        if (numero[i]==4)   {

            c4++;

        }
        if (numero[i]==5)   {

            c5++;

        }
        if (numero[i]==6)   {

            c6++;

        }
        if (numero[i]==7)   {

            c7++;

        }
        if (numero[i]==8)   {

            c8++;

        }
        if (numero[i]==9)   {

            c9++;

        }

    }
    
}

void dibujarHistoriograma (int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9)    {

    cout<<"9.";

    for (int j=0; j<=c9; j++)   {

        cout<<"\u2587";

    }

    cout<<endl;
    cout<<"8.";

    for (int j=0; j<=c8; j++)   {

        cout<<"\u2587";

    }
    
    cout<<endl;
    cout<<"7.";

    for (int j=0; j<=c7; j++)   {

        cout<<"\u2587";

    }

    cout<<endl;
    cout<<"6.";

    for (int j=0; j<=c6; j++)   {

        cout<<"\u2587";

    }

    cout<<endl;
    cout<<"5.";

    for (int j=0; j<=c5; j++)   {

        cout<<"\u2587";

    }

    cout<<endl;
    cout<<"4.";

    for (int j=0; j<=c4; j++)   {

        cout<<"\u2587";

    }

    cout<<endl;
    cout<<"3.";

    for (int j=0; j<=c3; j++)   {

        cout<<"\u2587";

    }

    cout<<endl;
    cout<<"2.";


    for (int j=0; j<=c2; j++)   {

        cout<<"\u2587";

    }

    cout<<endl;
    cout<<"1.";

    for (int j=0; j<=c1; j++)   {

        cout<<"\u2587";

    }
    
    cout<<endl;

}


