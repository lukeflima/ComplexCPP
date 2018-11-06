#include "complex.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Complex::Complex(double _a, double _b)
{
    a = _a;
    b = _b;
}

double Complex::real(){
	return a;
}

double Complex::imaginary(){
	return b;
}

Complex Complex::conjugate(){
	Complex c3(a,-1*b);
	return c3;
}

Complex Complex::operator+ (Complex c2)
{
    Complex c3(a + c2.a , b + c2.b);
	return c3;
}

Complex Complex::operator+(double x){
	Complex c3(a + x,b);
	return c3;
}

Complex Complex::operator+(int x){
	Complex c3(a + x,b);
	return c3;
}

Complex Complex::operator-()
{
	Complex c3(-a, -b);
	return c3;

}

Complex Complex::operator- (Complex c2)
{
	Complex c3(a - c2.a, b - c2.b);
	return c3;

}

Complex Complex::operator-(double x)
{
	Complex c3(a - x, b);
	return c3;

}

Complex Complex::operator-(int x)
{
	Complex c3(a - x, b);
	return c3;

}

Complex Complex::operator* (Complex c2)
{
    Complex c3(a*c2.a - b*c2.b, a*c2.b + b*c2.a);
	return c3;
}

Complex Complex::operator* (double x)
{
    Complex c3(a * x, b * x);
	return c3;
}

Complex Complex::operator* (int x)
{
    Complex c3(a * x, b * x);
	return c3;
}



Complex Complex::operator/ (Complex c2)
{
	if(!c2.a && !c2.b){
		throw string("Can't divide by zero.\n");
	}
    Complex c4 = (*this)*(c2.conjugate());
	Complex c5 = c2*((c2).conjugate());
	Complex c3;
    if(c5.a == 0){
    	c3.a = 0;
    	c3.b = 0;
        return c3;
    }
	c3.a = c4.a/c5.a;
    c3.b = c4.b/c5.a;

	return c3;
}

Complex Complex::operator/(double c)
{
	if(!c){
		throw string("Can't divide by zero.\n");
	}
    Complex c3(a/c,b/c);

	return c3;
}

Complex Complex::operator/ (int c)
{
    if(!c){
		throw string("Can't divide by zero.\n");
	}
    Complex c3(a/c,b/c);

	return c3;
}

ostream &operator<<(ostream &os, Complex const &c) { 
	ostringstream strs;
    ostringstream strs1;
    strs.precision(2);
    strs1.precision(2);
    strs << c.a;
    strs1 << c.b;
    string str;
    if(c.b > 0) str=strs.str() + "+" + strs1.str() + "i";
    else if(!c.b) str = strs.str();
    else str= strs.str() + "" + strs1.str() + "i";
    return os << str;
}

Complex pow(Complex c, int a)
{
    if(a == 0){
        Complex c3(0,0);
        return c3;
    }
    if(a == 1) return c;
    Complex c3(1,0);
	int i;
	if(a>0){
		for(i=0; i<a; i++)
			c3 = c3*c;
	}else{
		for(i=a; i<0; i++)
			c3 = c3/c;
	}
	return c3;
}
