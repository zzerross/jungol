#include <stdio.h>

#define N 9     
#define M 0x3fe

int A[N][N], Y[N] = { 0, }, X[N] = { 0, }, B[N][N] = { 0 };

void set(int i, int j) {
    int v = 1 << A[i][j];

    Y[i] |= v;
    X[j] |= v;
    B[i/3][j/3] |= v;
}

void unset(int i, int j) {
    int v = ~(1 << A[i][j]);

    Y[i] &= v;
    X[j] &= v;
    B[i/3][j/3] &= v;
}

int done() {
    for (int i = 0; i < N; i++)
        if ((Y[i] & X[i]) != M)
            return 0;

    for (int i = 0; i < N; i += 3)
        for (int j = 0; j < N; j += 3)
            if (B[i/3][j/3] != M)
                return 0;

    return 1;
}

int solve(int i, int j) {
    if (N <= j) {
        j = 0;

        if (N <= ++i)
            return done();
    }

    if (A[i][j])
        return solve(i, j + 1);

    for (int n = 1; n <= N; n++) {
        if ((Y[i] | X[j] | B[i/3][j/3]) & (1 << n))
            continue;

        A[i][j] = n;
        set(i, j);

        if (solve(i, j + 1))
            return 1;

        unset(i, j);
        A[i][j] = 0;
    }

    return 0;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);

            if (A[i][j])
                set(i, j);
        }
    }

    solve(0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", A[i][j]);

        printf("\n");
    }


    return 0;
}
