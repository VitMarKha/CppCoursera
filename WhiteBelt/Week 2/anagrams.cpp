#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        string first_word, second_word;
        cin >> first_word >> second_word;
        vector<char> first_word_char, second_word_char;

        for(const char& c : first_word) {
            first_word_char.push_back(c);
        }
        for(const char& c : second_word) {
            second_word_char.push_back(c);
        }

        sort(first_word_char.begin(), first_word_char.end());
        sort(second_word_char.begin(), second_word_char.end());

        if (first_word_char == second_word_char) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
