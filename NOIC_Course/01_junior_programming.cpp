#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum_range(){
    vector<int> list;
    int q = 0;
    cin >> q;
    int at = 0;
    for(int i = 0; i<q; i++){
        at = 0;
        cin >> at;
        list.push_back(at);
    }
    
    vector<int> sum;
    sum.push_back(list[0]);
    for(int i = 1; i < list.size(); i++){
        v.push_back(s[i-1] + list[i]);
    }
    int l,r;
    int n;
    cin >> n;
    for(int i =0; i<n;i++){
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    
    }
}

// https://olimpiada.ic.unicamp.br/pratique/p1/2017/f1/cofre/

int 2017_f_1_p_1(){
    return 0;
}

// https://olimpiada.ic.unicamp.br/pratique/p2/2019/f1/soma/

int 2019_f_1_p_2(){
    return 0;
}

int binary_search(vector<int> &list, int e){
    sort(list.begin(), list.end());
    // position upper, position down
    int p_upper = list.size() -1;
    int p_down = 0;
    int meio = 0;
    while (p_upper - p_down != 0){
        meio = (p_upper + p_down)/2;
        if(list[meio] == e){
            return meio;
            break;
        }
        else if (list[meio] > e){
            p_upper = meio - 1;
            
        } else{
            p_down = meio + 1;
        }
    }

    return -1;
}
// OBs, c++ tem uma função que faz isso, upper_bound(x)
int busca_lower_bound(int x)
{
	int ini = 1, fim = n;
	int ans = -1; // resposta da pergunta, que inicialmente será -1

	while (ini <= fim)
	{
		int mid = (ini+fim)/2; // meio do intervalo

		if (V[mid] >= x)
		{
			ans = V[mid]; // possível resposta
			fim = mid-1; // reduzo o intervalo para a metade esquerda
		}
		else ini = mid+1; // reduzo o intervalo para a metade direita, já que V[mid] < x
	}

	return ans;
}