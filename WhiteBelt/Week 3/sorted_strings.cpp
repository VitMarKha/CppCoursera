#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        all_strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(all_strings), end(all_strings));
        return all_strings;
    }
private:
    vector<string> all_strings;
};
