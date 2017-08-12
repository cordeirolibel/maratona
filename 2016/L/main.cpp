/****************************************************
https://www.urionlinejudge.com.br/judge/pt/problems/view/2246
CordeiroLibel   2017
Status: Testado e Termindado
****************************************************/

#include <iostream>
#define MAX 200
#define COR_MAX 40000

using namespace std;

int abreEconta(int m[MAX][MAX],bool visit[MAX][MAX],int H, int L, int h, int l, int cor){
    //limites
    if(h==H||l==L||h<0||l<0)
        return 0;
    //se ja foi visitado
    if(visit[h][l])
        return 0;
    //mudou de cor
    if(m[h][l]!=cor)
        return 0;

    visit[h][l] = true;

    return (abreEconta(m,visit,H,L,h+1, l ,cor)+
            abreEconta(m,visit,H,L,h-1, l ,cor)+
            abreEconta(m,visit,H,L, h ,l+1,cor)+
            abreEconta(m,visit,H,L, h ,l-1,cor)+1);

}

int main()
{
    int H, L;
    int m[MAX][MAX];
    bool visitados[MAX][MAX];

    //coletando dados
    cin >> H >> L;
    for(int i=0;i<H;i++)
        for(int j=0;j<L;j++){
            cin >> m[i][j];
            visitados[i][j]=false;
        }


    int cont, menor = COR_MAX;

    for(int i=0;i<H;i++){
        for(int j=0;j<L;j++){
            if(visitados[i][j]==false){
                cont = abreEconta(m,visitados,H,L,i,j,m[i][j]);
                if(cont<menor)
                    menor = cont;
            }
        }
    }

    cout << menor << endl;
    return 0;
}
