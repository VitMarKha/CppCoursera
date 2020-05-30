#include "iostream"
#include "algorithm"
using namespace std;

int main ()
{
    string str;
    int index_f;
    int score = 0;

    cin >> str;
    int size = str.size() - 1;
    if (size == 0 && str[0] == 'f')
    {
        cout << -1;
    }
    else if (size == 0 && str[0] != 'f')
    {
        cout << -2;
    }
    else if (size > 0)
    {
        for (int i = 0; i <= str.size(); ++i)
        {
            if (str[i] == 'f')
            {
                index_f = i;
                score += 1;
                if (score == 2)
                {
                    cout << index_f;
                }
            }
            else if (i == str.size() && score == 1)
            {
                cout << -1;
            }
            else if (i == str.size() && score == 0)
            {
                cout << -2;
            }
        }
    }
    
    return 0;
}
