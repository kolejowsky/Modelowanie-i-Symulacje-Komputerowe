#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

int main()
{
    srand(time(NULL));
    
    
    /*rand();
    rand();
    rand();
    rand();*/
    
    const int size = 2000;      //rozmiar tablicy

    float a = 0.0;              //poczatek przedzialu
    float b = 100.0;            //koniec przedzialu
    const float k = 10.0;       //ilosc przedzialow

    float RRMAX = 1.0 * RAND_MAX;   //pomocnicza

    float sumax = 0.0;
    float sumax2 = 0.0;


    float tab[size];

    for (int i = 0; i < size; i++)
    {
        tab[i] = rand()/RRMAX*(b-a)+a;
        sumax += tab[i];
        sumax2 += pow(tab[i],2);
    }

    float xsr = sumax / 2000.0;
    float xsr2 = sumax2 / 2000.0;

    float d = (b - a) / k;

    float w2 = xsr2 - pow(xsr,2); //wariancja do kwadratu

    float hi[10];
    
    for (int i = 0; i < k; i++)
    {
        hi[i] = 0;
        for (int j = 0; j < size; j++)
        {
            if ( ( tab[j] >= (a + d * ( i ) ) ) && (tab[j] < (a + d * (i + 1)  ) ) )
            {
                hi[i]++;
            }
        }
    }

    //cout << d << endl;

    for (int i = 0; i < k; i++)
    {
        cout << "przedzial "<< i+1 << " [ " << d * i << " , " << d * (i + 1) << " ] : " << hi[i] << endl;
    }

    /*for (int i = 0; i < size; i++)
    {
        cout<<tab[i]<<endl;
    }*/
}

