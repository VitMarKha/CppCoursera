#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
#include "set"
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& map) {
    set<string> set;
    for(const auto& item : map) {
        set.insert(item.second);
    }
    return set;
}
