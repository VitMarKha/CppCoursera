#include <map>
#include <stdexcept>

using namespace std;

template <typename Key, typename Value, typename T>
Value& GetRefStrict(map<Key, Value>& map, T t) {
    if (map.count(t) == 1) {
        return map.at(t);
    } else {
        throw runtime_error("");
    }
}
