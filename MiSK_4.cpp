//funkcja dopasowana do histogramu to rozk³ad Gaussowski 
//parametry:
// 
//1  Constant     7.55637e+02   1.30377e+01   4.64315e-02  -1.17979e-06
//2  Mean         6.54619e+01   2.05228e-01   8.53416e-04   2.67328e-04
//3  Sigma        1.38653e+01   1.35241e-01   1.11738e-05 - 4.21612e-03



///////////////////////////////////////////////////////////////////////////
//                                                                       //
//                  Miko³aj £uczak                                       //
//                  Modelowanie i Symulacje Komputerowe                  //
//                  Czas robienia zakupow                                //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

# define M_PI           3.14159265358979323846

float y() {
    srand(time(NULL));
    float a = 0.0;
    float b = 1.0;

    

    return 0;
}

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

    float sigma = 4; //dodatnia 
    float mi = 0.5;    //dowolny

    float x;
    float y;

    //Metoda Boxa - Mullera
    /*for (int i = 0; i < size; i++)
    {
        //tab[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

        float u1 = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b)
        float u2 = rand() / RRMAX * (b - a) + a;

        float R = sqrt(-2 * log(u1));
        float theta = 2 * M_PI * u2;

        float z1 = R * sin(theta);

        x_tab[i] = z1 * sigma + mi;

        sumax += tab[i];
        sumax2 += pow(tab[i], 2);
    }*/


    //Centralne twierdzenie graniczne
    /*for (int i = 0; i < size; i++)
    {
        //tab[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float mi = 0.5;
        float sigma2 = 1.0 / 12.0;

        float sigma = sqrt(sigma2);


        int const m = 6;

        float RRMAX = 1.0 * RAND_MAX;

        //float x[m];

        float x1 = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b);
        float x2 = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b);
        float x3 = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b);
        float x4 = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b);
        float x5 = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b);
        float x6 = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b);


        float suma = x1 + x2 + x3 + x4 + x5 + x6;
        //cout << suma << endl;
        

        //for (int i = 0; i < m; i++)
        //{
        //    x[i] = rand() / RRMAX * (b - a) + a; //losowanie z przedzialu (a;b);
        //    suma += x[i];
        //}

        x_tab[i] = ((((1.0 / m) * suma) - mi) / (sigma / sqrt(m) * 1.0));
    }*/


    //z biblioteki random

    mt19937 GEN(time(nullptr));
    normal_distribution<> los(a, b);

    for (int i = 0; i < size; i++)
    {
        
        x_tab[i] = los(GEN);
    }


    


    float xsr = sumax / 2000.0;
    float xsr2 = sumax2 / 2000.0;

    float d = (b - a) / k;

    //float w2 = xsr2 - pow(xsr, 2); //wariancja do kwadratu

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

