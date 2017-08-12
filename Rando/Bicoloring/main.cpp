/****************************************************
https://uva.onlinejudge.org/external/100/10004.pdf
CordeiroLibel   fevereiro/2017
Status: Terminado e Testado
****************************************************/
#include <iostream>
#include <vector>
#include <stack>

#define MAX 200

enum Color{
    SEMCOR = 0,
    COR1,
    COR2
};
using namespace std;

typedef pair<int, int> ii;

Color oposto (Color cor){
    if(cor == COR1)
        return COR2;
    return COR1;
}

int main()
{
    int nodes, lados;
    int atual, vizinho;
    bool achou = false;
    ii ent;
    vector<vector<int>> g;
    Color cores[MAX];

    cin >> nodes;
    while(nodes){
        cin >> lados;
        g.clear();
        g.resize(nodes);
        achou = false;

        //coletando dados
        for(int i=0;i<lados;i++){
            cin >> ent.first >> ent.second;
            g[ent.first].push_back(ent.second);
            g[ent.second].push_back(ent.first);
        }

        //zerando cores
        for(int i=0;i<nodes;i++)
            cores[i] = SEMCOR;

        //busca em profundidade
        stack<int> pilha;
        pilha.push(0);
        while(!pilha.empty()){
             atual = pilha.top();
             pilha.pop();

             for(unsigned int i=0;i<g[atual].size();i++){
                vizinho = g[atual][i];
                if(cores[vizinho]==SEMCOR){
                    cores[vizinho] = oposto(cores[atual]);
                    pilha.push(vizinho);
                }
                else if(cores[vizinho]==cores[atual]){
                    achou = true;
                    break;
                }
             }
             if(achou)
                break;
        }
        if(achou)
            cout << "NOT BICOLORABLE." << endl;
        else
            cout << "BICOLORABLE." << endl;
        cin >> nodes;
    }

    return 0;
}
