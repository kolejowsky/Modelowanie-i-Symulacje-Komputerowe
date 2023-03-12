#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));


    /*rand();
    rand();
    rand();
    rand();*/

    const int size = 2000;      //rozmiar tablicy

    //przedzial y
    float a = 0.0;              //poczatek przedzialu 
    float b = 1.0;            //koniec przedzialu

    //przedzial x
    float a1 = 0.0;
    float b1 = 2.0;

    float c = 2.0;

    const int k = 10;       //ilosc przedzialow

    float RRMAX = 1.0 * RAND_MAX;   //pomocnicza

    float sumax = 0.0;
    float sumax2 = 0.0;


    float tab[size];        //tablica liczb
    float x_tab[size];      //tablica wynikow

    float x;
    float y;

    /*for (int i = 0; i < size; i++)
    {
        //tab[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        //tab[i] = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b)
        tab[i] = rand() / RRMAX * (b1 - a1) + a1; //losowanie z przedzialu (a;b)
        
        if (tab[i] >= 0 && tab[i] < 0.5) //odwrocona dystrybuanta
        {
            x_tab[i] = sqrt(2 * tab[i]);
        }
        else
        {
            x_tab[i] = (2 - sqrt(2 * (1 - tab[i])));
        }
        

        sumax += tab[i];
        sumax2 += pow(tab[i], 2);
    }*/

    ofstream myfile("dane.txt");

    int i = 0;
    while (i < 2000)
    {
        x = rand() / RRMAX * (b1 - a1) + a1; //losowanie z przedzialu (a;b)
        y = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b)

        if (x <= 1.0)
        {
            if (y < x)
            {
                x_tab[i] = x;
                //myfile << x<< endl;
                i++;
            }
        }
        else if ( x>1.0 )
        {
            if (y <= (2 - x))
            {
                x_tab[i] = x;
                //myfile << x << endl;
                i++;
            }
        }
    }

    float xsr = sumax / 2000.0;
    float xsr2 = sumax2 / 2000.0;

    float d = (b - a) / k;

    float w2 = xsr2 - pow(xsr, 2); //wariancja do kwadratu

    float hi[k];

    for (int i = 0; i < k; i++)
    {
        hi[i] = 0;
        for (int j = 0; j < size; j++)
        {
            if ((tab[j] >= (a + d * (i))) && (tab[j] < (a + d * (i + 1))))
            {
                hi[i]++;
            }
        }
    }

    //cout << d << endl;

    /*for (int i = 0; i < k; i++)
    {
        cout << "przedzial " << i + 1 << " [ " << d * i << " , " << d * (i + 1) << " ] : " << hi[i] << endl;
    }*/

    for (int i = 0; i < size; i++)
    {
        //cout<<tab[i]<<endl;
        cout << x_tab[i] << endl;
    }


}

