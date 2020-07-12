#include "string"
#include "vector"

using namespace std;

bool IsPalindrom(string str) {
    int firstChar = 0;
    int endChar = str.size() - 1;
    bool result;
    int i = 0;

    while (i < str.size()) {
        if (str[firstChar] == str[endChar]) {
            ++firstChar;
            --endChar;
            ++i;
        } else {
            break;
        }
    }
    if (i == str.size()) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;

    for (auto w : words) {
        if (IsPalindrom(w) && w.size() >= minLength) {
            result.push_back(w);
        }
    }
    
    return result;
}
