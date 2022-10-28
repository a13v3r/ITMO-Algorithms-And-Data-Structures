#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void radixSortStrings(vector<string> &a, int m){ //make sure size of all strings = m
    for (int digit = m - 1; digit >= 0; digit--) {
        vector<string> temp_arr;
        for (int letter = 0; letter <= 26; letter++) { //26 = 'z' - 'a' + 1
            for (string& item: a) {
                if (item[digit] == char(letter + 'a')) temp_arr.push_back(item);
            }
        }
        a = temp_arr;


    }
}

int get_digit(int elem, int pos){
    while (pos > 0){
        elem /= 10;
        pos--;
    }
    return elem % 10;
}

void radixSortInt(vector<int> &a, int m){
    for (int dig = 0; dig < m; ++dig) {
        int k = 10;
        vector<int> cnt(k, 0);
        for (auto el: a) {
            cnt[get_digit(el,dig)]++;
        }
        int count = 0;
        for (int number = 0; number < k; ++number) {
            int tmp = cnt[number];
            cnt[number] = count;
            count += tmp;
        }
        vector<int> carry(a.size(),0);

        for (int i = 0; i < a.size(); ++i) {
            int d = get_digit(a[i], dig);
            carry[cnt[d]++] = a[i];
        }
        a = carry;
    }
}

int main() {
    int size_of_input;
    std::cin >> size_of_input;
    vector<string> values(size_of_input);
    for (int i = 0; i < size_of_input; ++i) cin >> values[i];

    radixSortStrings(values,values[0].size());

    for (int i = 0; i < size_of_input; ++i) cout << values[i] << " ";

    return 0;
}