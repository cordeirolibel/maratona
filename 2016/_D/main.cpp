/****************************************************
https://www.urionlinejudge.com.br/judge/pt/problems/view/2238
CordeiroLibel   2017
Status:
****************************************************/

#include <iostream>
#define MAX 1000000000

using namespace std;



int main()
{
    int A, B, C, D, num, CdivA;

    cin >> A >> B >> C >> D;

    //atalho
    if((C%A)!=0){
        cout << -1 << endl;
        return 0;
    }


    for(int i = 1;(A*i)<=C;i++){
        num = i*A;

        //pulo
        if(num > (C/2)){
            i = C/A-1;
            continue;
        }

        //teste basico
        if(((C/A)%i)!=0)
            continue;
        if(num%B==0)
            continue;

        if(D%num==0)
            continue;

        cout << num << endl;
        return 0;

    }

    cout << -1 << endl;
    return 0;
}
