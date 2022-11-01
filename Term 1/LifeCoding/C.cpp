#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    int n;
    cin >> n >> word;
    int k_elements = 26;
    int word_letters[k_elements];
    for (int i = 0; i < k_elements; ++i) {
        word_letters[i] = 0;
    }
    for (char i: word) {
        word_letters[i - 'A']++;
    }
    bool t = false;
    int middle;
    for (int i = 0; i < k_elements; ++i) {
        if (word_letters[i] % 2 != 0) {
            if (!t) {
                middle = i;
                t = true;
            }
        }
        for (int j = 0; j < word_letters[i] / 2; ++j)
            cout << char(i + 'A');
        word_letters[i] /= 2;

    }
    if (t)
        cout << char(middle + 'A');
    for (int i = k_elements - 1; i >= 0; --i) {
        for (int j = 0; j < word_letters[i]; ++j)
            cout << char(i + 'A');
    }
}
