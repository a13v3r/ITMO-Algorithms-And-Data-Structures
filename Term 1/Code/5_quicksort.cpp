#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool CmpToIntLower(int& a, int& b) {
    return a < b;
}

bool CmpToIntLowerEqual(int& a, int& b) {
    return a < b;
}

bool CmpToIntHigherEqual(int& a, int& b) {
    return a >= b;
}

bool CmpToIntHigher(int& a, int& b) {
    return a > b;
}


//Razbienie Lomuto
template<class T, class Compare>
int partitionLomuto(vector<T> &a,int l, int r, Compare &cmp) {
    T pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (cmp(a[j], pivot)){  //cmp: <= >=
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i + 1;
}

template<class T, class Compare>
void QuickSortL(vector<T> &a,int l, int r, Compare &cmp){
    if (l < r){
        int p = partitionLomuto(a,l,r,cmp);
        QuickSortL(a,l,p - 1,cmp);
        QuickSortL(a,p + 1,r,cmp);
    }
}


//Razbienie Hoara
template<class T, class Compare>
void QuickSortH(vector<T> &a,int l, int r, Compare &cmp){
    int i,j;
    T k = a[l + (r-l)/2];
    i = l;
    j = r;
    do {
        while (cmp(a[i],k)) i++;  // cmp: > <
        while (cmp(k,a[j])) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (l < j) QuickSortH(a,l,j,cmp);
    if (i < r) QuickSortH(a,i,r,cmp);
}

int main() {
    int size_of_input;
    std::cin >> size_of_input;
    vector<int> values(size_of_input);
    for (int i = 0; i < size_of_input; ++i) cin >> values[i];

    QuickSortH(values, 0, size_of_input - 1, CmpToIntLower);

    for (int i = 0; i < size_of_input; ++i) cout << values[i] << " ";

    return 0;
}

