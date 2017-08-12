
/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1934
CordeiroLibel   2016
Status: Time Limit
****************************************************/
#include <iostream>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

typedef struct {
    char nome[3];
    int n_rept;
    int valor;
}Var;

class NoBinario{
    NoBinario* dir;
    NoBinario* esq;
public:
    Var var;
    NoBinario(Var _var){
        dir = NULL;
        esq = NULL;
        var = _var;
    }
    void add(NoBinario* new_no){
        char *new_nome = new_no->var.nome;
        char *nome = var.nome;
        //mesma variavel
        if((new_nome[0]==nome[0])&&(new_nome[1]==nome[1]))
            return;

        //para esquerda
        if((new_nome[0]<nome[0])||((new_nome[0]==nome[0])&&(new_nome[1]<nome[1]))){

            if(esq==NULL)
                esq = new_no;
            else
                esq->add(new_no);
        }
        //para direita
        else if((new_nome[0]>nome[0])||((new_nome[0]==nome[0])&&(new_nome[1]>nome[1]))){
            if(dir==NULL)
                dir = new_no;
            else
                dir->add(new_no);
        }
    }

    void imprime(){
        if(esq!=NULL)
            esq->imprime();
        cout << var.nome <<" " << var.valor << endl;
        if(dir!=NULL)
            dir->imprime();
    }
};
//consiste em uma equação, a pilha é de variaveis
class Pilha{
    unsigned int tamanho;
    int soma;
    Var* vars;
public:
    Pilha(int tam_max){
        tamanho = 0;
        vars = new Var[tam_max];
    }
    void addVar(char nome[3]){
        for(unsigned int i=0;i<tamanho;i++){
            //variavel ja existe
            if((nome[0]==vars[i].nome[0])&&(nome[1]==vars[i].nome[1])){
                vars[i].n_rept++;
                return;
            }
        }
        //variavel não existe
        vars[tamanho].nome[0] = nome[0];
        vars[tamanho].nome[1] = nome[1];
        vars[tamanho].nome[2] = '\0';
        vars[tamanho].n_rept = 1;
        tamanho++;
    }
    void setSoma(int _soma){
        soma = _soma;
    }
    //atualiza se uma variavel ja tem resultado, retorna true se ja esta vazia
    bool update(Var var){
        for(unsigned int i=0;i<tamanho;i++){
            //variavel ja existe
            if((var.nome[0]==vars[i].nome[0])&&(var.nome[1]==vars[i].nome[1])){
                soma -= var.valor*vars[i].n_rept;
                tamanho--;
                if(tamanho==0)
                    return true;
                return false;
            }
        }
        return false;
    }
    //se possui so uma variavel, resolve e retorna true e result
    bool resolva(Var* result){
        if(tamanho == 1){
            result->nome[0] = vars[0].nome[0];
            result->nome[1] = vars[0].nome[1];
            result->nome[2] = '\0';
            result->valor = soma/(vars[0].n_rept);
            tamanho--;
            delete [] vars;
            return true;
        }
        return false;
    }
    int getSoma(){
        return soma;
    }
};

int main()
{
    int L, C;
    cin >> L >> C;
    //alocar
    Pilha** equacL = new Pilha*[L];
    Pilha** equacC = new Pilha*[C];
    for(int i=0;i<L;i++)
        equacL[i] = new Pilha(C);
    for(int i=0;i<C;i++)
        equacC[i] = new Pilha(L);
    //pegando dados
    char var_name[3];
    int soma;
    for(int i=0;i<L;i++){
        for(int j=0;j<C;j++){
            cin >> var_name[0] >> var_name[1];
            var_name[2] = '\0';
            equacC[j]->addVar(var_name);
            equacL[i]->addVar(var_name);
        }
        cin >> soma;
        equacL[i]->setSoma(soma);
    }
    for(int j=0;j<C;j++){
        cin >> soma;
        equacC[j]->setSoma(soma);
    }
    NoBinario* raiz = NULL;
    Var var;
    bool resolveu = false;
    //resolvendo, L e C indicam quantas equacoes falta resolver das linhas e colunas
    while((L>0)||(C>0)){
        resolveu = false;
        //resolvendo as equacoes de linha
        for(int i=0;i<L;i++){
            if(equacL[i]->resolva(&var)){//resolveu 1 equac =)
                //add a arvore binaria
                NoBinario* new_no = new NoBinario(var);
                if(raiz==NULL)
                    raiz = new_no;
                else
                    raiz->add(new_no);
                resolveu = true;
                equacL[i] = equacL[L-1];
                L--;
                break;
            }
        }
        //se nenhuma de linha foi resolvida, tentar as de coluna
        if(!resolveu)
            for(int j=0;j<C;j++){
                if(equacC[j]->resolva(&var)){//resolveu 1 equac =)
                    //add a arvore binaria
                    NoBinario* new_no = new NoBinario(var);
                    if(raiz==NULL)
                        raiz = new_no;
                    else
                        raiz->add(new_no);
                    resolveu = true;
                    equacC[j] = equacC[C-1];
                    C--;
                    break;
                }
            }
        //cout << var.nome << " " << var.valor << endl;
        //update, novo dado encontrado
        for(int i=0;i<L;i++){
            if(equacL[i]->update(var)){//equacao eliminada
                equacL[i] = equacL[L-1];
                L--;
                i--;
            }
        }
        for(int j=0;j<C;j++){
            if(equacC[j]->update(var)){//equacao eliminada
                equacC[j] = equacC[C-1];
                C--;
                j--;
            }
        }
    }
    //imprimindo resultado
    raiz->imprime();
    //desalocar
    for(int i=0;i<L;i++)
        delete equacL[i];
    for(int i=0;i<C;i++)
        delete equacC[i];
    delete [] equacL;
    delete [] equacC;
    return 0;
}
