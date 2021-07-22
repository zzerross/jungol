#include <cstdio>
#include <algorithm>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define S 1000

int M, N, P, E, H = 0;

struct Point {
    int y, x;
} A[S];

void dump() {
#ifdef use_pr
    _pr("E=%d\n", E);

    for (int i = 0; i < E; i++)
        _pr("%3d: %5d %5d\n", i, A[i].y, A[i].x);
#endif
}

int max(int i, int j) {
    return i > j ? i : j;
}

bool cmp(struct Point& a, struct Point& b) {
    if (a.x < b.x)
        return true;

    return a.y < b.y;
}

int solve(int h, int x, int e, int p) {
    if (E <= e)
        return p < P;

    if (P <= p)
        return 0;

    if (solve(h, x, e + 1, p))
        return 1;

    if (solve(A[e].x + h, x, e + 1, p + 1))
        return 1;

    return 0;
}

int main() {
    scanf("%d %d %d %d", &M, &N, &P, &E);

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &A[i].y, &A[i].x);

        H = max(H, A[i].y); 

        _pr("%3d: %5d %5d\n", i, A[i].y, A[i].x);
    }

    dump();

    std::sort(A, A + E, cmp);

    int h = H;

    while (h++)
        if (solve(h, 0, 0, 0))
            break;

    printf("%d\n", h);

    return 0;
}
