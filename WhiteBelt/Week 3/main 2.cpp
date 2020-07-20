#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> vec(N);
    for(string& S : vec) {
        cin >> S;
    }
    sort(begin(vec), end(vec), [](string x, string y) {
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        transform(y.begin(), y.end(), y.begin(), ::tolower);
        return x < y;
    });
    for(const auto& i : vec) {
        cout << i << " ";
    }
    return 0;
}
