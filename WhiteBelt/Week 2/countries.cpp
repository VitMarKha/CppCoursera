#include "iostream"
#include "string"
#include "map"
#include "algorithm"
using namespace std;

int main() {
    int Q;
    map<string, string> book;
    cin >> Q;

    for(int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if(command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;

            if(book.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                book[country] = new_capital;
            } else if(book.count(country) == 1 && book[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else if(book.count(country) == 1 && book[country] != new_capital) {
                string old_capital = book[country];
                cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
                book[country] = new_capital;
            }
        } else if(command == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;

            if(old_country_name == new_country_name || book.count(new_country_name) == 1 || book.count(old_country_name) == 0) {
                cout << "Incorrect rename, skip" << endl;
            } else if(book.count(old_country_name) == 1) {
                string capital = book[old_country_name];
                cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
                book.erase(old_country_name);
                book[new_country_name] = capital;
            }
        } else if(command == "ABOUT") {
            string country;
            cin >> country;

            if(book.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else if(book.count(country) == 1) {
                string capital = book[country];
                cout << "Country " << country << " has capital " << capital << endl;
            }
        } else if(command == "DUMP") {
            if(book.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                book.insert(book.begin(), book.end());
                for(const auto& item : book) {
                    cout << item.first << "/" << item.second << " ";
                }
            }
        }
    }

    return 0;
}
