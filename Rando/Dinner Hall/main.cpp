/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1440
CordeiroLibel   fevereiro/2017
Status: Terminado e Testado
****************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stack>

class Hora{
public:
    int h;
    int m;
    int s;

    char t;
};

bool cmp(Hora a, Hora b)
{
    if(a.h<b.h)
        return true;
    else if(a.h==b.h){
        if(a.m<b.m)
            return true;
        else if(a.m==b.m)
            if(a.s<b.s)
                return true;
    }
    return false;
}

using namespace std;

int main()
{
    int n, maxi = 0, atual;
    int entradas=0;
    int entradas_duvidosas;

    cin >> n;
    while(n!=0){
        Hora times[n];
        maxi = 0;
        entradas=0;
        atual = 0;
        //coletando dados
        for(int i=0;i<n;i++){
            scanf("%d:%d:%d %c",&times[i].h,&times[i].m,&times[i].s,&times[i].t);
            if(times[i].t=='E')
                entradas++;
        }
        entradas_duvidosas = (n/2 - entradas);

        sort(&times[0],&times[n],cmp);

        //analisando dados
        for(int i=0;i<n;i++){
            if(times[i].t=='E')
                atual++;
            else if(times[i].t=='X')
                atual--;
            else{
                if(entradas_duvidosas){
                    atual++;
                    entradas_duvidosas--;
                }
                else
                    atual--;
            }
            if(atual>maxi)
                maxi = atual;
        }

        cout << maxi << endl;

        cin >> n;
    }

    return 0;
}
