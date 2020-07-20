#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool comp(int x, int y) {
    if(x > 0 && y > 0) {
        return x < y;
    } else if(x < 0 && y < 0) {
        x = -x;
        y = -y;
        return x < y;
    } else if(x > 0 && y < 0) {
        y = -y;
        return x < y;
    } else if(x < 0 && y > 0) {
        x = -x;
        return x < y;
    }
}

int main() {
    int Q;
    vector<int> vec;
    cin >> Q;
    for(int i = 0; i < Q; ++i) {
        int n;
        cin >> n;
        vec.push_back(n);
    }
    sort(begin(vec), end(vec), comp);
    for(const auto& i : vec) {
        cout << i << " ";
    }
    return 0;
}
