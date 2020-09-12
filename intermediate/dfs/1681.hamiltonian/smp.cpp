#include <cstdio>
#include <ctime>
#include <cstdlib>

#define S 12
#define C 9 // 0

int main() {
    srand((unsigned int) time(NULL));

    int N = S;

    printf("%d\n", N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", i == j ? 0 : ((rand() % C) + 1));

        printf("\n");
    }

    return 0;
}
