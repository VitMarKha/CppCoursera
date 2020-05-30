#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

int main ()
{
    const vector<int> dayInMounts = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 0;

    int q;
    cin >> q;
    vector<vector<string>> currentMonth(dayInMounts[month]);

    for (int i = 0; i < q; ++i)
    {
        string comand;
        cin >> comand;

        if (comand == "ADD")
        {
            int day;
            string s;
            cin >> day >> s;
            currentMonth[day - 1].push_back(s);

        }
        else if (comand == "DUMP")
        {
            int day;
            cin >> day;
            --day;

            cout << currentMonth[day].size() << " ";
            for (const string& concern : currentMonth[day])
            {
                cout << concern << " ";
            }
            cout << endl;
        }
        else if (comand == "NEXT")
        {
            const int tmpVector = dayInMounts[month];
            ++month;
            if (month > 11)
            {
                month = 0;
            }

            const int newTmpVector = dayInMounts[month];

            if (newTmpVector < tmpVector)
            {
                vector<string>& lastDayConcerns = currentMonth[newTmpVector - 1];

                for (int day = newTmpVector; day < tmpVector; ++day)
                {
                    lastDayConcerns.insert(end(lastDayConcerns), begin(currentMonth[day]), end(currentMonth[day]));
                }
            }
            currentMonth.resize(newTmpVector);
        }
    }

    return 0;
}
