#include <bits/stdc++.h>
using namespace std;
/*
map<pair<int,int>, int> → transforma um par (a,b) em um ID inteiro.

Lógica:
     chave             valor
       (a, b)              ID
       (2, 5)              0
       (3, 1)              1
       (7, 4)              2
*/

/*
Função lambda
*/

map<pair<int,int>, int> id;
int prox_id = 0;

auto get_id = [&](int a, int b) {
    if (id.find({a,b}) == id.end()) {
        id[{a,b}] = prox_id;
        prox_id++;
    }

    return id[{a,b}];
};

/*
Logida do .find
Se encontrou:
id.find({a,b}) != id.end()

Se não encontrou:
id.find({a,b}) == id.end()
*/