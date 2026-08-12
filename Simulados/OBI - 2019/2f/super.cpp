#include <bits/stdc++.h>
using namespace std;


/* - Supermecado

- Comprar carne no mercado + barato

-> Usam B$.
-> X Bits por Y gramas de carne

*/
// 1 opt
struct mercado{double preco; int gramas;};

bool comp(mercado a, mercado b){
    // juntar pelas medias de preço
    return (a.gramas/a.preco) < (b.gramas/b.preco);
}
vector<mercado> mercados;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Duas opções:
    // 1- Valor é imutável, logo não podemos simplesmentes achar a média Bit/g e achar o Bit/kg.
    // Acredito mais provável
   
    int N; cin >> N; 

    for(int i=0; i<N;i++){
        mercado mer_at;
        cin >> mer_at.preco >> mer_at.gramas;
        
        mercados.push_back(mer_at);
    }
    
    sort(mercados.begin(), mercados.end(), comp);

    int carne_at = 0;
    int mercado_at = 0;
    double custo_at = 0;

    // Posso fazer um dp[i], i = primeiros mercados
    for(auto i : mercados){
        // 3 casos:
        // 1 - Comprar máximo até passar 1000 desejado no menor preço
        carne_at += i.gramas *((1000 - carne_at)/i.gramas);
        custo_at = ((1000 - carne_at)/i.gramas) *i.preco
        
        // 2 - possivel reduzir o preço


    }


    return 0;
    // 2 - Valor mudavel e podemos simplesmente calcular a média.

    int N; cin >> N; 
    vector<double> mercado_media;
    for(int i=0; i<N;i++){
        int P, G;
        cin >> P >> G;
        mercado_media.push_back(P/G);
        // manter 100 a mais, e depois dividir por 100 o resultado
    }   
    sort(mercado_media.begin(), mercado_media.end());

    cout << 1000 * mercado_media[0] << endl;
    // nn deu certo; obvio


}

// Estratégia fazer primeiro 2 -> Mais fácil, e depois 1 se não rodar 100/100 na submissão.