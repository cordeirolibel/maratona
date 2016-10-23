/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1929
CordeiroLibel   outubro/2016
Status: Terminado e testado.
****************************************************/

#include <iostream>

using namespace std;

//teste com somente 3 numeros
bool teste(int n1, int n2, int n3){
    if(((n1+n2)>n3) && ((n1+n3)>n2) && ((n2+n3)>n1))
        return true;
    return false;
}

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(teste(a,b,c) || teste(a,b,d) ||
       teste(a,c,d) || teste(b,c,d)){
        cout << 'S' << endl;
        return 0;
    }
    cout << 'N' << endl;
    return 0;
}
