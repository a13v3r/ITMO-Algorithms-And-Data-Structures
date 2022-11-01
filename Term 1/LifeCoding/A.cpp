#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    string anagram;
    cin >> word >> anagram;
    int k_elements = 26;
    int word_letters[k_elements];
    int anagram_letters[k_elements];
    for (int i = 0; i < k_elements; ++i) {
        word_letters[i] = 0;
        anagram_letters[i] = 0;
    }

    for (char i : word) {
        word_letters[i-'a']++;
    }
    for (char i : anagram) {
        anagram_letters[i-'a']++;
    }
    bool t = true;
    for (int i = 0; i < k_elements; ++i) {
        if (word_letters[i] != anagram_letters[i]) {
            t = false;
            break;
        }
    }
    if (t)
        cout << "YES";
    else
        cout << "NO";
}