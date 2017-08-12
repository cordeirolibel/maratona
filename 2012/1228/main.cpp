/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1228
CordeiroLibel   2017 - by gabrielsouzaesilva
Status:Terminado e Testado
****************************************************/
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int largada[24];
    int chegada[24];
    int competidores[24];
    int ultrapassagens, n, aux;


    while(scanf("%d", &n) != EOF){

        ultrapassagens = 0;
        aux=0;

        for(int i=0; i<n; i++)
        {
            cin >> largada[i];
        }

        for(int i=0; i<n; i++)
        {
            cin >> chegada[i];
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(largada[i] == chegada[j])
                {
                    competidores[j] = i;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(competidores[i] > competidores[j])
                {
                    aux = competidores[j];
                    competidores[j] = competidores[i];
                    competidores[i] = aux;
                    ultrapassagens++;
                }
            }
        }

        cout << ultrapassagens << endl;

    }

    return 0;
}
