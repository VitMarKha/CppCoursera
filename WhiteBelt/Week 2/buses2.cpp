#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
using namespace std;

int main() {
    int Q;
    cin >> Q;
    map<vector<string>, int> route;
    int stop_number = 1;

    for(int i = 0; i < Q; ++i) {
        int N;
        cin >> N;

        if(N > 0) {
            vector<string> stops;
            for(int j = 0; j < N; ++j) {
                string stop;
                cin >> stop;
                stops.push_back(stop);
            }
            if(route.count(stops) > 0) {
                cout << "Already exists for " << route[stops] << endl;
            } else {
                route[stops] = stop_number;
                cout << "New bus " << route[stops] << endl;
                ++stop_number;
            }
        }
    }
//    cout << endl;
//    //Проверка
//    for(const auto& item : route) {
//        for(const auto& c : item.first) {
//            cout << c << " ";
//        }
//        cout << ": " << item.second << endl;
//    }
    return 0;
}
