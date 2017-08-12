/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1940
CordeiroLibel   2016
Status: Terminado e Testado.
****************************************************/
#include <iostream>

using namespace std;

int main()
{
    int J, N, ponto;

    cin >> J >> N;

    int pontos[J];

    for(int i=0;i<J;i++)
        pontos[i] = 0;

    for(int i=0;i<(J*N);i++){
        cin >> ponto;
        pontos[i%J]+=ponto;
    }

    int max_pontos = 0;
    int ganhador = 0;

    for(int i=0;i<J;i++){
        if(pontos[i]>=max_pontos){
            max_pontos = pontos[i];
            ganhador = i;
        }
    }

    cout << ganhador+1 << endl;
    return 0;
}
