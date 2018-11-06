# Complex
Implementation of complex number using operator overload.

## Usage
Just import complex.cpp and use it.

### Example
```cpp
Complex c1(5,-7);
Complex c2(1,1);
Complex c3 = c1/c2;
cout << c3 << endl;
```
Output:
```
-1-6i
```
## To compile
```
g++ main.cpp -o complex
```
## To test
```
g++ -Wall tests/tests.cpp -o tests
```