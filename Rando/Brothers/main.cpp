/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1376
CordeiroLibel   janeiro/2017
Status: Terminado e Testado
****************************************************/
#include <iostream>
#include <vector>
using namespace std;

int heirs;

bool m(int num1, int num2){
    if(num1 == (heirs-1)){
        if(num2 == 0)
            return true;
        return false;
    }
    else if (num1==(num2-1))
        return true;
    return false;
}


int main()
{
    int  L, C, batalhas;
    cin >> heirs >> L >>  C >> batalhas;
    while(heirs!=0){
        int mapa[L][C];
        int clone[L][C];
        //coletando dados
        for(int i=0;i<L;i++){
            for(int j=0;j<C;j++){
                cin >> mapa[i][j];
                clone[i][j] = mapa[i][j];
            }
        }

        while(batalhas--){
            for(int i=0;i<L;i++){
                for(int j=0;j<C;j++){
                    if(0<i)
                        if(m(clone[i][j],clone[i-1][j]))
                            mapa[i-1][j] = clone[i][j];
                    if(i<(L-1))
                        if(m(clone[i][j],clone[i+1][j]))
                            mapa[i+1][j] = clone[i][j];
                    if(0<j)
                        if(m(clone[i][j],clone[i][j-1]))
                            mapa[i][j-1] = clone[i][j];
                    if(j<(C-1))
                        if(m(clone[i][j],clone[i][j+1]))
                            mapa[i][j+1] = clone[i][j];
                }
            }
            //clonando mapa
            if(batalhas!=0)
                for(int i=0;i<L;i++)
                    for(int j=0;j<C;j++)
                        clone[i][j] = mapa[i][j];
        }
        //imprimindo
        for(int i=0;i<L;i++){
            for(int j=0;j<C;j++){
                if(j!=0)
                    cout << ' ';
                cout << mapa[i][j];
            }
            cout << endl;
        }
        cin >> heirs >> L >>  C >> batalhas;
    }
    return 0;
}

