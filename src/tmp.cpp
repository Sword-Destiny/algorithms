#include <sys/mman.h>
#include <iostream>
#include <unistd.h>

using namespace std;

static const size_t len = 8192;

int main() {

    int *p = (int *) mmap(nullptr, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    int *pp = (int *) mmap(((char *)p) + len, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("p %p pp %p\n", p, pp);

    int size = len / sizeof(int);
    // read without write
    for (int i = 0; i < size; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    // write
    for (int i = 0; i < size; ++i) {
        p[i] = i;
    }

    // read first 2 page
    for (int i = 0; i < size; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    // unmap first page
    (void) munmap(p, len / 2);

    // read 2nd page
    for (int i = size / 2; i < size; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    // unmap 2nd page
    (void) munmap(p + len / 2, len / 2);

    int m;
    cin >> m;

    return 0;
}