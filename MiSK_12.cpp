#include <iostream>

using namespace std;

int main()
{
    int a = 313;
    int c = 717;
    int m = 1011137;

    const int n = 9000;

    int x[n];
    x[0] = 1;

    for (int i = 1; i < n; i++)
    {
        x[i] = (a * x[i - 1] + c) % m;
        //cout << x[i] << endl;
    }

    float r[n];

    for (int i = 0; i < n; i++)
    {
        r[i] = x[i] * 1.0 / (m - 1) * 1.0;
        //cout << r[i] << endl;
    }

    float y2[n / 2];

    for (int i = 0; i < n / 2; i++)
    {
        //cout << i + 1 << " ";
        y2[i] = r[2 * i] + r[(2 * i) + 1];
        //cout << y2[i] << endl;
    }
    
    float sum2[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        if (y2[i] > 0 && y2[i] <= 1) sum2[i] = y2[i];
        else if (y2[i] > 1 && y2[i] <= 2) sum2[i] = 2 - y2[i];
    }

    for (int i = 0; i < n / 2; i++)
    {
        //cout << i + 1 << " ";
        //cout << sum2[i] << endl;
    }

    float y3[n / 3];

    for (int i = 0; i < n / 3; i++)
    {
        //cout << i + 1 << " " 
        //cout << " " << 3 * i << " " << 3 * i + 1 << " " << 3 * i + 2 << " ";
        y3[i] = r[3 * i] + r[(3 * i) + 1] + r[(3 * i) + 2];
        cout << y3[i] << endl;
    }
    
}