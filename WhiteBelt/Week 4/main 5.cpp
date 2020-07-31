#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "vector"
using namespace std;

int main() {
    string path = "input.txt";
    ifstream input(path);

    int N, M;
    int tmp;
    input >> N;
    input >> M;

    for(int i = 0; i < N; ++i) {
        vector<int> line;
        for(int j = 0; j < M; ++j) {
            input >> tmp;
            input.ignore(1);
            line.push_back(tmp);
        }

        if (i < N - 1) {
            int l = 0;
            for (const auto &item : line) {
                if (l != line.size() - 1) {
                    cout << setw(10) << item << " ";
                } else {
                    cout << setw(10) << item;
                }
                ++l;
            }
            cout << endl;
        } else {
            int g = 0;
            for (const auto &item : line) {
                if (g != line.size() - 1) {
                    cout << setw(10) << item << " ";
                } else {
                    cout << setw(10) << item;
                }
                ++g;
            }
        }
    }

    //Проверка
//    cout << N << " " << M << endl;
//    for(const auto& item : line) {
//        cout << item << " ";
//    }

    return 0;
}
