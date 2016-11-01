/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1936
CordeiroLibel   novembro/2016
Status: Terminado e Testado.
****************************************************/
#include <iostream>
#define N 10
using namespace std;

int fact[N];

int calc(int valor)
{
    int i;
    if(valor==0)
        return 0;

    for(i=1;valor>=fact[i];i++);
    i--;

    valor = valor - fact[i];

    return calc(valor)+1;

}

int main()
{
    int valor;
    fact[0] = 1;
    for(int i=1;i<N;i++)
        fact[i] = fact[i-1]*i;

    cin >> valor;

    cout << calc(valor) << endl;


    return 0;
}
