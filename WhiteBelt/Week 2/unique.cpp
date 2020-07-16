#include "iostream"
#include "string"
#include "set"
using namespace std;

int main() {
    int Q;
    set<string> set;
    cin >> Q;
    for(int i = 0; i < Q; ++i) {
        string str;
        cin >> str;
        set.insert(str);
    }
    cout << set.size();
    return 0;
}
