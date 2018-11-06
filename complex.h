#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>

using namespace std;

class Complex
{
    public:
        Complex(double a=0, double b=0);
        string toString();
        Complex operator+ (Complex);
        Complex operator+ (double);
        Complex operator+ (int);

        Complex operator- (Complex);
        Complex operator- (double);
        Complex operator- (int);
        Complex operator- ();

        Complex operator* (Complex);
        Complex operator* (double);
        Complex operator* (int);

        Complex operator/ (Complex);
        Complex operator/ (double);
        Complex operator/ (int);

        Complex conjugate();
        double real();
      	double imaginary();

        double a;
        double b;

    friend Complex pow(Complex c, int a);
};

#endif // COMPLEX_H
