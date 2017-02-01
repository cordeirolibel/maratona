/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1935
CordeiroLibel   novembro/2016
Status: Terminado e Testado.
****************************************************/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long unsigned int n, b, resto, new_n, espessura;

    cin >> n >> b;


    espessura = (n-sqrt(n*n-b))/2;
    resto = b-4*espessura*(n-espessura);
    new_n = n-2*espessura;

    if(resto <= new_n)
    {
        cout << espessura + 1 << " " << espessura + resto << endl;
        return 0;
    }

    resto -= new_n-1;
    if(resto <= new_n)
    {
        cout << espessura + resto << " " << n-espessura << endl;
        return 0;
    }

    resto -= new_n-1;
    if(resto <= new_n)
    {
        cout << n-espessura << " " << n-espessura-resto+1 << endl;
        return 0;
    }

    resto -= new_n-1;
    cout << n-espessura-resto+1 << " " << espessura + 1 << endl;
    return 0;
}
