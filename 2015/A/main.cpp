/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1931
CordeiroLibel   novembro/2016
Status:
****************************************************/
#include <iostream>

#define MIN(a,b) (a < b ? a : b)

using namespace std;
class Ramo;
class No{
    int num;
    int valor_par;
    int valor_impar;
    int ant_par;
    int ant_impar;
    Ramo** ramos;
    int n_ramos;
public:
    No(int max_nos, int _num){
        num = _num;
        ramos = new Ramo*[max_nos];

        ant_par = 0;
        valor_par = 0;
        ant_impar = 0;
        valor_impar = 0;
        n_ramos = 0;
    }
    void add_ramo(No* new_no, int peso){
        ramos[n_ramos] = new Ramo(new_no, peso);
        n_ramos++;
    }
};

class Ramo{
public:
    int peso;
    No* no;
    Ramo(No* _no, int _peso){
        no = _no;
        peso = _peso;
    }
};
int main()
{
    int n_cidades, n_estradas;
    cin >> n_cidades >> n_estradas;

    No *cidades[n_cidades];
    for(int i=0;i<n_cidades;i++);
        cidades[i] = new No(MIN(n_cidades-1,n_estradas),i);

    for(int i=0;i<n_estradas;i++){
        int c1,c2,peso;
        cin >> c1 >> c2 >> peso;
        cidades[c1]->add_ramo(cidades[c2], peso);
        cidades[c2]->add_ramo(cidades[c1], peso);
    }
    return 0;
}









