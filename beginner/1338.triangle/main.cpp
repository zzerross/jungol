#include <stdio.h>

int N;
char A[101][101] = { 0, }, C = 'A';

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        for (int y = i, x = N, n = 0; n <= N-i; n++, y++, x--)
            if ((A[y][x] = C++) == 'Z')
                C = 'A';

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            printf("%c ", A[i][j] ? A[i][j] : ' ');

        printf("\n");
    }


    return 0;
}
