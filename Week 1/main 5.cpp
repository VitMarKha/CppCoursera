#include "iostream"
using namespace std;

int main ()
{
    double N, A, B, X, Y, result;
    cin >> N >> A >> B >> X >> Y;

    if (N <= A && N <= B)
    {
        result = N;
    }
    else if (N > B)
    {
        result = N - (N * (Y / 100));
    }
    else if (N > A)
    {
        result = N - (N * (X / 100));
    }
    cout << result;
    return 0;
}
