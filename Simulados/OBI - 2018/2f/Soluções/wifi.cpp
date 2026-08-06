#include <bits/stdc++.h>
using namespace std;

struct Ret {

    int xmin, xmax;
    int ymin, ymax;

};

// Ordenamos primeiro pelo início.
//
// Se dois começam no mesmo lugar,
// colocamos primeiro o maior.
//
bool cmp(Ret a, Ret b){

    if(a.xmin != b.xmin)
        return a.xmin < b.xmin;

    return a.xmax > b.xmax;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Ret> v(N);

    for(int i=0;i<N;i++){

        int x1,y1,x2,y2;

        cin>>x1>>y1>>x2>>y2;

        v[i].xmin=min(x1,x2);
        v[i].xmax=max(x1,x2);

        v[i].ymin=min(y1,y2);
        v[i].ymax=max(y1,y2);

    }

    sort(v.begin(),v.end(),cmp);

    int resposta=0;

    int maiorX = -1;
    int menorY = INT_MAX;
    int maiorY = -1;

    for(auto r:v){

        bool contido=false;

        /*
            Se já existe um retângulo que

            termina mais à direita

            começa mais abaixo

            termina mais acima

            então ele contém este.
        */

        if(maiorX>=r.xmax &&
           menorY<=r.ymin &&
           maiorY>=r.ymax)

            contido=true;

        if(!contido)
            resposta++;

        /*
            Atualizamos nosso melhor candidato.

            Esse trecho é um padrão muito comum
            em Sweep Line.

            Vamos carregando informações
            suficientes sobre o passado.
        */

        if(r.xmax>maiorX){

            maiorX=r.xmax;
            menorY=r.ymin;
            maiorY=r.ymax;

        }else{

            menorY=min(menorY,r.ymin);
            maiorY=max(maiorY,r.ymax);

        }

    }

    cout<<resposta;
}