#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool CmpToIntLower(int &a, int &b){
    return a < b;
}


template<class T, class Compare>
void InsertionSort(vector<T> &a, Compare cmp = CmpToIntLower){
    for (int i = 1; i < a.size(); ++i) {
        int j = i-1;
        while  (j >= 0 && CmpToIntLower(a[j + 1], a[j])){
            swap(a[j+1],a[j]);
            j--;
        }
    }
}

int main(){
    int size_of_input;
    cin >> size_of_input;
    vector<int> values(size_of_input);

    for (int i = 0; i < size_of_input; ++i) cin >> values[i];

    InsertionSort(values, CmpToIntLower);

    for (int i = 0; i < size_of_input; ++i) cout<< values[i] << " ";

    return 0;
}
