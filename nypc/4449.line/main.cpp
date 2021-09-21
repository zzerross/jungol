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

struct Point {
    int x, y;

    Point(): x(0), y(0) {
    }

    Point(int x, int y): x(x), y(y) {
    }

    bool operator<(const Point& o) {
        return x == o.x ?  y < o.y : x < o.x;
    }

    void dump(const char* s) {
        pr1("%8s: %d %d\n", s, x, y);
    }
} gPoints[POINTS];

int gCount[POINTS], gNumOfPoints, gE;

void dump() {
#if 1 <= DEBUG
    for (int i = 0; i < gNumOfPoints; i++)
        pr2("%8d %8d\n", gPoints[i].x, gPoints[i].y);

    pr2("\n");
#endif
}

int ccw(Point p, Point q, Point r) {
    int ret = ((q.x - p.x) * (r.y - p.y)) - ((q.y - p.y) * (r.x - p.x));

    if (0 < ret)
        return 1;
    else if (ret < 0)
        return -1;
    else
        return 0;
}

int main() {
    setbuf(stdout, NULL);

    int T;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &gNumOfPoints, &gE);

        for (int i = 0; i < gNumOfPoints; i++)
            scanf("%d %d", &gPoints[i].x, &gPoints[i].y);

#if TEST
        if (t != TEST)
            continue;
#endif

        sort(gPoints, gPoints + gNumOfPoints);
        dump();
        
        for (int i = 0; i < gNumOfPoints; i++)
            gCount[i] = POINTS;
        gCount[0] = 0;

        for (int i = 0; i < gNumOfPoints - 1; i++) {
            Point pivot = gPoints[i];
            Point upper(gPoints[i+1].x, gPoints[i+1].y + gE);
            Point lower(gPoints[i+1].x, gPoints[i+1].y - gE);

            if (gCount[i] < gCount[i+1])
                gCount[i+1] = gCount[i] + 1;

            for (int j = i + 2; j < gNumOfPoints; j++) {
                Point upperCandidate(gPoints[j].x, gPoints[j].y + gE);
                if (ccw(pivot, upper, upperCandidate) < 0)
                    upper = upperCandidate;

                Point lowerCandidate(gPoints[j].x, gPoints[j].y - gE);
                if (0 < ccw(pivot, lower, lowerCandidate))
                    lower = lowerCandidate;

                if (0 < ccw(pivot, upper, lower))
                    break;

                if (0 <= ccw(pivot, lower, gPoints[j]) && ccw(pivot, upper, gPoints[j]) <= 0)
                    if (gCount[i] + 1 < gCount[j])
                        gCount[j] = gCount[i] + 1;
            }
        }

        printf("#%d %d\n", t, gCount[gNumOfPoints-1]);
    }

    return 0;
}
