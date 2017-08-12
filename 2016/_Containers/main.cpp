/****************************************************
https://www.urionlinejudge.com.br/judge/en/problems/view/2237
CordeiroLibel   2017
Status:
****************************************************/

#include <iostream>
#include <map>
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
    short pos[2][4];
    int peso;
    int id;
    Cnt(){
        peso = INF;
    }
    bool isEqual(Cnt* cnt){
        for(short i = 0;i<4;i++)
            if(cnt->mat[0][i]!=mat[0][i])
                return false;
        for(short i = 0;i<4;i++)
            if(cnt->mat[1][i]!=mat[1][i])
                return false;
        return true;
    }

    void idFix(){
        id = 0;
        id+= pos[0][0]*1;
        id+= pos[0][1]*8;
        id+= pos[0][2]*64;
        id+= pos[0][3]*512;
        id+= pos[1][0]*4096;
        id+= pos[1][1]*32768;
        id+= pos[1][2]*262144;
        id+= pos[1][3]*2097152;
    }

    void initFix(){
        int cont = 0;
        map<int,int>::iterator itv;
        map <int,int> vals;
        for(short i = 0;i<4;i++,cont++){
            itv = vals.find(mat[0][i]);
            if(itv==vals.end()){//nao tinha
                pos[0][i] = cont;
                vals[mat[0][i]] = 0*10+i;
            }
            else{//tinha
                pos[1][i] = pos[itv->second/10][itv->second%10];
            }
        }
        for(short i = 0;i<4;i++,cont++){
            itv = vals.find(mat[1][i]);
            if(itv==vals.end()){//nao tinha
                pos[1][i] = cont;
                vals[mat[1][i]] = 1*10+i;
            }
            else{//tinha
                pos[1][i] = pos[itv->second/10][itv->second%10];
            }
        }
        idFix();

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
            troca(&pos[0][0],&pos[1][0]);
            break;
        case 1:
            peso = init_peso+troca(&mat[0][1],&mat[1][1]);
            troca(&pos[0][1],&pos[1][1]);
            break;
        case 2:
            peso = init_peso+troca(&mat[0][2],&mat[1][2]);
            troca(&pos[0][2],&pos[1][2]);
            break;
        case 3:
            peso = init_peso+troca(&mat[0][3],&mat[1][3]);
            troca(&pos[0][3],&pos[1][3]);
            break;
        case 4:
            peso = init_peso+troca(&mat[0][0],&mat[0][1]);
            troca(&pos[0][0],&pos[0][1]);
            break;
        case 5:
            peso = init_peso+troca(&mat[0][1],&mat[0][2]);
            troca(&pos[0][1],&pos[0][2]);
            break;
        case 6:
            peso = init_peso+troca(&mat[0][2],&mat[0][3]);
            troca(&pos[0][2],&pos[0][3]);
            break;
        case 7:
            peso = init_peso+troca(&mat[1][0],&mat[1][1]);
            troca(&pos[1][0],&pos[1][1]);
            break;
        case 8:
            peso = init_peso+troca(&mat[1][1],&mat[1][2]);
            troca(&pos[1][1],&pos[1][2]);
            break;
        case 9:
            peso = init_peso+troca(&mat[1][2],&mat[1][3]);
            troca(&pos[1][2],&pos[1][3]);
            break;
        }
        idFix();
    }
    Cnt* copyCnt(){
        Cnt* new_cnt = new Cnt;
        for(short i = 0;i<4;i++){
            new_cnt->mat[0][i] = mat[0][i];
            new_cnt->pos[0][i] = pos[0][i];
        }
        for(short i = 0;i<4;i++){
            new_cnt->mat[1][i] = mat[1][i];
            new_cnt->pos[1][i] = pos[1][i];
        }
        new_cnt->id = id;
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

map<int,Cnt> vistos;
map<int,Cnt>::iterator it;
queue <Cnt*> fila;


map<int,Cnt>::iterator findCnt(Cnt* cnt){
    for (it=vistos.begin(); it!=vistos.end(); ++it)
        if(it->second.isEqual(cnt))
            return it;
    return vistos.end();
}

//verifica se cnt ja tem um peso menor
//retorna true se acorreu alguma mudança em 'vistos'
bool update(Cnt* cnt){

    it = vistos.find(cnt->id);
    //it = findCnt(cnt);

    if (it == vistos.end()){//nao tinha
        //cria um novo
        vistos[cnt->id] = *cnt;
        return true;
    }

    if(it->second.peso > cnt->peso){//tinha, mas cnt tem peso menor
        it->second.peso = cnt->peso;
        //delete cnt;
        return true;
    }
    //delete cnt;
    return false;
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
    for (it=vistos.begin(); it!=vistos.end(); ++it)
        if(it->second.isEqual(fin)){
            return it->second.peso;
        }
    return 0;
}

int main()
{
    Cnt init;
    Cnt fin;

    init.cinMat();
    init.initFix();

    fin.cinMat();

    init.peso = 0;

    fila.push(&init);
    busca();

    cout << find_fin(&fin);


    return 0;
}
