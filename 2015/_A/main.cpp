/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1931
CordeiroLibel   janeiro/2017
Status: Terminado
****************************************************/
#include <iostream>

#define MIN(a,b) (a < b ? a : b)
#define INF 100000000 //10^8
using namespace std;

class Estrada{
public:
    int indice;
    Estrada* prox;
    int peso;
    Estrada(int  atual, int _peso = 0){
        indice = atual;
        prox = NULL;
        peso = _peso;
    }
    ~Estrada(){
        if(prox!=NULL)
            delete prox;
    }
    void addProx(int index, int _peso){
        prox = new Estrada(index, _peso);
    }
};

class Cidade{
    int num;
    bool fixo_par;
    bool fixo_impar;
public:
    long int peso_par;
    long int peso_impar;

    Cidade(int _num){
        num = _num;
        peso_par = INF;
        peso_impar = INF;
        fixo_par = false;
        fixo_impar = false;
    }

    void fixarPar(){
        fixo_par = true;
    }
    bool fixouPar(){
        return fixo_par;
    }
    void fixarImpar(){
        fixo_impar = true;
    }
    bool fixouImpar(){
        return fixo_impar;
    }
};

//busca menor valor não fixo - retorna seu local e se é o peso par ou impar
//retorna -1 para todos fixos
int menor(bool* eh_par, Cidade** cidades, int n_cidades){
    int index_min = -1;
    long int peso_min = INF;

    for(int i=0;i<n_cidades;i++){
        if((!cidades[i]->fixouPar())&&(cidades[i]->peso_par<peso_min)){
            index_min = i;
            peso_min = cidades[i]->peso_par;
            *eh_par = true;
        }
        else if((!cidades[i]->fixouImpar())&&(cidades[i]->peso_impar<peso_min)){
            index_min = i;
            peso_min = cidades[i]->peso_impar;
            *eh_par = false;
        }
    }
    return index_min;
}

int main()
{
    int n_cidades, n_estradas;
    cin >> n_cidades >> n_estradas;

    //lista encadeada
    Estrada** lista = new Estrada*[n_cidades];
    for(int i=0;i<n_cidades;i++)
        lista[i] = new Estrada(i);

    //alocando
    Cidade** cidades = new Cidade*[n_cidades];
    for(int i=0;i<n_cidades;i++)
        cidades[i] = new Cidade(i);

    //pegando ramos
    for(int i=0;i<n_estradas;i++){
        int c1,c2,pedagio;
        cin >> c1 >> c2 >> pedagio;
        lista[c1-1]->addProx(c2-1, pedagio);
        lista[c2-1]->addProx(c1-1, pedagio);
    }

    //===Dijkstra

    long int peso;
    Estrada* vizinho;
    int ind;
    //partindo da posicao 0
    bool eh_par = true;
    int pivo = 0;
    cidades[pivo]->peso_par = 0;
    cidades[pivo]->fixarPar();

    //enquanto não fixar o caminho par para a cidade n_cidades-1, ou não achar mesmo
    while(pivo != -1){
        vizinho = lista[pivo]->prox;
        while(vizinho != NULL){
            ind = vizinho->indice;
            cout << vizinho->indice << endl;
            //pivo de caminho par
            if(eh_par){
                //nem tenta caminhos q estão fixos
                if(cidades[ind]->fixouImpar()||(ind==pivo))
                    continue;
                peso = cidades[pivo]->peso_par + vizinho->peso;
                //melhor caminho
                if(peso < cidades[ind]->peso_impar)
                    cidades[ind]->peso_impar = peso;
            }
            //pivo de caminho impar
            else{
                //nem tenta caminhos q estão fixos
                if(cidades[ind]->fixouPar()||(ind==pivo))
                    continue;
                peso = cidades[pivo]->peso_impar + vizinho->peso;
                //melhor caminho
                if(peso < cidades[ind]->peso_par)
                    cidades[ind]->peso_par = peso;
            }
            if(vizinho->prox == NULL)
               cout << "oi";
            vizinho = vizinho->prox;


        }
        //fixa pivo
        if(eh_par)
            cidades[pivo]->fixarPar();
        else
            cidades[pivo]->fixarImpar();

        //saidas - achou o menor caminho par para cidade n_cidades-1
        if((pivo == n_cidades-1)&&(eh_par))
            break;

        //novo pivo
        pivo = menor(&eh_par,cidades,n_cidades);

    }

    //imprimindo resultado
    if(cidades[n_cidades-1]->peso_par >= INF)
        cout << -1 << endl;
    else
        cout << cidades[n_cidades-1]->peso_par<< endl;

    //delete
    for(int i=0;i<n_cidades;i++){
        delete cidades[i];
        delete lista[i];
    }
    delete [] cidades;
    delete [] lista;

    return 0;
}

