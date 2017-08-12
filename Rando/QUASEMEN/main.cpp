/****************************************************
https://www.urionlinejudge.com.br/judge/pt/problems/view/1391
CordeiroLibel   2017
Status: Testado e Terminado
****************************************************/
#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000
#define MAX_VERTICES 500

using namespace std;

class Vertice{
public:
    int num;
    int peso;

    Vertice(int n, int p){
        num = n;
        peso = p;
    }
};

//Comparacao para priority_queue
class Compare{
public:
    bool operator() (Vertice a, Vertice b)
    {
        if (a.peso>b.peso)
            return true;
        return false;
    }
};

//fila de Vertice ordenada por peso (crescente)
priority_queue<Vertice, vector<Vertice>, Compare> fila_ordenada;

void apaga_caminhos(int adj[MAX_VERTICES][MAX_VERTICES], int partida, int destino, int atual, vector<int> pi []){

    if (atual == partida)
        return;

    int proximo;
    //para cada possivel caminho
    for(unsigned int i=0;i<pi[atual].size();i++){
        proximo = pi[atual][i];

        //apagando
        adj[proximo][atual] = INF;
        adj[atual][proximo] = INF;

        apaga_caminhos(adj, partida,destino,proximo,pi);
    }


}

void print(int adj[MAX_VERTICES][MAX_VERTICES], int n_vertices){
    cout <<"__\t";
    for(int j=0;j<n_vertices;j++)
        cout << j << '\t';
    cout << endl;
    for(int i=0;i<n_vertices;i++){
        cout << i << "|\t";
        for(int j=0;j<n_vertices;j++){
            cout << adj[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{

    int adj[MAX_VERTICES][MAX_VERTICES];
    vector<int> pi[MAX_VERTICES];
    int dist[MAX_VERTICES];

    int n_vertices, n_arestas;
    int partida, destino;

    while(true){
        //===============================
        //  Coletando Dados

        cin >> n_vertices >> n_arestas;

        if((!n_vertices)&&(!n_arestas))//saida
            break;

        cin >> partida >> destino;

        //montando matriz de adjacencia
        for(int i=0;i<n_vertices;i++){
            for(int j =0;j<n_vertices;j++)
                adj[i][j] = INF;
            adj[i][i] = 0;
            dist[i] = INF;
        }

        int v1, v2, distancia;
        for(int i=0;i<n_arestas;i++){
            cin >> v1 >> v2 >> distancia;
            /// !Verificar se eh direcional e se comeca em 0
            adj[v1][v2] = distancia;
            //adj[v2][v1] = distancia;
        }

        //===============================
        //  Dijkstra

        //primeiro verice
        /// !Verificar se comeca em 0
        fila_ordenada.push(Vertice(partida,0));
        dist[partida] = 0;

        while(!fila_ordenada.empty()){
            //removendo o vertice de menor peso
            Vertice top = fila_ordenada.top();
            fila_ordenada.pop();

            int novo_custo;
            for(int i=0;i<n_vertices;i++){

                //verifica se novo caminho por top vale a pena
                novo_custo = adj[top.num][i] + dist[top.num];
                if(novo_custo<dist[i]){

                    //atualiza vertice i e coloca na fila
                    dist[i] = novo_custo;
                    pi[i].clear();//limpa todos os pais
                    pi[i].push_back(top.num);
                    fila_ordenada.push(Vertice(i,dist[i]));
                }

                //pode ter mais de um pai
                else if((novo_custo==dist[i])&&(i!=top.num))
                    pi[i].push_back(top.num);
            }
        }

        //===============================
        //  Removendo Caminhos de Adj

        apaga_caminhos(adj, partida,destino,destino,pi);

        //===============================
        //  Reset variaveis

        for(int i=0;i<n_vertices;i++){
            dist[i] = INF;
            pi[i].clear();
        }

        //===============================
        //  Dijkstra novamente

        //primeiro verice
        /// !Verificar se comeca em 0
        fila_ordenada.push(Vertice(partida,0));
        dist[partida] = 0;

        while(!fila_ordenada.empty()){
            //removendo o vertice de menor peso
            Vertice top = fila_ordenada.top();
            fila_ordenada.pop();

            int novo_custo;
            for(int i=0;i<n_vertices;i++){

                //verifica se novo caminho por top vale a pena
                novo_custo = adj[top.num][i] + dist[top.num];
                if(novo_custo<dist[i]){

                    //atualiza vertice i e coloca na fila
                    dist[i] = novo_custo;
                    pi[i].clear();//limpa todos os pais
                    pi[i].push_back(top.num);
                    fila_ordenada.push(Vertice(i,dist[i]));
                }

                //pode ter mais de um pai
                else if((novo_custo==dist[i])&&(i!=top.num))
                    pi[i].push_back(top.num);
            }
        }

        if(dist[destino]>=INF)
            cout << -1 << endl;
        else
            cout << dist[destino] << endl;
    }
    return 0;
}




