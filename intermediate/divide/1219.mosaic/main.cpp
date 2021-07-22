#include <cstdio>
#include <algorithm>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define S 1000
#define Z 1000//000

int Y, X, P, E, H = 0, M[Z][Z] = { 0, };

struct Point {
    int y, x;

    bool operator<(struct Point& b) {
        struct Point& a = *this;
 
        if (a.x < b.x)
            return true;

        return a.y < b.y;
    }
} A[S];

void dump() {
#ifdef use_pr
    _pr("E=%d\n", E);

    for (int i = 0; i < E; i++)
        _pr("%3d: %5d %5d\n", i, A[i].y, A[i].x);

    _pr("%3s> ", "M");

    for (int j = 1; j <= X; j++)
        _pr("%d ", j % 10);

    _pr("\n");

    for (int i = Y; 1 <= i; i--) {
        _pr("%3d: ", i);

        for (int j = 1; j <= X; j++)
            _pr("%c ", M[i][j] ? 'x' : '.');

        _pr("\n");
    }
#endif
}

int min(int i, int j) {
    return i < j ? i : j;
}

int max(int i, int j) {
    return i > j ? i : j;
}

void msrt(struct Point* a, int n) {
    struct Point b[S];
    int i, j;

    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            int l = p;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (i = 0; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = b[i] < b[j] ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int main() {
#ifdef use_pr
    setbuf(stdout, NULL);
#endif

    scanf("%d %d %d %d", &Y, &X, &P, &E);

    for (int e = 0; e < E; e++) {
        scanf("%d %d", &A[e].y, &A[e].x);

        H = max(H, A[e].y); 

        _pr("%5s: e=%4d %5d %5d\n", "input", e, A[e].y, A[e].x);

#ifdef use_pr
        M[A[e].y][A[e].x] = 1;
#endif
    }

    msrt(A, E);
    dump();

    int h = H, p = P;

    for (int x, e = 0; h <= Y; h++) {
        p = P - 1;

        _pr("%3d>\n", h);

        for (x = A[0].x + h, e = 1; e < E && x <= X && 0 < p; e++) {
            if (x <= A[e].x) {
                if (A[e].x < x + h) {
                    x = x + h;
                } else {
                    x = A[e].x + h;
                }

                p--;
            }

            _pr("%3d: %2d %2d, x=%2d p=%2d\n", h, A[e].y, A[e].x, x, p);
        }

        _pr("%3d: x=%2d\n", h, x);

        if (A[E-1].x < x && 0 <= p)
            break;
    }

    printf("%d\n", h);

    return 0;
}
