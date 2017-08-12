/****************************************************
https://www.urionlinejudge.com.br/judge/pt/problems/view/2235
CordeiroLibel   2017
Status: Testado e Terminado
****************************************************/

#include <iostream>

using namespace std;

bool recursao(int v[3], int num, int pos, bool sem_nenhum){
    if(pos==3){
        if((num==0)&&(sem_nenhum==false))
            return true;
        else
            return false;
    }
    return recursao(v,num+v[pos],pos+1,false)||
           recursao(v,num-v[pos],pos+1,false)||
           recursao(v,num       ,pos+1,sem_nenhum);

}

int main()
{
    int v[3];
    cin >> v[0] >> v[1] >> v[2];
    if (recursao(v,0,0, true))
        cout << 'S' << endl;
    else
        cout << 'N' << endl;
    return 0;
}
