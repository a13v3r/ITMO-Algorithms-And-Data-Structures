#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void CountingSort(vector<int>& a) {
    int maxn;
    for (int i = 0; i < a.size(); ++i) {
        maxn = max(maxn, a[i]);
    }
    maxn++;
    vector<int> cnt(maxn, 0);
    for (auto el: a) {
        cnt[el]++;
    }
    a.clear();
    a.resize(0);
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            a.push_back(i);
        }
    }
}

int main() {
    int size_of_input;
    std::cin >> size_of_input;
    vector<int> values(size_of_input);
    for (int i = 0; i < size_of_input; ++i) cin >> values[i];

    CountingSort(values);

    for (int i = 0; i < size_of_input; ++i) cout << values[i] << " ";

    return 0;
}