#include "iostream"
#include "string"
#include "vector"
using namespace std;

int main() {
    int Q;
    const vector<int> YEAR = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 0;
    vector<vector<string>> current_month(YEAR[month]);
    cin >> Q;

    for (int i = 1; i <= Q; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            int day;
            string task;
            cin >> day;
            cin >> task;
            current_month[--day].push_back(task);
        } else if (command == "DUMP") {
            int day;
            cin >> day;
            cout << current_month[--day].size() << " ";
            for (auto c : current_month[day]) {
                cout << c << " ";
            }
            cout << endl;
        } else if (command == "NEXT") {
            int previous_month = YEAR[month];
            ++month;
            int new_month;
            if (month == 12) {
                month = 0;
                new_month = YEAR[month];
            } else {
                new_month = YEAR[month];
            }
            if (new_month < previous_month) {
                vector<string> tmp;
                for (int step = new_month; step < previous_month; ++step) {
                    for (auto& c : current_month[step]){
                        tmp.push_back(c);
                    }
                }
                --new_month;
                for (auto c : tmp) {
                    current_month[new_month].push_back(c);
                }
                new_month = new_month + 2;
                for (int step = new_month; step <= previous_month; ++step){
                    current_month.pop_back();
                }
            } else {
                current_month.resize(current_month.size() + (new_month - previous_month));
            }
        }
    }
//Проверка
//    cout << endl;
//    int i = 1;
//    int j = 1;
//    for (auto v1 : current_month) {
//        cout << "День " << i << endl;
//        for (auto v2 : v1) {
//            cout << "Задача " << j << " " << v2 << endl;
//            ++j;
//        }
//        ++i;
//    }
//    cout << "Размер месяца: " << current_month.size();
    return 0;
}
