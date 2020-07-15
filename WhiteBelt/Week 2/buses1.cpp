#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
using namespace std;

int SearchInVector(const vector<string>& vec, const string& str) {
    int result = 0;

    for(const auto& c : vec) {
        if(c == str) {
            result = 1;
        }
    }
    return result;
}

int main() {
    int Q;
    map<string, vector<string>> route;
    vector<string> all_bus;
    cin >> Q;

    for(int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if(command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            all_bus.push_back(bus);

            route[bus];
            for(int j = 0; j < stop_count; ++j) {
                string stop_n;
                cin >> stop_n;

                route[bus].push_back(stop_n);
            }
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            int presence_of_stop = 0;
            cin >> stop;
            vector<string> stop_in_buses;

            for(const auto& item : route) {
                string bus = item.first;

                for(const auto& stop_n : item.second) {

                    if(stop_n == stop) {
                        stop_in_buses.push_back(bus);
                        //cout << bus << " ";
                        ++presence_of_stop;
                    }
                }
            }
            if(presence_of_stop == 0) {
                cout << "No stop" << endl;
            } else {
                for(const auto& b : all_bus) {

                    if(SearchInVector(stop_in_buses, b)) {
                        cout << b << " ";
                    }
                }
            }
            cout << endl;
        } else if(command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;

            if(route.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for(const auto& stop_n : route[bus]) {
                    cout << "Stop " << stop_n << ": ";
                    int buses = 0;
                    vector<string> buses_in_stop;

                    for(const auto& item : route) {

                        for(const auto& w : item.second) {

                            if(stop_n == w && item.first != bus) {
                                buses_in_stop.push_back(item.first);
//                                cout << item.first << " ";
                                ++buses;
                            }
                        }
                    }
                    if(buses == 0) {
                        cout << "no interchange";
                    } else {
                        for(const auto& b : all_bus) {

                            if(SearchInVector(buses_in_stop, b)) {
                                cout << b << " ";
                            }
                        }
                    }
                    cout << endl;
                }
            }
        } else if(command == "ALL_BUSES") {
            if(route.size() == 0) {
                cout << "No buses" << endl;
            } else {
                for(const auto& item : route) {
                    cout << "Bus " << item.first << ": ";

                    for(const auto& stop_n :item.second) {
                        cout << stop_n << " ";
                    }
                    cout << endl;
                }
//                map<string, vector<string>> route_sort = route.sort();
            }
        }
    }
    //Проверка
//    cout << endl;
//    for(const auto& item : route) {
//        cout << item.first << ": ";
//        for (const auto& w : item.second) {
//            cout << w << ", ";
//        }
//        cout << endl;
//    }
    return 0;
}
