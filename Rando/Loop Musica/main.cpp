/****************************************************
http://br.spoj.com/problems/LOOPMUSI/
CordeiroLibel   2017
Status: Terminado e Testado
****************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n, first, second, ant, atual, prox, picos;
    cin >> n;
    while(n!=0){
        picos = 0;
        cin >> ant;
        cin >> atual;
        first = ant;
        second = atual;
        if((n==2)&&(first==second)){
            cout << 0 <<endl;
            cin >> n;
            continue;
        }
        else if(n==2){
            cout << 2 <<endl;
            cin >> n;
            continue;
        }

        for(int i=2;i<n;i++){
            cin >> prox;
            if(((ant>atual)&&(atual<prox))||
               ((ant<atual)&&(atual>prox)))
               picos++;
            ant = atual;
            atual = prox;
        }
        prox = first;
        if(((ant>atual)&&(atual<prox))||
           ((ant<atual)&&(atual>prox)))
           picos++;
        ant = atual;
        atual = prox;
        prox = second;
        if(((ant>atual)&&(atual<prox))||
           ((ant<atual)&&(atual>prox)))
           picos++;
        cout << picos << endl;
        cin >> n;
    }
    return 0;
}
