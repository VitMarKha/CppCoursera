#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
using namespace std;

int main() {
    string path = "input.txt";
    ifstream input(path);

    for(double x; input >> x;) {
        cout << fixed << setprecision(3);
        cout << x << endl;
    }

    return 0;
}
