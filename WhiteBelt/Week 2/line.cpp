#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

int main () {
    int q;
    int i = 0;
    int people;
    int worries = 0;
    string comand;
    vector<int> turn;
    vector<int> forWorryCounts;
    cin >> q;

    while (i < q) {
        cin >> comand;

        if (comand == "WORRY") {
            cin >> people;
            turn[people] = true;
        } else if (comand == "QUIET") {
            cin >> people;
            turn[people] = 0;
        } else if (comand == "COME") {
            cin >> people;
            if (people > 0) {
                for (int r = 0; r < people; ++r) {
                    turn.push_back(0);
                }
            } else if (people < 0)
            {
                people *= -1;
                for (int y = 0; y != people; --people) {
                    turn.pop_back();
                }
            }
        } else if (comand == "WORRY_COUNT")
        {
            worries = 0;
            for (auto isTrue : turn) {
                if (isTrue == 1) {
                    worries += 1;
                }
            }
            forWorryCounts.push_back(worries);
        }
        ++i;
    }
    for (auto w : forWorryCounts) {
        cout << w << endl;
    }

    return 0;
}
