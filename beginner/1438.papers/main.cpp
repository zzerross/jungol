#include <stdio.h>

#define S 100

int A[S][S] = { 0, }, N, Y, X, R = 0;

int main() {
    for (scanf("%d", &N); N--;) {
        scanf("%d %d", &X, &Y);

        for (int i = Y; i < Y + 10; i++)
            for (int j = X; j < X + 10; j++)
                A[i][j] = 1;
    }

    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
            R += A[i][j];

    printf("%d\n", R);

    return 0;
}
