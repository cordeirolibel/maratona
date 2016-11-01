/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1928
CordeiroLibel   outubro/2016
Status: Terminado.
****************************************************/
#include <iostream>

using namespace std;

class Card{
    int num;//1 to N
    int valor;//1 to N/2
    Card** ligacoes;
    int n_lig;
    bool repetida;
public:
    //criando card
    Card(int _num, int _valor, int max_ligacoes){
        //alocando ligaçoes
        ligacoes = new Card*[max_ligacoes];
        //set vars
        num = _num;
        valor = _valor;
        n_lig = 0;
    }
    //adiciona uma ligação
    void addLig(Card* card)
    {
        ligacoes[n_lig] = card;
        n_lig++;
    }
    bool jaFoi(){
        return repetida;
    }
    //procura distancia ate _valor
    int findDintance(int _valor, int ant, bool first = false){
        int dist;
        //acho o ponto final
        if((_valor==valor)&&(!first)){
            repetida = true;
            return 1;
        }
        //procurando nas ligaçoes
        for(int i=0;i<n_lig;i++){
            //não va pelo mesmo caminho q veio
            if(ligacoes[i]->getNum() == ant)
                continue;
            dist = ligacoes[i]->findDintance(_valor,num);
            if(dist){//se esta na ligação i
                if(!first)
                    return dist+1;
                else
                    return dist;
            }
        }
        //não achou caminho
        return 0;
    }
    int getNum(){
        return num;
    }
    int getValor(){
        return valor;
    }
};

int main()
{
    int N, valor, c1, c2;
    cin >> N;
    Card* cards[N];
    //lendo cards
    for(int i=0;i<N;i++){
        cin >> valor;
        cards[i] = new Card(i,valor,N-1);
    }
    //lendo ligações
    for(int i=0;i<(N-1);i++){
        cin >> c1 >> c2;
        cards[c1-1]->addLig(cards[c2-1]);
        cards[c2-1]->addLig(cards[c1-1]);
    }
    //calculando soma de pontos
    unsigned long int soma=0;
    for(int i=0;i<N;i++){
        //se card não foi contado ainda
        if(!cards[i]->jaFoi()){
            soma+=cards[i]->findDintance(cards[i]->getValor(),0,true);
        }
    }
    cout << soma;
    return 0;
}
