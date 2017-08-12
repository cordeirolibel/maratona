/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1931
CordeiroLibel   2017
Status: Testado e Terminado
****************************************************/

#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000
#define MAX_VERTICES 50000

using namespace std;

class Vertice{
public:
    int num;
    int peso_par;
    int peso_imp;

    Vertice(int n, int p_par, int p_imp){
        num = n;
        peso_par = p_par;
        peso_imp = p_imp;
    }
    Vertice(){
    }
    Vertice(int n, int p){
        num = n;
        peso_par = p;
    }
    int peso(){
        return peso_par;
    }
    void peso(int p){
        peso_par = p;
    }
};

//Comparacao para priority_queue
class ComparePar{
public:
    bool operator() (Vertice a, Vertice b)
    {
        if (a.peso_par>b.peso_par)
            return true;
        return false;
    }
};
class CompareImp{
public:
    bool operator() (Vertice a, Vertice b)
    {
        if (a.peso_imp>b.peso_imp)
            return true;
        return false;
    }
};

//fila de Vertice ordenada por peso (crescente)
priority_queue<Vertice, vector<Vertice>, ComparePar> fila_ordenada_par;
priority_queue<Vertice, vector<Vertice>, CompareImp> fila_ordenada_imp;

int main()
{

    vector<Vertice> list_eq[MAX_VERTICES];
    int dist_par[MAX_VERTICES];
    int dist_imp[MAX_VERTICES];

    int n_vertices, n_arestas;
    int partida, destino;

    //===============================
    //  Coletando Dados

    cin >> n_vertices >> n_arestas;

    partida = 0;
    destino = n_vertices-1;

    //montando matriz de adjacencia
    for(int i=0;i<n_vertices;i++){
        dist_par[i] = INF;
        dist_imp[i] = INF;
    }

    int v1, v2, distancia;
    for(int i=0;i<n_arestas;i++){
        cin >> v1 >> v2 >> distancia;
        list_eq[v1-1].push_back(Vertice(v2-1,distancia));
        list_eq[v2-1].push_back(Vertice(v1-1,distancia));
    }

    //===============================
    //  Dijkstra

    //primeiro verice
    /// !Verificar se comeca em 0
    fila_ordenada_par.push(Vertice(partida,0, INF));
    dist_par[partida] = 0;

    bool atual_eh_par;

    Vertice top;
    while(!(fila_ordenada_par.empty()&&fila_ordenada_imp.empty())){
        //removendo o vertice de menor peso
        if (fila_ordenada_par.empty())
            atual_eh_par = false;
        else if(fila_ordenada_imp.empty())
            atual_eh_par = true;
        else if(fila_ordenada_par.top().peso_par<=fila_ordenada_imp.top().peso_imp)
            atual_eh_par = true;
        else
            atual_eh_par = false;

        if (atual_eh_par){
            top = fila_ordenada_par.top();
            fila_ordenada_par.pop();
        }
        else{
            top = fila_ordenada_imp.top();
            fila_ordenada_imp.pop();
        }


        /// !Verificar se comeca em 0 e se quer terminar antes
        if((top.num == destino)&&atual_eh_par)
            break;

        int novo_custo;
        for(unsigned int i=0;i<list_eq[top.num].size();i++){
            int indx = list_eq[top.num][i].num;
            if(indx==top.num)
                continue;
            //verifica se novo caminho por top vale a pena
            if(atual_eh_par){
                novo_custo = list_eq[top.num][i].peso() + dist_par[top.num];
                if(novo_custo<dist_imp[indx]){

                    //atualiza vertice i e coloca na fila
                    dist_imp[indx] = novo_custo;
                    fila_ordenada_imp.push(Vertice(indx,dist_par[indx],dist_imp[indx]));
                }
            }
            else{
                novo_custo = list_eq[top.num][i].peso() + dist_imp[top.num];
                if(novo_custo<dist_par[indx]){

                    //atualiza vertice i e coloca na fila
                    dist_par[indx] = novo_custo;
                    fila_ordenada_par.push(Vertice(indx,dist_par[indx],dist_imp[indx]));
                }
            }
        }
    }

    //===============================
    //  Print
    if(dist_par[destino]<INF)
        cout << dist_par[destino] << endl;
    else
        cout << -1 << endl;

    return 0;
}
