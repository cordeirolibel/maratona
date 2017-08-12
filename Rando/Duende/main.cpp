/****************************************************
http://br.spoj.com/problems/DUENDE/
CordeiroLibel   fevereiro/2017
Status: Terminado e Testado
****************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> ii;

int main()
{
    int L, C;
    cin >> L >> C;

    ii duende;

    int dist[L][C];
    bool visit[L][C];

    queue <ii> fila;

    int g[L][C];

    //coletando dados
    for (int i=0;i<L;i++){
        for(int j=0;j<C;j++){
            cin >> g[i][j];
            if(g[i][j]==3){
                duende.first = i;
                duende.second = j;
            }
        }
    }

    for (int i=0;i<L;i++)
        for(int j=0;j<C;j++)
            visit[i][j] = false;

    fila.push(duende);
    visit[duende.first][duende.second] = true;
    dist[duende.first][duende.second]  = 0;

    while(!fila.empty()){
        duende = fila.front();
        fila.pop();

        ii viz[4];
        viz[0] = ii(duende.first+1,duende.second);
        viz[1] = ii(duende.first-1,duende.second);
        viz[2] = ii(duende.first,duende.second+1);
        viz[3] = ii(duende.first,duende.second-1);

        //vasculhando todos os vizinhos não vizitados
        for(int i=0;i<4;i++){
            if((viz[i].first>=0)&&(viz[i].first<L)&&
               (viz[i].second>=0)&&(viz[i].second<C)){
                if((!visit[viz[i].first][viz[i].second])&&(g[viz[i].first][viz[i].second]!=2)){
                    visit[viz[i].first][viz[i].second] = true;
                    dist[viz[i].first][viz[i].second] = dist[duende.first][duende.second]+1;
                    fila.push(viz[i]);
                    if(g[viz[i].first][viz[i].second]==0){
                        cout << dist[viz[i].first][viz[i].second] << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
