#include "iostream"
#include "fstream"
#include "string"
using namespace std;

void ReadFile(const string& path) {
    ifstream input(path);
    if(input) {
        string line;
        while(getline(input, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Error" << endl;
    }
}

int main() {
    string path = "input.txt";
    ReadFile(path);
    return 0;
}
