/****************************************************
https://www.urionlinejudge.com.br/judge/pt/problems/view/2242
CordeiroLibel   2017
Status: Testado e Terminado
****************************************************/

#include <iostream>
#include <queue>
#include <stack>
#include <string>

#define MAX 50
using namespace std;

queue<char> fila;
stack<char> pilha;

bool eh_volgal(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        return true;
    return false;
}

int main()
{
    char str[MAX+1];
    cin >> str;
    for(int i=0;str[i]!='\0';i++){
        if(eh_volgal(str[i])){
            fila.push(str[i]);
            pilha.push(str[i]);

        }
    }

    while(!fila.empty()){
        if(fila.front()!=pilha.top()){
            cout << 'N' << endl;
            return 0;
        }
        fila.pop();
        pilha.pop();
    }
    cout << 'S' << endl;

    return 0;
}
