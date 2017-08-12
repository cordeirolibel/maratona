/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1931
CordeiroLibel   2017
Status:
****************************************************/
#include <iostream>
#include <queue>
#include <vector>

#define INF 100000000 //10^8
#define CIDADES_MAX 10000

using namespace std;

int adj[CIDADES_MAX][CIDADES_MAX];

class Vertice{
public:
    int dist;//distancia
    int num;
    int pi;//pai

    //inicializa
    Vertice(){
        dist = INF;
        pi = -1;
    }
};

//regra de comparacao para a fila ordenada
class Comp{
public:
    bool operator()(Vertice v1, Vertice v2){
        if(v1.dist<v2.dist)
            return true;
        return false;
    }
};


int main()
{
    int n_cidades, n_estradas;
    cin >> n_cidades >> n_estradas;

    vector<Vertice> vertices;
    vertices.resize(n_cidades);

    //inicializa
    for(int i=0;i<n_cidades;i++){
        for(int j=0;j<n_cidades;j++){
            adj[i][j]=INF;
        }
        adj[i][i] = 0;
        vertices[0].dist =
    }
    vertices[0].dist = 0;

    //coletando dados
    int c1,c2,peso;
    for(int i=0;i<n_estradas;i++){
        cin >> c1 >> c2 >> peso;
        adj[c1-1][c2-1] = peso;
        adj[c2-1][c1-1] = peso;
    }

    //arrumando a fila ordenada
    priority_queue<Vertice, vector<Vertice>, Comp> fila;

    for(int i=0;i<n_cidades;i++){
        fila.push(vertices[i]);
    }

    while(fila.empty()){
        Vertice atual = fila.top();
        fila.pop();
        cout << atual.dist << endl;
    }
    return 0;
}

