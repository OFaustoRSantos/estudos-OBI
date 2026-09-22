#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Função auxiliar para ordenar da MENOR palavra para a MAIOR
bool comparaTamanho(const string& a, const string& b) {
    return a.size() < b.size();
}

int main() {
    // ... (sua leitura dos dados) ...
    int N = usu_senhas.size();

    // 1. Ordenar por tamanho garante que a palavra_at só busca em strings maiores ou iguais
    sort(usu_senhas.begin(), usu_senhas.end(), comparaTamanho);

    long long n_pares = 0; // Usar long long evita overflow em N grandes
    vector<int> memo(N, -1);
    vector<int> pares_palavra(N, 0);

    for(int i = 0; i < N; i++) {
        // Usamos & (referência) para NÃO copiar a string na memória. É apenas um apelido!
        const string& palavra_at = usu_senhas[i];

        if(memo[i] != -1) {
            pares_palavra[i] = pares_palavra[memo[i]];
            n_pares += pares_palavra[i];
            continue;
        }

        for(int j = i + 1; j < N; j++) {
            const string& palavra_teste = usu_senhas[j];

            // Se forem idênticas
            if(palavra_at == palavra_teste) {
                n_pares++;
                pares_palavra[i]++;
                memo[j] = i; // Guarda para quando o loop principal chegar em J
            } 
            // Se forem de tamanhos diferentes, o find faz a busca mágica otimizada por hardware
            else if (palavra_teste.find(palavra_at) != string::npos) {
                n_pares++;
                pares_palavra[i]++;
            }
        }
    }

    cout << "Total de pares: " << n_pares << endl;
    return 0;
}