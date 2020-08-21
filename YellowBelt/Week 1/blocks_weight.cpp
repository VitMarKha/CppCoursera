#include <iostream>

using namespace std;

int main() {
    uint64_t N, R;
    cin >> N >> R;

    uint64_t weight;
    uint64_t sum = 0;
    for(uint64_t i = 0; i < N; ++i) {
        uint64_t W, H, D;
        cin >> W >> H >> D;
        weight = (W * H * D) * R;
        sum += weight;
    }

    cout << sum;
    return 0;
}
