/****************************************************
http://br.spoj.com/problems/COPA/
CordeiroLibel   2017
Status: Terminado e Testado
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int t, n, pontos, soma;
    string time;
    cin >> t >> n;
    while(t!=0){
        soma = 0;
        for(int i=0;i<t;i++){
            cin >> time >> pontos;
            soma+=pontos;
        }
        cout << 3*n-soma << endl;
        cin >> t >> n;
    }
    return 0;
}


