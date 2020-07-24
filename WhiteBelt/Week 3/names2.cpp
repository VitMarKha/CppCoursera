#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
#include "set"
using namespace std;

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

vector<string> CreateVector(const map<int, string>& year_name, const int& year) {
    vector<string> result;
    for(const auto& item : year_name) {
        if(item.first <= year) {
            result.push_back(item.second);
        } else {
            break;
        }
    }
    return result;
}
vector<string> RemovingRepetitions(const vector<string>& all_names, const string& name) {
    vector<string> result;

    for(int i = 0; i < all_names.size(); ++i) {
        if(result.empty() || result.back() != all_names[i]) {
            result.push_back(all_names[i]);
        } else {
            continue;
        }
    }

    if(result[0] == name) {
        result.erase(result.begin());
    }

    return result;
}

string VectorInStr(const vector<string>& sorted_names) {
    string result;

    int lastIndex = sorted_names.size() - 1;
    for(int i = 0; i < sorted_names.size(); ++i) {
        if(i != lastIndex) {
            result += sorted_names[i] + ", ";
        } else {
            result += sorted_names[i];
        }
    }

    return result;
}

string FindOldNames(const int& year, const map<int, string>& year_name, const string& name) {
    string str;
    vector<string> all_names;

    if(name.empty()) {
        return str;
    }

    //Создание вектора
    all_names = CreateVector(year_name, year);

    //Сортировка в обратном порядке
    reverse(begin(all_names), end(all_names));

    //Удаление первого элемента из вектора так как это последнее имя, то есть оно выводится в любом случае
    all_names.erase(all_names.begin());

    vector<string> sorted_names;
    if (all_names.size() > 1) {
        //Удаление повоторов
        sorted_names = RemovingRepetitions(all_names, name);

        if(sorted_names.size() == 1) {
            if(sorted_names[0] == name) {
                return str;
            } else {
                str += sorted_names[0];
                return str;
            }
        }
        //Из вектора в строку
        str = VectorInStr(sorted_names);
    }

    if(all_names.size() == 1) {
        if(all_names[0] == name) {
            return str;
        } else {
            str += all_names[0];
        }
    }

    //Проверка
//    cout << str << endl;
//    for(const auto& i : all_names) {
//        cout << i << " ";
//    }
//    cout << endl;
    return str;
}

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
    string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
        string first_name = FindName(year, year_first_name);
        string last_name = FindName(year, year_last_name);
        string old_firs_name = FindOldNames(year, year_first_name, first_name);
        string old_last_name = FindOldNames(year, year_last_name, last_name);

        if(first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        else if (last_name.empty() && !old_firs_name.empty()) {
            return first_name + " (" + old_firs_name + ")" + " with unknown last name";
        }
        else if (last_name.empty() && old_firs_name.empty()) {
            return first_name + " with unknown last name";
        }
        else if(first_name.empty() && !old_last_name.empty()) {
            return last_name + " (" + old_last_name + ")" + " with unknown first name";
        }
        else if(first_name.empty() && old_last_name.empty()) {
            return last_name + " with unknown first name";
        }
        else if(old_firs_name.empty() && old_last_name.empty()) {
            return first_name + " " + last_name;
        }
        else if (!old_firs_name.empty() && old_last_name.empty()){
            return first_name + " (" + old_firs_name + ")" + " " + last_name;
        }
        else if (old_firs_name.empty() && !old_last_name.empty()) {
            return first_name + " " + last_name + " (" + old_last_name + ")";
        }
        else {
            return first_name + " (" + old_firs_name + ")" + " " + last_name + " (" + old_last_name + ")";
        }
    }
private:
    // приватные поля
    map<int, string> year_first_name;
    map<int, string> year_last_name;
};
