# Mod 3: técnicas

## Soma de prefixo

### Ideia soma de prefixo

Responder somas de intervalos em O(1) após um pré-processamento O(N), em 1D e 2D, e usar Difference Array para atualizações em intervalo.

Exemplo:
Tendo o saldo bancário do dia 10 e o do dia 4 você pode descobrir quanto entrou do dia 5 ao 10 fazendo:
saldo[10] - saldo[4]

Não precisando somar dia após dia.

### Origem soma prefixo

Você recebe um vetor de N números e precisa responder Q consultas do tipo "qual a soma dos elementos entre os índices L e R?". Somar na hora para cada consulta é O(N) por consulta. Com prefix sum, cada consulta vira O(1)

### Estrutura soma_prefixo

prefix[i] = prefix[i-1] + valor (esse valor seria o "original" - valor de i no vetor inicial)

### implementação soma_prefixo

vector<long long> a = {3, 1, 4, 1, 5, 9};
int n = a.size();
vector<long long> prefix(n + 1, 0);

for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + a[i];
}

// soma do intervalo [L, R] inclusivo:
long long somaIntervalo(int L, int R) {
    return prefix[R + 1] - prefix[L];
}

Isso pode ser de alguma forma uma matrix também, numa soma de prefixo 2d

### Implementação — Prefix Sum 2D (matriz)

cpp
int n, m;
vector<vector<long long>> grid;
vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
}

// OBS>: Lembrese de subtrair o prefix[i][j] pelo principio da inclusão e exclusão

// soma do retângulo com cantos (r1,c1) até (r2,c2), inclusivo:
long long somaRetangulo(int r1, int c1, int r2, int c2) {
    return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
}

### Problemas legais soma_prefixo

1- Soma de intervalo em vetor estático, múltiplas consultas (fácil)
2- Soma de submatriz em grid, múltiplas consultas (médio)
3- Quantidade de subarrays com soma exata igual a K, usando prefix sum + hashmap (médio/difícil)

#### Desafios soma_prefixo

- Responda Q consultas de soma de intervalo em O(1) cada.
- Some um valor V a todo um intervalo [L,R], Q vezes, e imprima o vetor final (difference array).
- Some a soma de uma submatriz para múltiplas consultas.
- Conte quantos subarrays têm soma exatamente igual a K.
- Ache o subarray de tamanho fixo K com maior soma (prefix sum + janela).

### onde não usar soma de prefixo

- Quando o vetor é atualizado com frequência e você precisa consultar somas a cada atualização — nesse caso prefira Fenwick Tree/BIT (Módulo 4)
- Quando as consultas não são de soma de intervalo (ex: máximo de intervalo precisa de Sparse Table ou Segment Tree)

### Difference Array

Técnica irmã

## two pointers
