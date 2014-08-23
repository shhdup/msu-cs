#include <stdio.h>

long v[100000];

int main(void) {
    long n = 0;
    long t;
    while (scanf("%ld", &t)) {
        if (!t) break;
        v[n++] = t;
    }
    for(int i = 0; i < n; i+=2) {
        printf("%ld ", v[i]);
    }
    for(int i = n - 1 - (n % 2); i >= 0; i -= 2) {
        printf("%ld ", v[i]);
    }
    printf("\n");
    return 0;
}
