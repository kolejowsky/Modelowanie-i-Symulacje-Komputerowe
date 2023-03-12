#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

# define M_PI           3.14159265358979323846

//wartosci

//prawdopodobienstwo
float p[4] = { 0.2, 0.1, 0.5, 0.1 };

//suma prawdopodobienstw
float s[4] = { p[0], p[0] + p[1], p[0] + p[1] + p[2], p[0] + p[1] + p[2] + p[3] };

//liczby
float l[4] = { 2.0 , 5.0, 8.0 , 13.0 };


float check(float num);
float check(int c, float x);

int main()
{
    srand(time(NULL));


    /*rand();
    rand();
    rand();
    rand();*/

    const int size = 2000;      //rozmiar tablicy

    //przedzial 1
    float a = 0.0;              //poczatek przedzialu 
    float b = 1.0;            //koniec przedzialu

    //przedzial 2
    int a1 = 0;
    int b1 = 7;

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

    float D;

    //metoda odwroconej dystrybuanty

    /*for (int i = 0; i < size; i++)
    {
        D = rand() / RRMAX * (b - a) + a;
        tab[i] = D;
        x_tab[i] = check(D);
        sumax += x_tab[i];

    }*/

    

    float r;
    int j;

    //metoda eliminacji
    
    for (int i = 0; i < size; i)
    {
        j = rand() % (b1 - a1 + 1) + a1;
        r = rand() / RRMAX * (b - a) + a;

        tab[i] = r;
        x_tab[i] = check(j, r);
        if (x_tab[i] != -1)
        {
            sumax += x_tab[i];
            i++;
        }
    }





    float xsr = sumax / 2000.0;
    float xsr2 = sumax2 / 2000.0;

    //liczenie odchylenia standardowego

    float sumaOdch = 0;
    
    for (int i = 0; i < size; i++)
    {
        //sumaOdch += pow((x_tab[i] - xsr), 2);
        sumaOdch += pow((tab[i] - xsr), 2);
    }

    float Odch = sumaOdch * 1.0 / 2000.0;

    //teoretyczne odchylenie 

    float odTeo = 0.0;
    odTeo += pow(2.0, 2) * 0.2;
    odTeo += pow(5.0, 2) * 0.1;
    odTeo += pow(8.0, 2) * 0.5;
    odTeo += pow(13.0, 2) * 0.2;




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

    cout << "srednia: " << xsr << endl;
    cout << "Odchylenie standardowe teoretyczne: " << odTeo << endl;
    cout << "Odchylenie standardowe wyliczone: " << Odch << endl;


    for (int i = 0; i < size; i++)
    {
        //cout<<tab[i]<<endl;
        //cout << x_tab[i] << endl;
    }


}



float check(float num) {
    float x;
    if((num >= 0) && (num <= s[0]))
    { 
        return l[0];
    }
    else if ((num > s[0] && num <= s[1]))
    {
        return l[1];
    }
    else if ((num > s[1] && num <= s[2]))
    {
        return l[2];
    }
    else if ((num > s[2] && num <= s[3]))
    {
        return l[3];
    }
}

float check(int c, float x) {
    switch (c)
    {
        case 1:
        {
            if (x < s[0]) return l[0];
        }
        case 2:
        {
            if (x < s[1]) return l[1];
        }
        case 3:
        {
            if (x < s[2]) return l[2];
        }
        case 4:
        {
            if (x < s[3]) return l[3];
        }
        default:
        {
            return -1;
        }

    }
}

