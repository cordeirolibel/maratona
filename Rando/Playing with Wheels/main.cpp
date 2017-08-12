/****************************************************
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1008
CordeiroLibel   2017
Status: Testado e Terminado
****************************************************/

#include <iostream>
#include <queue>

#define M(a) (((a)<0) ? (((a)+10)%10):((a)%10))

#define MAX 10000

using namespace std;

//encontra vizinhos de 0~7
int prox(int num, int index){
    switch(index){
    case 0:
        return (num - num%10) + M(num%10-1);
    case 1:
        return (num - num%10) + M(num%10+1);
    case 2:
        return (num - ((num/10)%10)*10) + M((num/10)%10-1)*10;
    case 3:
        return (num - ((num/10)%10)*10) + M((num/10)%10+1)*10;
    case 4:
        return (num - ((num/100)%10)*100) + M((num/100)%10-1)*100;
    case 5:
        return (num - ((num/100)%10)*100) + M((num/100)%10+1)*100;
    case 6:
        return (num - ((num/1000)%10)*1000) + M((num/1000)%10-1)*1000;
    case 7:
        return (num - ((num/1000)%10)*1000) + M((num/1000)%10+1)*1000;
    }
    return -1;
}

int cinNum(){
    int ent, saida = 0;
    cin >> ent;
    saida+=ent*1000;
    cin >> ent;
    saida+=ent*100;
    cin >> ent;
    saida+=ent*10;
    cin >> ent;
    saida+=ent;
    return saida;
}

int main()
{
    int n_problemas;
    cin >> n_problemas;

    int start, finish, n_invalidos, invalido;
    bool visitados[MAX];
    int dist[MAX];

    while(n_problemas--){
        queue<int> fila;
        bool achou = false;
        //zerando visitados
        for(int i=0;i<MAX;i++)
            visitados[i] = false;

        //coletando dados
        start=cinNum();
        finish=cinNum();
        cin >> n_invalidos;
        for(int i=0;i<n_invalidos;i++){
            invalido = cinNum();
            visitados[invalido] = true;
        }

        int atual, vizinho;

        fila.push(start);
        dist[start] = 0;
        visitados[start] = true;

        while(!fila.empty()){
            atual = fila.front();
            fila.pop();

            //analisando vizinhos
            for(int i=0;i<8;i++){
                vizinho = prox(atual,i);
                if(!visitados[vizinho]){
                    visitados[vizinho] = true;
                    fila.push(vizinho);
                    dist[vizinho] = dist[atual]+1;
                }

                if(vizinho == finish){
                    achou = true;
                    break;
                }
            }
            if(achou)
                break;
        }
        //imprimindo resultados
        if(achou)
            cout << dist[vizinho] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
