#include <cstdio>

int main() {
    int M, N;

    scanf("%d %d", &M, &N);

    int d = M <= N ? 1 : -1;

    for (int i = M; 0 < d ? i <= N : N <= i; i += d) {
        for (int j = 1; j <= 9; j++)
            printf("%d * %d = %2d%s", i, j, i * j, j % 3 ? "   " : "\n");

        printf("\n");
    }

    return 0;
}
