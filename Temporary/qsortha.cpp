#include <iostream>
#include <cstdlib>

using namespace std;

int compare(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main() {

    int a[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = 1000 - i;
    }

    qsort(a, 10, sizeof(int), compare);

    for(int i : a) {
        cout << i << endl;
    }

    return 0;
}
