#include <iostream>
#include <iomanip>
#include "../../include/mid_level/sqrt.h"

using std::cout;
using std::endl;
using std::setprecision;
using std::setiosflags;
using std::ios;

int main() {
    unsigned long a = 1, b = 13;
    asm ("bsr %1,%%eax ;"
         "movl %%eax,%0 ;"
    : "=m"(a)
    : "m" (b)
    );
    cout << "hello world! " << (1 << (a + 1)) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton(5000000000000.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton(0.0005f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton(0.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton(-1.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton((double)5000000000000.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton((double)0.0005f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton((double)0.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_newton((double)-1.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_fast(5000000000000.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_fast(0.0005f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_fast(0.0f) << endl;
    cout << setiosflags(ios::fixed) << setprecision(64) << sqrt_fast(-1.0f) << endl;
    return 0;
}