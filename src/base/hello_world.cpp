#include <iostream>

using std::cout;
using std::endl;

int main() {
    unsigned long a=1, b = 13;
    asm ("bsr %1,%%eax ;"
         "movl %%eax,%0 ;"
         : "=m"(a)
         : "m" (b)
    );
    cout << "hello world! " << (1<<(a+1)) << endl;
    return 0;
}