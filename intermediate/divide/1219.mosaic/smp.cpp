#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAW_H 10//00000
#define MAW_W 10//00000
#define MAW_P 4 //100
#define MAW_E 10//00

int main() {
    srand((unsigned int) time(NULL));

    int H = rand() % MAW_H + 1;
    int W = rand() % MAW_W + 1;
    int P = rand() % MAW_P + 1;
    int E = rand() % MAW_E + 1;

    printf("%d %d\n%d\n%d\n", H, W, P, E);

    for (int e = 0; e < E; e++) {
        int y = rand() % H + 1;
        int x = rand() % W + 1;

        printf("%d %d\n", y, x);
    }

    return 0;
}
