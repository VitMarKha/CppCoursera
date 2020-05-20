using namespace std;

int Factorial(int x)
{
    int number = 1;
    int fact = 1;
    int result;

    if (x > 0)
    {
        while (number <= x)
        {
            fact *= number;
            ++number;
        }
        result = fact;
    }
    else
    {
        result = 1;
    }

    return result;
}
