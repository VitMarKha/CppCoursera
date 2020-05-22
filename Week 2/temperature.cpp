#include "algorithm"
#include "vector"
#include "iostream"

using namespace std;

int main ()
{
    int n;
    int s;
    int ind = 0;
    int ind2 = 0;
    int all = 0;
    int sred;
    vector<int> v;
    vector<int> result;
    vector<int> index;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        v.push_back(s);
    }

    for (auto w : v)
    {
        all += w;
    }
    sred = all / n;

    while (ind < v.size())
    {
        if (v[ind] > sred)
        {
            result.push_back(ind2);
        }
        ++ind;
        ++ind2;
    }

    cout << result.size() << endl;

    for (auto w : result)
    {
        cout << w << " ";
    }
    
    return 0;
}
