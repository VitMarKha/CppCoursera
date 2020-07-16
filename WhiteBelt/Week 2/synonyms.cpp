#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
#include "set"
using namespace std;

int main() {
    int Q;
    set<set<string>> vocabulary;
    map<string, int> col_synonyms;
    cin >> Q;

    for(int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if(command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            if(vocabulary.count({word1, word2}) == 0) {
                vocabulary.insert({word1, word2});
                ++col_synonyms[word1];
                ++col_synonyms[word2];
            }
        } else if (command == "COUNT") {
            string word;
            cin >> word;
            cout << col_synonyms[word] << endl;
        } else if(command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if(vocabulary.count({word1, word2}) > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
