#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& new_str) {
        str = new_str;
    }

    string Reverse() {
        string new_str;
        for(int i = str.size() - 1; i >= 0; --i ) {
            new_str.push_back(str[i]);
        }
        str = new_str;
        return str;
    }
    string ToString() const {
        return str;
    }

private:
    string str;
};
