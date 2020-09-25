#include <stdio.h>

typedef unsigned long long u64;

int main() {
    u64 N, l, m, h, r;

    scanf("%llu", &N);

    for (l = 1, h = N; l <= h;) {
        m = l + (h - l) / 2;

        if (m <= N / m)
            l = (r = m) + 1;
        else
            h = m - 1;
    }

    printf("%llu\n", r);

    return 0;
}
