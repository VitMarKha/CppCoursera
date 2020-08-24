#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
using namespace std;

//Pair
template <typename First, typename Second>
pair<First, Second> operator*(pair<First, Second>& pairL, pair<First, Second>& pairR);

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second>& pair);

//Map
template <typename Key, typename Value>
map<Key, Value> operator*(map<Key, Value>& mapL, map<Key, Value>& mapR);

template <typename Key,typename Value>
map<Key, Value> Sqr(map<Key, Value>& map);

//Vector
template <typename T>
vector<T> operator*(vector<T>& v1,vector<T> v2);

template <typename T>
vector<T> Sqr(vector<T>& v);

//X
template <typename T>
T Sqr(T& x);



//Pair
template <typename First, typename Second>
pair<First, Second> operator*(pair<First, Second>& pairL, pair<First, Second>& pairR) {
    pairL.first = pairL.first * pairL.first;
    pairL.second = pairL.second * pairL.second;
    return pairL;
}
template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second>& pair) {
    pair = pair * pair;
    return pair;
}

//Map
template <typename Key, typename Value>
map<Key, Value> operator*(map<Key, Value>& mapL, map<Key, Value>& mapR) {
    for(auto& item : mapL) {
        item.second = item.second * item.second;
    }
    return mapL;
}
template <typename Key,typename Value>
map<Key, Value> Sqr(map<Key, Value>& map) {
    map = map * map;
    return map;
}

//Vector
template <typename T>
vector<T> operator*(vector<T>& v1,vector<T> v2) {
    for(auto& i : v1) {
        i = i * i;
    }
    return v1;
}
template <typename T>
vector<T> Sqr(vector<T>& v) {
    v = v * v;
    return v;
}

//X
template <typename T>
T Sqr(T& x) {
    x = x * x;
    return x;
}
