#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct mono {
    long a;
    long b;
    long n;
};

int less(const void *aa, const void *bb) {
    const struct mono *a = aa;
    const struct mono *b = bb;
    if ((*a).n > (*b).n) return -1;
    if ((*a).n < (*b).n) return 1;
    if ((*a).a > (*b).a) return 1;
    if ((*a).a < (*b).a) return -1;
    if ((*a).b > (*b).b) return 1;
    if ((*a).b < (*b).b) return -1;
    return 0;
}

int gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

char s[100001];
char* ss;

struct mono parse(int l, int r) {
    struct mono foo;
    foo.a = (ss[l++] == '+' ? 1 : -1);
    foo.b = 0;
    foo.n = 0;
    int cr = l;
    int bar = 0;
    int ne = 0;
    while (cr < r && '0' <= ss[cr] && ss[cr] <= '9') {
        bar = 10*bar + (ss[cr++] - '0');
        ne = 1;
    }
    if (ne) foo.a = foo.a * bar;
    l = cr;
    if (l == r) return foo;
    if (ss[l] == '*') ++l; foo.n = 1; ++l;
    if (l == r) return foo;
    ++l;
    foo.n = 0;
    while (l < r) foo.n = foo.n*10 + (ss[l++] - '0');
    return foo;
}

struct mono integral(struct mono foo) {
    long g = gcd(foo.a, foo.n+1);
    struct mono ans;
    ans.a = foo.a / g;
    ans.b = (foo.n+1) / g;
    if (ans.b < 0) {
        ans.a = -ans.a; ans.b = -ans.b;
    }
    ans.n = foo.n + 1;
    return ans;
}

int main(void) {
    struct mono poly[100000];
    int polysize = 0;
    fgets(s, 100000, stdin);
    int n = strlen(s)-1;

    char tts[100002];
    char* ts = tts+1;
    int tss = 0;
    char var = 'x';
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') ts[tss++] = s[i];
        if ('a' <= s[i] && s[i] <= 'z') var = s[i];
    }
    ts[tss] = 0;
    n = tss;
    ss = ts;

    if (ss[0] != '+' && ss[0] != '-') {
        --ss; ss[0] = '+'; ++n;
    }

    int r;
    for (int i = 0; i < n; i = r) {
        r = i+1;
        while (r < n && ss[r] != '+' && ss[r] != '-') ++r;
        poly[polysize++] = integral(parse(i, r));
    }

    qsort(poly, polysize, sizeof(*poly), less);

    int first = 1;
    for (int i = 0; i < polysize; ++i) {
        if (poly[i].a == 0) continue;
        if (first) {
            if (poly[i].a < 0) printf("-");
        } else {
            if (poly[i].a < 0) printf(" - "); else printf(" + ");
        }
        first = 0;
        if (poly[i].a < 0) poly[i].a *= -1;
        if (poly[i].a != 1 || poly[i].b != 1) printf("%ld", poly[i].a);
        if (poly[i].b != 1) printf("/%ld", poly[i].b);
        if (poly[i].a != 1 || poly[i].b != 1) printf("*");
        printf("%c", var);
        if (poly[i].n != 1) printf("^%ld", poly[i].n);
    }
    if (!first) printf(" + ");
    printf("C\n");
    return 0;
}
