#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// base sort using algo
bool cmp(int a, int b){
    return (a < b);
    // retorne true se a for menor que b e tiver que vir antes.
}
// a melhor função: struct >>>

// A lista tem que estar sorted
int binary_search(vector<int> list, int target){
    int left = 0;
    int right = list.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (list[mid] == target)
            return mid;

        if (list[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// bubble_sort:
int bubble_sort(vector<int> list){
    int pos_i = 0;
    

}

int main(){

}