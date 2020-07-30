#include "iostream"
#include "fstream"
#include "string"
using namespace std;

int main() {
    string path = "input.txt";
    ifstream input(path);
    ofstream output("output.txt");

    if(input) {
        string line;
        while(getline(input, line)) {
            output << line << endl;
        }
    } else {
        cout << "Error" << endl;
    }

    return 0;
}
