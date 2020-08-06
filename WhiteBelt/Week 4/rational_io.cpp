//#include <sstream>
#include <iostream>
#include <sstream>
#include "assert.h" // <- Если ее убрать решение не проходит 3 часть
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

// Реализуйте для класса Rational операторы << и >>
ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    if (stream) {
        int first = 0, second = 0;
        stream >> first;
        stream.ignore(1);
        stream >> second;
        if (second != 0) {
            rational = Rational(first, second);
        }
    }

    return stream;
}

int main() {

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
