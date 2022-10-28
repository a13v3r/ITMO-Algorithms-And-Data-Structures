#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void SimpleCountingSort(vector<int>& a) {
    int maxn = 0;
    for (int i = 0; i < a.size(); ++i) {
        maxn = max(maxn, a[i]);
    }
    maxn++;
    vector<int> cnt(maxn, 0);
    for (auto el : a) {
        cnt[el]++;
    }
    a.clear();
    a.resize(0);
    for (int number = 0; number < maxn; ++number) {
        for (int j = 0; j < cnt[number]; ++j) {
            a.push_back(number);
        }
    }
}

void CountingSort(vector<int>& a) {
    int maxn = 0;
    for (int i = 0; i < a.size(); ++i) {
        maxn = max(maxn, a[i]);
    }
    maxn++;
    vector<int> cnt(maxn, 0);
    for (auto el : a) {
        cnt[el]++;
    }
    for (int number = 1; number < maxn; ++number) {
        cnt[number] += cnt[number - 1];
    }
    vector<int> carry(a.size(), 0);

    for (int i = a.size() - 1; i >= 0; --i) {
        carry[--cnt[a[i]]] = a[i];
    }
    a = carry;
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