#include <iostream>
#include <cstdlib>
#include <random>
#include <math.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 12;
    float pr = 0.7;

    float RRMAX = 1.0 * RAND_MAX;
    
    float a = 0;
    float b = 1.0;

    float k;
    

    int s = 0; //liczba sukcesow
    int p = 0; //liczba porazek

    int suma = 0;
    int suma2 = 0;

    //proba bernouliego

    /*
    for (int i = 0; i < 2000; i++)
    {
        s = 0;
        p = 0;
        for (int i = 0; i < n; i++)
        {
            k = rand() / RRMAX * (b - a) + a;
            //cout << "k " << k << endl;
            if (k <= pr) s++;
            else p++;

            


        }
        suma += s;
        suma2 += pow(s, 2);
        //cout << s << endl;
    }*/

    //rozklad pascala

    int r = 4; // oczekiwana liczba porazek

    for (int i = 0; i < 2000; i++)
    {
        s = 0;
        p = 0;

        while(p < r)
        {
            k = rand() / RRMAX * (b - a) + a;
            //cout << "k " << k << endl;
            if (k <= pr) s++;
            else p++;

        }
        suma += s;
        suma2 += pow(s, 2);
        //cout << s << endl;
    }

    float srednia = suma * 1.0 / 2000.0;
    float srednia2 = suma2 * 1.0 / 2000.0;

    cout << "srednia wyliczona: " << srednia << endl;
    float sredTeo = (r * pr) / (1 - pr);
    cout << "srednia teoretyczna: " << sredTeo << endl;

    float wariancja = srednia2 - pow(srednia, 2);
    cout << "wariancja wyliczona: " << wariancja << endl;
    float warTeo = (r * pr) / pow((1 - pr),2);
    cout << "wariancja teoretyczna: " << warTeo << endl;
    
    float odchSt = sqrt(wariancja); //odchylenie standardowe
    //cout << "odchylenie standardowe: " << odchSt << endl;
}
