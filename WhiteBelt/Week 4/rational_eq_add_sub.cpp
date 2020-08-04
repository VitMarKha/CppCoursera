#include <sstream>
#include <iostream>
//#include "fstream"
//#include "string"
//#include "iomanip"
//#include "vector"
//#include "algorithm"
using namespace std;

int GreatestCommonFactor(int x, int y) {
    while (x > 0 && y > 0){
        if (x > y){
            x = x % y;
        }else{
            y = y % x;
        }
    }

    return x + y;
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
       int a = numerator, b = denominator, c = 0;
       while(b != 0) {
           c = a % b;
           a = b;
           b = c;
       }
       if(denominator / a < 0) {
           numerator = -numerator;
           denominator = -denominator;
       }
       p = numerator / a;
       q = denominator / a;
        //Проверка
        //cout << p << " " << q << endl;
    }

    int Numerator() const {
        // Реализуйте этот метод
        return p;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return q;
    }

private:
    // Добавьте поля
    int p;
    int q;
};

// Реализуйте для класса Rational операторы ==, + и -
Rational operator+(Rational lhs, Rational rhs) {
    if(lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
    } else {
        int leastCommonMultiple = lhs.Denominator() * rhs.Denominator() / GreatestCommonFactor(lhs.Denominator(), rhs.Denominator());
        int factor1 = leastCommonMultiple / lhs.Denominator();
        int factor2 = leastCommonMultiple / rhs.Denominator();
        return Rational((factor1 * lhs.Numerator() + factor2 * rhs.Numerator()), leastCommonMultiple);
    }
}

Rational operator-(Rational lhs, Rational rhs) {
    if(lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
    } else {
        int leastCommonMultiple = lhs.Denominator() * rhs.Denominator() / GreatestCommonFactor(lhs.Denominator(), rhs.Denominator());
        int factor1 = leastCommonMultiple / lhs.Denominator();
        int factor2 = leastCommonMultiple / rhs.Denominator();
        return Rational((factor1 * lhs.Numerator() - factor2 * rhs.Numerator()), leastCommonMultiple);
    }
}

bool operator==(Rational one, Rational two) {
    if(one.Numerator() == two.Numerator() && one.Denominator() == two.Denominator()) {
        return true;
    } else {
        return false;
    }
}


int main() {

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
