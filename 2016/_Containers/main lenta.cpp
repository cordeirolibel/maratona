/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/2237
CordeiroLibel   2017
Status:
****************************************************/


#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000
#define N_MOVES 10

using namespace std;

int troca(short*a,short*b){
    short tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return (*a + *b);
}

class Cnt{
public:
    short mat[2][4];
    int peso;

    Cnt(){
        peso = INF;
    }
    bool isEqual(Cnt* cnt){
       for(short i = 0;i<4;i++){
        if(cnt->mat[0][i]!=mat[0][i])
            return false;
        if(cnt->mat[1][i]!=mat[1][i])
            return false;
        }
        return true;
    }

    void cinMat(){
        for(short i = 0;i<4;i++)
            cin >> mat[0][i];
        for(short i = 0;i<4;i++)
            cin >> mat[1][i];
    }
    // 00 01 02 03
    // 10 11 12 13
    void moveMat(short who, int init_peso){
        switch(who){
        case 0:
            peso = init_peso+troca(&mat[0][0],&mat[1][0]);
            break;
        case 1:
            peso = init_peso+troca(&mat[0][1],&mat[1][1]);
            break;
        case 2:
            peso = init_peso+troca(&mat[0][2],&mat[1][2]);
            break;
        case 3:
            peso = init_peso+troca(&mat[0][3],&mat[1][3]);
            break;
        case 4:
            peso = init_peso+troca(&mat[0][0],&mat[0][1]);
            break;
        case 5:
            peso = init_peso+troca(&mat[0][1],&mat[0][2]);
            break;
        case 6:
            peso = init_peso+troca(&mat[0][2],&mat[0][3]);
            break;
        case 7:
            peso = init_peso+troca(&mat[1][0],&mat[1][1]);
            break;
        case 8:
            peso = init_peso+troca(&mat[1][1],&mat[1][2]);
            break;
        case 9:
            peso = init_peso+troca(&mat[1][2],&mat[1][3]);
            break;
        }
    }
    Cnt* copyCnt(){
        Cnt* new_cnt = new Cnt;
        for(short i = 0;i<4;i++)
            new_cnt->mat[0][i] = mat[0][i];
        for(short i = 0;i<4;i++)
            new_cnt->mat[1][i] = mat[1][i];
        return new_cnt;
    }

    void print(bool one_line = false){
        for(short i = 0;i<4;i++)
            cout << mat[0][i] << " ";
        if(!one_line)
            cout << endl;
        for(short i = 0;i<4;i++)
            cout << mat[1][i] << " ";
        cout << peso;
        if(!one_line)
            cout <<endl;
        cout << endl;
    }
};

vector <Cnt> vistos;
queue <Cnt*> fila;


//verifica se cnt ja tem um peso menor
//retorna true se acorreu alguma mudança em 'vistos'
bool update(Cnt* cnt){
    for(unsigned int i=0;i<vistos.size();i++){
        if(cnt->peso>=maxi)
            continue;
        if(vistos[i].isEqual(cnt)){//ja tem salvo
            if(vistos[i].peso > cnt->peso){//mas cnt tem peso menor
                vistos[i].peso = cnt->peso;
                //delete cnt;
                return true;
            }
            //delete cnt;
            return false;
        }
    }
    //cria um novo
    vistos.push_back(*cnt);
    return true;
}

//busca em largura

void busca(){
    Cnt* new_cnt, *cnt;
    while(!fila.empty()){
        cnt = fila.front();
        if(update(cnt)){//ocorreu mudanca
            for(int i=0;i<N_MOVES;i++){
                new_cnt = cnt->copyCnt();
                new_cnt->moveMat(i,cnt->peso);
                fila.push(new_cnt);
            }
        }
        fila.pop();
    }
    return;
}

int find_fin(Cnt* fin){
    for(unsigned int i=0;i<vistos.size();i++)
        if(vistos[i].isEqual(fin))
            return vistos[i].peso;
    return 0;
}

int main()
{
    Cnt init;
    Cnt fin;

    init.cinMat();
    fin.cinMat();

    init.peso = 0;

    fila.push(&init);
    busca();

    cout << find_fin(&fin);


    return 0;
}



