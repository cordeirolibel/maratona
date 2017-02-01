/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1928
CordeiroLibel   outubro/2016
Status:
****************************************************/

#include <iostream>

#define INFINITO 100000
#define MIN(a,b) a<b?a:b

using namespace std;


class No {
public:
    int valor;
    No* prox;
    No(){
        prox = NULL;
    }
    No(int _valor){
        prox = NULL;
        valor = _valor;
    }
    ~No(){
        if(prox!=NULL)
            delete prox;
    }
    void addProx(int index){
        if(prox==NULL)
            prox = new No(index);
        else
            prox->addProx(index);
    }

    void imprime(){
        cout << valor+1 << " ";
        if(prox!=NULL)
            prox->imprime();
    }
};

//Dado matriz, sua ordem, o no que viemos, o no atual, o no que queremos chegar
//retona o peso do caminho de
int busca(No** nos, int tam,int ant,int no,int dest){
    int valor;

    //chegou no destino
    if(no==dest)
        return 1;

    No* prox = nos[no]->prox;
    while(prox!=NULL){
        if(prox->valor==ant){//nao busca pelo mesmo caminho que veio
            prox = prox->prox;
            continue;
        }
        //busca todos os caminhos a partir do no
        valor = busca(nos,tam,no,prox->valor,dest);
        if(valor)//se encontrou caminho
            return valor+1;

        prox = prox->prox;
    }
    return 0;
}


int main()
{
    int N, c1, c2, card;
    cin >> N;

    int cards[N/2][2];
    for(int i=0;i<(N/2);i++)
        cards[i][0] = -1;

    No** nos = new No*[N];
    //set nos
    for(int i=0;i<N;i++){
        nos[i] = new No(i);
    }

    //lendo cards
    for(int i=0;i<N;i++){
        cin >> card;
        if(cards[card-1][0]==-1)
            cards[card-1][0] = i;
        else
            cards[card-1][1] = i;
        cout << "   " << i <<"  " << card <<  endl;
    }

    //lendo ligações
    for(int i=0;i<(N-1);i++){
        cin >> c1 >> c2;
        nos[c1-1]->addProx(c2-1);
        nos[c2-1]->addProx(c1-1);

    }

    //somando menores caminhos
    int soma = 0;
    for(int k=0;k<(N/2);k++){
        //procurando a posicao de duas cartas iguais de valor k
        c1 = cards[k][0];
        c2 = cards[k][1];

        soma += busca(nos,N,c1,c1,c2)-1;
    }

    cout << soma << endl;

    for(int i=0;i<N;i++)
        delete nos[i];
    delete [] nos;

    return 0;
}


