#include<stdio.h>

struct point {
    int x, y;
};

struct point diff(struct point a, struct point b) {
    struct point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

struct point read_point(void) {
    struct point foo;
    scanf("%d%d", &foo.x, &foo.y);
    return foo;
}

int points_readed, n;
struct point v0, v1;

struct point get_point(void) {
    if (++points_readed <= n) return read_point();
    if (points_readed == n+1) return v0;
    return v1;
}

int wedge_product(struct point a, struct point b) {
    return a.x*b.y - a.y*b.x;
}

int clockwise2(struct point a, struct point b) {
    int foo = a.x*b.y - a.y*b.x;
    return foo ? (foo > 0 ? 1 : -1) : 0;
}

int clockwise(struct point a, struct point b, struct point c) {
    return clockwise2(diff(b, a), diff(c, a));
}

int main(void) {
    points_readed = 0;

    scanf("%d", &n);
    v0 = get_point();
    v1 = get_point();

    struct point prev2 = v0;
    struct point prev1 = v1;

    int direct = 0;
    for (int i = 2; i < n+2; ++i) {
        struct point cur = get_point();
        int curdir = clockwise(prev2, prev1, cur);
        if (curdir != direct) {
            if (direct) {
                printf("No\n");
                return 0;
            } else {
                direct = curdir;
            }
        }
        prev2 = prev1;
        prev1 = cur;
    }

    printf("Yes\n");

    return 0;
}
