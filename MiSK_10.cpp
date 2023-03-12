#include <iostream>

using namespace std;

int main()
{
    int a = 33;
    int c = 7;
    int m = 1000;

    const int n = 5000;

    int x[n];
    x[0] = 1;

    for (int i = 1; i < n; i++)
    {
        x[i] = (a * x[i - 1] + c )% m;
        //cout << x[i] << endl;
    }

    float r[n];

    for (int i = 0; i < n; i++)
    {
        r[i] = x[i] * 1.0 / (m - 1) * 1.0;
        //cout << r[i] << endl;
    }

    cout << endl << endl;

    const int d = 10;
    float rk[d];
    for (int i = 0; i < d; i++)
    {
        rk[i] = 0;
    }


    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rk[i] += pow(r[j], i + 1);
        }
    }

    for (int i = 0; i < d; i++)
    {
        rk[i] /= n*1.0;
        //cout <<"rk"<<i+1<<": " << rk[i] << endl;
    }

    float tab2d[2][n / 2];

    for (int i = 0; i < n / 2; i++)
    {
        tab2d[0][i] = r[2*i];
        tab2d[1][i] = r[(2 * i) + 1];
    }

    for (int i = 0; i < n / 2; i++)
    {
        //cout << tab2d[0][i] << " " << tab2d[1][i] << endl;
        //cout << endl;
    }

    const int liczba_klas = 10;
    float hist_wart[liczba_klas];

    for (int i = 0; i < liczba_klas; i++)
    {
        hist_wart[i] = (i + 1)*1.0 / liczba_klas * 1.0;
        //cout << hist_wart[i] << endl;
    }
    
    int histogram2d[liczba_klas][liczba_klas];

    for (int i = 0; i < liczba_klas; i++)
    {
        for (int j = 0; j < liczba_klas; j++)
        {
            histogram2d[i][j] = 0;
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        int pom1 = tab2d[0][i] * 10;
        int pom2 = tab2d[1][i] * 10;
        histogram2d[pom1][pom2]++;
    }

    for (int i = 0; i < liczba_klas; i++)
    {
        for (int j = 0; j < liczba_klas; j++)
        {
            cout << histogram2d[i][j] << " ";
        }
        cout << endl;
    }


    
     //sprobowac zrobic test chi kwadrat (wiec chyba histogram tez)
}