#include <stdio.h>

#define S 81

int N;
char A[S], R[S];

int compare(char* a, char* b, int n) {
    int i = 0;

    for (; a[i] == b[i]; i++)
        if (n <= i + 1)
            break;

    return a[i] - b[i];
}

int _compare(char* a, char* b, int n) {
    int r = compare(a, b, n);

    printf("compare: r=%d, n=%d, a=%s b=%s\n", r, n, a, b);

    return r;
}

int valid(char* a, int n) {
    for (int l = n / 2; 1 <= l; l--)
        for (int i = 0; i <= n - l; i++)
            if (!compare(&a[i], &a[i+l], l))
                return 0;

    return 1;
}

int _valid(char* a, int n) {
    int r = valid(a, n);

    printf("valid: r=%d, n=%d, a=%s\n", r, n, a);

    return r;
}

void copy(char* a, char* b, int n) {
    for (int i = 0; i < n; i++)
        a[i] = b[i];

    a[n] = '\0';
}

void solve(char* a, int n) {
    if (!valid(a, n))
        return;

    if (N <= n) {
        if (compare(a, R, n) < 0)
            return copy(R, a, n);

        return;
    }

    for (char c = '1'; c <= '3'; c++) {
        a[n] = c;
        a[n+1] = '\0';


        solve(a, n + 1);
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        R[i] = '3';

    R[N] = '\0';

    solve(A, 0);

    printf("%s\n", R);

    return 0;
}
