/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1931
CordeiroLibel   2017
Status:
****************************************************/
#include <iostream>
#include <queue>
#include <vector>

#define INF 100000000 //10^8

using namespace std;

typedef pair<int,int> ii;

int main()
{
    int n_cidades, n_estradas;
    cin >> n_cidades >> n_estradas;

    vector<vector<ii>> adj; //first - cidade2; second - distancia
    adj.resize(n_cidades);

    //coletando dados
    int c1,c2,peso;
    for(int i=0;i<n_estradas;i++){
        cin >> c1 >> c2 >> peso;
        adj[c1-1].push_back(ii(peso,c2-1));
        adj[c2-1].push_back(ii(peso,c1-1));
    }

    priority_queue<ii,vector<ii>,greater<ii>> fila; //first - distancia; second - posição

    int dist_p[n_cidades];
    bool visit_p[n_cidades];

    int dist_i[n_cidades];
    bool visit_i[n_cidades];

    //set variaveis
    for(int i=0;i<n_cidades;i++){
        dist_p[i] = INF;
        visit_p[i] = false;
        dist_i[i] = INF;
        visit_i[i] = false;
    }

    bool atual_par;
    int atual_dist, atual_pos;
    int prox_dist, prox_pos;

    dist_p[0] = 0;
    fila.push(ii(0,0));

    while(!fila.empty()){
        atual_dist = fila.top().first;
        atual_pos = fila.top().second;
        fila.pop();

        //verifica se atual é par
        if(visit_p[atual_pos])
            atual_par = false;
        else if(visit_i[atual_pos])
            atual_par = true;
        else if(atual_dist==dist_p[atual_pos])
            atual_par = true;
        else
            atual_par = false;

        if(atual_par)
            visit_p[atual_pos] = true;
        else
            visit_i[atual_pos] = true;

        if(visit_p[n_cidades-1])
            break;

        //analisando cada vertice
        for(unsigned int i=0;i<adj[atual_pos].size();i++){
            prox_pos = adj[atual_pos][i].first;
            prox_dist = adj[atual_pos][i].second;

            if(atual_par){
                if(!visit_i[prox_pos]){
                   if (dist_i[prox_pos] > (atual_dist+prox_dist)){
                        dist_i[prox_pos] = atual_dist+prox_dist;
                        fila.push(ii(dist_i[prox_pos],prox_pos));
                   }
                }
            }
            else{//impar
                if(!visit_p[prox_pos]){
                   if (dist_p[prox_pos] > (atual_dist+prox_dist)){
                        dist_p[prox_pos] = atual_dist+prox_dist;
                        fila.push(ii(dist_p[prox_pos],prox_pos));
                   }
                }
            }
        }
    }

    if(visit_p[n_cidades-1])
        cout << dist_p[n_cidades-1] << endl;
    else
        cout << -1 << endl;

    return 0;
}

