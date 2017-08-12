/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1934
CordeiroLibel   2017
Status:
****************************************************/
#include <iostream>
#include <string.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_NOMES 26*26
using namespace std;

class Nomes{
    int tamanho;
    char nomes[MAX_NOMES][2];
    int valores[MAX_NOMES];
public:
    Nomes(){
        tamanho = 0;
    }
    void add(char nome[2]){
        for(int i=0;i<tamanho;i++)
            if((nomes[i][0] == nome[0])&&(nomes[i][1] == nome[1]))
                return;
        nomes[tamanho][0] = nome[0];
        nomes[tamanho][1] = nome[1];
        tamanho++;
    }
    void ordena(){
        for(int i=0;i<tamanho;i++){
            for(int j=1;j<tamanho;j++){
                if(strcmp(nomes[j-1],nomes[j])==1)
                    troca(j-1,j);
            }
        }
    }
    void troca(int pos1, int pos2){
        char tmp[2];
        tmp[0] = nomes[pos1][0];
        tmp[1] = nomes[pos1][1];
        nomes[pos1][0] = nomes[pos2][0];
        nomes[pos1][1] = nomes[pos2][1];
        nomes[pos2][0] = tmp[0];
        nomes[pos2][1] = tmp[1];
    }
    int busca(char nome[2], int pos=-1, int _min=0, int _max=-1){
        if(pos == -1){
            pos = tamanho/2;
            _max = tamanho-1;
        }
        int cmp =  strcmp(nome, nomes[pos]);

        if(cmp==0)
            return pos;
        else if(cmp==1)
            _min = pos+1;
        else
            _max = pos-1;

        pos = _min + (_max-_min)/2;
        return (busca(nome,pos,_min,_max));
    }
    void setValor(int pos, int valor){
        valores[pos] = valor;
    }
    int tam(){
        return tamanho;
    }
    void imprime(){
        for(int i=0;i<tamanho;i++){
            cout << nomes[i] << valores[i] << endl;
        }
    }
};
int main()
{
    int L, C;
    cin >> L >> C;
    char matriz[L][C][2];
    int soma_l[L], soma_c[C];
    Nomes* nomes = new Nomes;


    //pegando dados
    char nome[2];
    for(int i=0;i<L ;i++){
        for(int j=0;j<C;j++){
            cin >> nome;
            matriz[i][j][0] = nome[0];
            matriz[i][j][1] = nome[1];
            nomes->add(nome);
        }
        cin >> soma_l[i];
    }
    for(int j=0;j<C;j++)
        cin >> soma_c[j];

    //ordena em ordem alfabetica
    nomes->ordena();

    int tam_n = nomes->tam();

    //================Criando sistema Ax = b;
    int A[L+C][tam_n], B[L+C];

    //zerando matriz A
    for(int i=0;i<(L+C) ;i++)
        for(int j=0;j<tam_n;j++)
            A[i][j] = 0;

    //adicionando equações de linha
    for(int i=0;i<L ;i++){
        for(int j=0;j<C;j++){
            int local = nomes->busca(matriz[i][j]);
            A[i][local]++;
        }
        B[i] = soma_l[i];
    }
    //adicionando equações de coluna
    for(int j=0;j<C;j++){
        for(int i=0;i<L ;i++){
            int local = nomes->busca(matriz[i][j]);
            A[j+L][local]++;
        }
        B[j+L] = soma_c[j];
    }
    //contando numero de variaves
    int n_var[L+C];
    for(int i=0;i<(L+C) ;i++){
        n_var[i] = 0;
        for(int j=0;j<tam_n;j++)
            if(A[i][j]!=0)
                n_var[i]++;
    }
    //ordenando equações por numero de variaveis
    int tmp[tam_n];
    for(int i=0;i<(L+C);i++){
        for(int j=1;j<(L+C);j++){
            if(n_var[j-1]>n_var[j]){//troca
                //n_var
                tmp[0] = n_var[j];
                n_var[j] = n_var[j-1];
                n_var[j-1] = tmp[0];
                //B
                tmp[0] = B[j];
                B[j] = B[j-1];
                B[j-1] = tmp[0];
                //A
                for(int k=0;k<tam_n;k++){
                    tmp[k] = A[j][k];
                    A[j][k] = A[j-1][k];
                    A[j-1][k] = tmp[k];
                }
            }
        }
    }

    //resolvendo
    int var=0, valor;
    for(int i=0;i<(L+C);i++){
        //resolve uma equação
        for(int k=0;k<tam_n;k++)
            if(A[i][k]!=0){
                var = k;
                break;
            }
        valor = B[var]/A[i][var];
        nomes->setValor(var,valor);
        //ajusta as outras equações
        for(int j=i+1;j<(L+C);j++){
            if(A[j][var]!=0){
                B[var]=B[var]-A[j][var]*valor;
                A[j][var] = 0;
            }
        }
    }

    nomes->imprime();
    return 0;
}
