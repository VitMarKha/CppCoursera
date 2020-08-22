#include <map>
#include <vector>
using namespace std;

bool operator<(const Region& lhs, const Region& rhs) {
    tuple<string, string, map<Lang, string>, int64_t> lhs_tuple = {lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population};
    tuple<string, string, map<Lang, string>, int64_t> rhs_tuple = {rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population};
    return lhs_tuple < rhs_tuple;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int col = 0;
    map<Region, int> count;
    for(const auto& item : regions) {
        col = max(col, ++count[item]);
    }
    return col;
}
