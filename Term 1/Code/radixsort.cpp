#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void radixSortLSD(vector<string> &a, int m){
    for (int i = m - 1; i >= 0; i--) {
        vector<string> temp_arr;
        for (int digit = 0; digit <= 26; digit++)
            for (string& item : a){
                if (item[digit] == char(digit + 'a')) temp_arr.push_back(item);
            }
        a = temp_arr;
    }
}

int main() {
    int size_of_input;
    std::cin >> size_of_input;
    vector<string> values(size_of_input);
    for (int i = 0; i < size_of_input; ++i) cin >> values[i];

    radixSortLSD(values,values[0].size());

    for (int i = 0; i < size_of_input; ++i) cout << values[i] << " ";

    return 0;
}