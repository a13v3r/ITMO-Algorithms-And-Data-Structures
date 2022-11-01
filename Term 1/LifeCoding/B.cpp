#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int input[n];
    int k_elements = 20000;
    int counting[k_elements];
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        counting[input[i] + 10000]++;
    }
    int j = 0;
    for (int i = 0; i < k_elements; ++i) {
        while (counting[i] > 0) {
            input[j] = i - 10000;
            counting[i]--;
            j++;
            cout << i - 10000;
        }
    }
}