//#include <sstream>
#include <iostream>
#include "assert.h"
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

// Реализуйте для класса Rational операторы * и /
Rational operator*(Rational lhs, Rational rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(Rational lhs, Rational rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

bool operator==(Rational one, Rational two) {
    return one.Numerator() == two.Numerator() && one.Denominator() == two.Denominator();
}


int main() {

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
