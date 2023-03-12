#include <iostream>
#include <cstdlib>
#include <random>
#include <math.h>

using namespace std;

void wypisz_wynik(float lambda, float srednia, float srednia2)
{
    cout << "srednia wyliczona: " << srednia << endl;
    float sredTeo = lambda;
    cout << "srednia teoretyczna: " << sredTeo << endl;

    float wariancja = srednia2 - pow(srednia, 2);
    cout << "wariancja wyliczona: " << wariancja << endl;
    //float warTeo = (r * pr) / pow((1 - pr), 2);
    //cout << "wariancja teoretyczna: " << warTeo << endl;

    float odchSt = sqrt(wariancja); //odchylenie standardowe
    cout << "odchylenie standardowe: " << odchSt << endl;

    cout << endl;
}

int main()
{
    srand(time(NULL));

    float RRMAX = 1.0 * RAND_MAX;

    /////////////////////////
    //
    //      Wieczorkowski
    //      3.25
    //
    /////////////////////////

    
    float a = 0;
    float b = 1.0;

    float s1 = 0;
    float s1_2 = 0;

    float lambda = 5;
    float D = 0.0;
    float Y = 0.0;

    float X = -1;
    float S = 0;

    float x_1[2000];
    


    
    for (int i = 0; i < 2000; i++)
    {
        X = -1;
        S = 0;

        while (S <= lambda)
        {
            float D = rand() / RRMAX * (b - a) + a;
            float Y = -1.0 * log(1 - D);
            S += Y;
            X++;
        }
        //cout << X << endl;
        x_1[i] = X;

        s1 += X;
        s1_2 += pow(X,2);
    }

    float sr1 = s1 * 1.0 / 2000.0;
    float sr1_2 = s1_2 * 1.0 / 2000.0;



    wypisz_wynik(lambda, sr1, sr1_2);

    

    /////////////////////////
    //
    //      3.26
    //
    /////////////////////////

    float q = exp(-1.0 * lambda);
    float U = 0;

    float s2 = 0;
    float s2_2 = 0;

    float x_2[2000];

    for (int i = 0; i < 2000; i++)
    {
        X = -1;
        S = 1;
        while (S > q)
        {
            U = rand() / RRMAX * (b - a) + a;
            S *= U;
            X = X + 1;
        }
        //cout << X << endl;
        x_2[i] = X;
        s2 += X;
        s2_2 += pow(X, 2);
    }

    float sr2 = s2 * 1.0 / 2000.0;
    float sr2_2 = s2_2 * 1.0 / 2000.0;

    wypisz_wynik(lambda, sr2, sr2_2);

    ////////////////////////////
    ///
    ///  SUMA
    /// 
    /// ////////////////////////


    float TAB_X[2000];

    float s3 = 0;
    float s3_2 = 0;

    for (int i = 0; i < 2000; i++)
    {
        TAB_X[i] = x_1[i] + x_2[i];

        s3 += TAB_X[i];
        s3_2 += pow(TAB_X[i], 2);
    }

    float sr3 = s3 * 1.0 / 2000.0;
    float sr3_2 = s3_2 * 1.0 / 2000.0;

    wypisz_wynik(2* lambda , sr3, sr3_2);

    
}
