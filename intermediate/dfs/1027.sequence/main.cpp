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

int valid(char* a, int n) {
    for (int l = n / 2; 1 <= l; l--)
        for (int i = 0; i <= n - l; i++)
            if (!compare(&a[i], &a[i+l], l))
                return 0;

    return 1;
}

char* copy(char* a, char* b, int n) {
    for (int i = 0; i < n; i++)
        a[i] = b[i];

    a[n] = '\0';

    return a;
}

char* solve(char* a, int n) {
    if (!valid(a, n))
        return NULL;

    if (N <= n) {
        if (compare(a, R, n) < 0)
            return copy(R, a, n);

        return NULL;
    }

    for (char c = '1'; c <= '3'; c++) {
        a[n] = c;
        a[n+1] = '\0';


        if (solve(a, n + 1))
            return R;
    }

    return NULL;
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
