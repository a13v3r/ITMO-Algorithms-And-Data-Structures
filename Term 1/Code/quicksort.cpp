#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool CmpToIntLower(int& a, int& b) {
    return a < b;
}

//Razbienie Lomuto


//Razbienie Hoara
template<class T, class Compare>
void QuickSort(vector<T>& a, int l, int r, Compare& cmp) {
    int i, j;
    auto k = a[l + (r - l) / 2];
    i = l;
    j = r;
    do {
        while (cmp(a[i], k)) i++;
        while (cmp(k, a[j])) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (l < j) QuickSort(a, l, j, cmp);
    if (i < r) QuickSort(a, i, r, cmp);
}


int main() {
    int size_of_input;
    std::cin >> size_of_input;
    vector<int> values(size_of_input);
    for (int i = 0; i < size_of_input; ++i) cin >> values[i];

    QuickSort(values, 0, size_of_input - 1, CmpToIntLower);

    for (int i = 0; i < size_of_input; ++i) cout << values[i] << " ";

    return 0;
}

