/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=386&sca=3030
 */

#include <stdio.h>

#define S 101
#define Z (S * S)

int N, M, A, B, C, D, V[S][S] = { 0, };
int Y[] = { 1, 2,  2,  1, -1, -2, -2, -1, };
int X[] = { 2, 1, -1, -2, -2, -1,  1,  2, };

int range(int i, int j) {
    return 1 <= i && i <= N && 1 <= j && j <= M;
}

int min(int i, int j) {
    return i < j ? i : j;
}

struct Q {
    int y[Z], x[Z], t[Z];
    int f, r;

    struct Q& init() {
        f = 0, r = 0;

        return *this;
    }

    bool empty() {
        return f == r;
    }

    void push(int y, int x, int t) {
        this->y[r] = y;
        this->x[r] = x;
        this->t[r++] = t;
    }

    bool pop(int& y, int& x, int& t) {
        if (empty())
            return false;

        y = this->y[f];
        x = this->x[f];
        t = this->t[f++];

        return true;
    }
} Q;

int main() {
    scanf("%d %d  %d %d  %d %d", &N, &M, &A, &B, &C, &D);

    Q.init().push(A, B, 0);

    for (int i, j, t; Q.pop(i, j, t);) {
        if (i == C && j == D) {
            printf("%d\n", t);
            break;
        }

        for (int d = 0; d < 8; d++) {
            int y = i + Y[d];
            int x = j + X[d];

            if (range(y, x) && !V[y][x]) {
                V[y][x] = 1;

                Q.push(y, x, t + 1);
            }
        }
    }

    return 0;
}
