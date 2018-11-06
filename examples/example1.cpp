#include <iostream>

#include "../complex.cpp"

using namespace std;

int main()
{
    Complex c1(5,-7);
    Complex c2(1,1);
    Complex c3 = c1/c2;
    cout  << c3 << endl;
    cout << -c1 << endl;
    Complex c4(4,10);
    Complex zero(0,0);
    cout << c1/zero << endl;
    cout << pow(c4,-2) << endl;
    
    return 0;
}

