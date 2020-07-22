#include "iostream"
#include "string"
#include "map"
#include "algorithm"
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        year_first_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        year_last_name[year] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        const string first_name = FindName(year, year_first_name);
        const string last_name = FindName(year, year_last_name);

        if(first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else if(first_name.empty()) {
            return last_name + " with unknown first name";
        } else {
            return first_name + " " + last_name;
        }
    }
private:
    // приватные поля
    map<int, string> year_first_name;
    map<int, string> year_last_name;

    string FindName(const int& year, const map<int, string>& year_name) {
        string name;

        for(const auto& item : year_name) {
            if(item.first <= year) {
                name = item.second;
            } else {
                break;
            }
        }
        return name;
    }
};
