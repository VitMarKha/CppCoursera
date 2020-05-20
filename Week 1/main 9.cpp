#include "iostream"
#include "vector"
using namespace std;

int main ()
{
    vector<int> result;
    int number;
    cin >> number;

    while (number > 0)
    {
        result.push_back(number % 2);
        number /= 2;
    }

    for (int i = result.size() - 1; i >= 0; --i)
    {
        cout << result[i];
    }
    
    return 0;
}
