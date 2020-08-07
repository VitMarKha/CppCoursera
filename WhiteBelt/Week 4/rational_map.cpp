#include <iostream>
#include <sstream>
#include "assert.h" // <- Если ее убрать решение не проходит 3 часть
#include "set"
#include "vector"
#include "map"
//#include <sstream>
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

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator<(const Rational& lhs, const Rational& rhs) {
    if(lhs.Denominator() == rhs.Denominator()) {
        return lhs.Numerator() < rhs.Numerator();
    } else {
        int leastCommonMultiple = lhs.Denominator() * rhs.Denominator() / GreatestCommonFactor(lhs.Denominator(), rhs.Denominator());
        int factor1 = leastCommonMultiple / lhs.Denominator();
        int factor2 = leastCommonMultiple / rhs.Denominator();

        int one = factor1 * lhs.Numerator();
        int two = factor2 * rhs.Numerator();

        return one < two;

    }
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    if(lhs.Denominator() == rhs.Denominator()) {
        return lhs.Numerator() > rhs.Numerator();
    } else {
        int leastCommonMultiple = lhs.Denominator() * rhs.Denominator() / GreatestCommonFactor(lhs.Denominator(), rhs.Denominator());
        int factor1 = leastCommonMultiple / lhs.Denominator();
        int factor2 = leastCommonMultiple / rhs.Denominator();

        int one = factor1 * lhs.Numerator();
        int two = factor2 * rhs.Numerator();

        return one > two;

    }
}

int main() {

    //Проверка
//    Rational r1(1, 8);
//    Rational r2(2, 8);
//    if(r1 < r2) {
//        cout << "True";
//    } else {
//        cout << "No";
//    }

    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
