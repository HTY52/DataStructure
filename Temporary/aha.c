#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &a[i]);
    	// a[i] = i;
    }

    int t = n%2 ? n : n-1;

    for(int i = 0; i < t/2; i+=2) {
    	int temp = a[i];
    	a[i] = a[t - i - 1];
    	a[t - i - 1] = temp;
    }

    for (int i = 0; i < n; ++i) {
    	printf("%d ", a[i]);
    }

    return 0;
}
