#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;

#if 1 <= DEBUG
#define pr1(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr1(fmt, ...)
#endif

#if 2 <= DEBUG
#define pr2(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr2(fmt, ...)
#endif

#define POINTS 10000

template <typename T>
struct Vector2D {
    T x, y;

    Vector2D(): x(0), y(0) {
    }

    Vector2D(T x, T y): x(x), y(y) {
    }

    T cross(const Vector2D& o) const {
        return x * o.y - y * o.x;
    }

    T ccw(const Vector2D& o) const {
        return cross(o);
    }

    T ccw(const Vector2D& a, const Vector2D& b) const {
        Vector2D oa = a - *this;
        Vector2D ob = b - *this;

        return oa.cross(ob);
    }

    bool operator<(const Vector2D& o) const {
        return x == o.x ?  y < o.y : x < o.x;
    }

    Vector2D operator-(const Vector2D& o) const {
        return Vector2D<T>(x - o.x, y - o.y);
    }

    void dump(const char* s) {
        pr1("%8s: %d %d\n", s, x, y);
    }
};

Vector2D<int> gVectors[POINTS];

int gTests, gCounts[POINTS], gNumOfVectors, gE;

void dump() {
#if 1 <= DEBUG
    for (int i = 0; i < gNumOfVectors; i++)
        pr2("%8d %8d\n", gVectors[i].x, gVectors[i].y);

    pr2("\n");
#endif
}

int main() {
    setbuf(stdout, NULL);

    scanf("%d", &gTests);

    for (int t = 1; t <= gTests; t++) {
        scanf("%d %d", &gNumOfVectors, &gE);

        for (int i = 0; i < gNumOfVectors; i++)
            scanf("%d %d", &gVectors[i].x, &gVectors[i].y);

#if TEST
        if (t != TEST)
            continue;
#endif

        sort(gVectors, gVectors + gNumOfVectors);
        dump();
        
        for (int i = 0; i < gNumOfVectors; i++)
            gCounts[i] = POINTS;
        gCounts[0] = 0;

        for (int i = 0; i < gNumOfVectors - 1; i++) {
            Vector2D<int> pivot = gVectors[i];
            Vector2D<int> upper(gVectors[i+1].x, gVectors[i+1].y + gE);
            Vector2D<int> lower(gVectors[i+1].x, gVectors[i+1].y - gE);

            if (gCounts[i] < gCounts[i+1])
                gCounts[i+1] = gCounts[i] + 1;

            for (int j = i + 2; j < gNumOfVectors; j++) {
                Vector2D<int> upperCandidate(gVectors[j].x, gVectors[j].y + gE);
                if (pivot.ccw(upper, upperCandidate) < 0)
                    upper = upperCandidate;

                Vector2D<int> lowerCandidate(gVectors[j].x, gVectors[j].y - gE);
                if (0 < pivot.ccw(lower, lowerCandidate))
                    lower = lowerCandidate;

                if (0 < pivot.ccw(upper, lower))
                    break;

                if (0 <= pivot.ccw(lower, gVectors[j]) && pivot.ccw(upper, gVectors[j]) <= 0)
                    if (gCounts[i] + 1 < gCounts[j])
                        gCounts[j] = gCounts[i] + 1;
            }
        }

        printf("#%d %d\n", t, gCounts[gNumOfVectors-1]);
    }

    return 0;
}
