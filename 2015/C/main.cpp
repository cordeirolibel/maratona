/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/1933
CordeiroLibel   novembro/2016
Status: Terminado e Testado.
****************************************************/
#include <iostream>

using namespace std;

int main()
{
    int c1, c2;

    cin >> c1 >> c2;

    if(c1 == c2)
    {
        cout << c1 << endl;
    }
    else
    {
        if(c1 > c2)
        {
            cout << c1 << endl;
        }
        else
        {
            cout << c2 << endl;
        }
    }
    return 0;
}
