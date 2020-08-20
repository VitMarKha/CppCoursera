#include <iostream>
#include <vector>

using namespace std;

int main() {
    int64_t N = 0;
    vector<int64_t> vec;
    cin >> N;

    for(int64_t i = 0; i < N; ++i) {
        int64_t c = 0;
        cin >> c;
        vec.push_back(c);
    }

    int64_t sum = 0;
    for(const auto& item : vec) {
        sum += item;
    }
    int64_t average = sum / static_cast<int64_t>(vec.size());

    vector<int64_t> new_vec;
    for(int64_t i = 0; i < static_cast<int64_t>(vec.size()); ++i) {
        if(vec[i] > average) {
            new_vec.push_back(i);
        }
    }

    //Вывод
    cout << new_vec.size() << endl;
    for(int64_t i = 0; i < static_cast<int64_t>(new_vec.size()); ++i ) {
        if(i == static_cast<int64_t>(new_vec.size() - 1)) {
            cout << new_vec[i];
        } else {
            cout << new_vec[i] << " ";
        }
    }

    return 0;
}
