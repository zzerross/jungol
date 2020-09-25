/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2857&sca=30
 */

#include <cstdio>

#define S 500000

int M, N, A[S];

int main() {
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
        scanf("%d", &A[i]);

    scanf("%d", &N);

    for (int m, t, i = 0; i < N; i++) {
        scanf("%d", &t);

        for (int l = 0, h = M - 1; l <= h;) {
            m = l + (h - l) / 2;

            if (A[m] < t) {
                l = m + 1;
            } else if (t < A[m]) {
                h = m - 1;
            } else {
                break;
            }
        }

        printf("%d ", A[m] == t ? m : -1);
    }

    printf("\n");

    return 0;
}
