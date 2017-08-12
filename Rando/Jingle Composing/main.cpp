/****************************************************
https://www.urionlinejudge.com.br/judge/problems/view/1430
CordeiroLibel   2017
Status: Termindado e Testado
****************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int right;
    float sum;
    char str;

    while(true){
        right=0;
        sum = 0.0;
        str = cin.get();
        while(str!='\n'){
            switch(str){
                case '*':
                    return 0;
                    break;
                case '/':
                    if(sum == 1.0)
                        right++;
                    sum = 0.0;
                    break;
                case 'W':
                    sum+=1.0;
                    break;
                case 'H':
                    sum+=1.0/2;
                    break;
                case 'Q':
                    sum+=1.0/4;
                    break;
                case 'E':
                    sum+=1.0/8;
                    break;
                case 'S':
                    sum+=1.0/16;
                    break;
                case 'T':
                    sum+=1.0/32;
                    break;
                case 'X':
                    sum+=1.0/64;
                    break;
            }
            str = cin.get();
        }
        cout << right << endl;
    }
    return 0;
}
