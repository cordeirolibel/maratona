/****************************************************
https://www.urionlinejudge.com.br/judge/pt/problems/view/2243
CordeiroLibel   2017
Status:
****************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int v[n];
    for (int i=0;i<n;i++)
        cin >> v[i];

    v[0] = 1;
    for (int i=1;i<n;i++){
        //minimo entre o proprio, o anterior +1, i+1 e n-i
        v[i] = min(v[i],min(v[i-1]+1,min(i+1,n-i)));
    }

    v[n-1] = 1;
    for (int i=n-2;i>=0;i--){
        //minimo entre o proprio e o proximo +1
        v[i] = min(v[i],v[i+1]+1);
    }

    int maximo = 0;
    for (int i=0;i<n;i++)
        if(v[i]>maximo)
            maximo = v[i];

    cout << maximo << endl;
    return 0;
}
