#include <iostream>

using namespace std;

class Rational {

private:
    int num;
    int den;

    int findGCD(int a, int b) const {
        if (b == 0) {
            return a;
        }
        else {
            return findGCD(b, a % b);
        }
    }

public:
    Rational(int numer, int denomin) {
        num = numer;
        den = denomin;
    }

    void print() const {
        cout << num << "/" << den;
    }

    void set(int numer, int denomin) {
        num = numer;
        den = denomin;
    }

    void reduce() {
        int gcd = findGCD(num, den);
        num /= gcd;
        den /= gcd;
    }

    bool compare(const Rational& с) const {
        return num == с.num && den == с.den;
    }

    Rational operator-(const Rational& с) const {
        int new_num = num * с.den - с.num * den;
        int new_den = den * с.den;
        return Rational(new_num, new_den);
    }

    Rational operator*(const Rational& с) const {
        int new_num = num * с.num;
        int new_den = den * с.den;
        return Rational(new_num, new_den);
    }

    Rational operator/(const Rational& с) const {
        int new_num = num * с.den;
        int new_den = den * с.num;
        return Rational(new_num, new_den);
    }


};

int main() {
    Rational r1(2, 4);
    Rational r2(3, 6);
    Rational r3(5, 6);


    cout << "r1 ";
    r1.print();
    cout << endl;
    cout << "r2 ";
    r2.print();
    cout << endl;


    r1.reduce();
    cout << "r1 ";
    r1.print();
    cout << endl;


    r2.set(4, 6);
    cout << "r2 ";
    r2.print();
    cout << endl;


    if (r1.compare(r2)) {
        cout << "r1 == r2" << endl;
    }
    else {
        cout << "r1 != r2" << endl;
    }

    cout << "---------------" << endl;

    Rational r4 = r3 - r2; 
    Rational r5 = r1 * r2; 
    Rational r6 = r2 / r3;  
    cout << "r4 ";
    r4.print();
    cout << endl;

    cout << "r5 ";
    r5.print();
    cout << endl;

    cout << "r6 ";
    r6.print();
    cout << endl;
}
