#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "vector"
using namespace std;

struct Student {
    string first_name;
    string last_name;
    int day;
    int mouth;
    int year;
};

int main() {
    Student student;
    vector<Student> allStudents;
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> student.first_name >> student.last_name >> student.day >> student.mouth >> student.year;
        allStudents.push_back(student);
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; ++i) {
        string command;
        int number;
        cin >> command >> number;
        --number;

        if(command == "name") {

            if (number >= 0 && number < N) {
                cout << allStudents[number].first_name << " " << allStudents[number].last_name << endl;
            } else {
                cout << "bad request" << endl;
            }

        } else if (command == "date") {

            if(number >= 0 && number < N) {
                cout << allStudents[number].day << "." << allStudents[number].mouth << "." << allStudents[number].year << endl;
            } else {
                cout << "bad request" << endl;
            }

        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}
