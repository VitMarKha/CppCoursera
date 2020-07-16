#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
#include "set"
using namespace std;

int main() {
    int Q;
    map<set<string>, int> numbers;
    int n = 1;
    cin >> Q;

    for(int i = 0; i < Q; ++i) {
        int N;
        cin >> N;
        set<string> stops;

        for(int j = 0; j < N; ++j) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        if(numbers.count(stops) == 0) {
            numbers[stops] = n;
            cout << "New bus " << numbers[stops] << endl;
            ++n;
        } else if(numbers.count(stops) == 1) {
            cout << "Already exists for " << numbers[stops] << endl;
        }
    }
    return 0;
}
