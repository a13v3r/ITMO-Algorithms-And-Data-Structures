#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool CmpToIntLower(int& a, int& b) {
    return a < b;
}


template<class T, class Compare>
vector<T> my_merge(vector<T>& a, int l1, int r1, int l2, int r2, Compare cmp) {
    vector<T> temp;
    while (l1 < r1 && l2 < r2) {
        if (cmp(a[l1], a[l2])) {
            temp.push_back(a[l1++]);
        } else {
            temp.push_back(a[l2++]);
        }
    }
    while (l1 < r1) temp.push_back(a[l1++]);
    while (l2 < r2) temp.push_back(a[l2++]);
    return temp;
}

template<class T, class Compare>
void MergeSortNotRecursive(vector<T>& a, Compare cmp = CmpToIntLower) {
    int step = 1;
    while (step < a.size()) {
        int i = 0;
        vector<T> b;
        while (i * 2 * step <= a.size()) {
            int l1 = i * 2 * step, r1 = l1 + step, l2 = l1 + step, r2 = min(l2 + step, (int) a.size());
            if (l2 < a.size()) {
                //merge(a.begin()+l1,a.begin()+r1,a.begin()+l2,a.begin()+r2, back_inserter(b));
                vector<T> tmp = my_merge(a, l1, r1, l2, r2, cmp);
                copy(tmp.begin(), tmp.end(), back_inserter(b));
            } else {
                r1 = min(l1 + step, (int) a.size());
                copy(a.begin() + l1, a.begin() + r1, back_inserter(b));
            }
            i++;
        }
        a = b;
        step += step;
    }
}

template<class T, class Compare>
void MergeSortRecursive(vector<T>& a, int left, int right, Compare& cmp = CmpToIntLower) {
    if (right - left <= 1) {
        return;
    }
    if (right - left == 2) {
        if (cmp(a[left], a[left + 1])) swap(a[left], a[left + 1]);
    }
    int mid = left + (right - left) / 2;
    MergeSortRecursive(a, left, mid, cmp);
    MergeSortRecursive(a, mid, right, cmp);
    //merge(a.begin()+left,a.begin()+mid,a.begin()+mid,a.begin()+right, back_inserter(tmp));
    vector<T> tmp = my_merge(a, left, mid, mid, right, cmp);
    copy(tmp.begin(), tmp.end(), a.begin() + left);
}


int main() {
    int size_of_input;
    std::cin >> size_of_input;
    vector<int> values(size_of_input);
    for (int i = 0; i < size_of_input; ++i) cin >> values[i];

    MergeSortRecursive(values, 0, size_of_input, CmpToIntLower);
    //MergeSortNotRecursive(values, CmpToIntLower);

    for (int i = 0; i < size_of_input; ++i) cout << values[i] << " ";

    return 0;
}