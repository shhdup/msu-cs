#include<stdio.h>
#include<string.h>

char a[300], b[300], c[300];
int n;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void reverse(char *s) {
    char *b = s;
    while (*b) ++b; --b;
    while (s < b) {
        char tmp = *s; *s = *b; *b = tmp;
        ++s; --b;
    }
}

int lazy[300][2];

int solve(int i, int shift) {
    int *foo = &lazy[i][shift];
    if (*foo != -1) return *foo;
    if (i == n) return *foo = (shift == 0);
    for (char x = '0'; x <= '9'; ++x)
        if (a[i] == '?' || a[i] == x)
            for (char y = '0'; y <= '9'; ++y)
                if (b[i] == '?' || b[i] == y)
                    for (char z = '0'; z <= '9'; ++z)
                        if (c[i] == '?' || c[i] == z)
                            if ((shift+x+y-'0'-'0') % 10 == (z - '0'))
                                if (solve(i+1, (shift+x+y-'0'-'0') / 10)) {
                                    a[i] = x; b[i] = y; c[i] = z;
                                    return *foo = 1;
                                }
    return *foo = 0;
}

int main(void) {
    scanf("%[^+]+%[^=]=%s", a, b, c);
    int la = strlen(a), lb = strlen(b), lc = strlen(c);
    n = max(la, max(lb, lc));
    reverse(a); reverse(b); reverse(c);
    for (int i = la; i < n; ++i) a[i] = '0'; a[n] = 0;
    for (int i = lb; i < n; ++i) b[i] = '0'; b[n] = 0;
    for (int i = lc; i < n; ++i) c[i] = '0'; c[n] = 0;
    for (int i = 0; i < 300; ++i) {
        lazy[i][0] = -1; lazy[i][1] = -1;
    }
    if (solve(0, 0)) {
        a[la] = 0; b[lb] = 0; c[lc] = 0;
        reverse(a); reverse(b); reverse(c);
        printf("%s+%s=%s\n", a, b, c);
    } else {
        printf("No\n");
    }
    return 0;
}
