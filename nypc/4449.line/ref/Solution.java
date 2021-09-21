// refer https://zoosso.tistory.com/611

import java.io.*;
import java.util.*;
 
public class Solution {
    static final long INF = Long.MAX_VALUE;
    static int N;
    static long epsilon;
    static Point[] points;
    static Long[] DP;
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
 
        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            epsilon = Long.parseLong(st.nextToken());
             
            points = new Point[N];
            for(int i=0; i<N; i++) {
                st = new StringTokenizer(br.readLine());
                long x = Long.parseLong(st.nextToken());
                long y = Long.parseLong(st.nextToken());
                points[i] = new Point(x, y);
            }
             
            // (1차) x좌표 기준 오름차순
            // (2차) y좌표 기준 오름차순 
            Arrays.sort(points);
             
            DP = new Long[N];
            Arrays.fill(DP, INF);
             
            DP[0] = 0L; 
            for(int i=0; i<N-1; i++) {
                Point pivot = points[i];
                Point U = new Point(points[i+1].x, points[i+1].y + epsilon);
                Point L = new Point(points[i+1].x, points[i+1].y - epsilon);
                if(DP[i+1] > DP[i]) DP[i+1] = DP[i] + 1;
                 
                for(int j=i+2; j<N; j++) {
                    // 기울기 범위 조정 (동일선상의 경우, 기존  U과 L 변경 불필요)
                    // 반시계 방향으로, 최대 기울기 감소
                    Point tempU = new Point(points[j].x, points[j].y + epsilon);
                    if(ccw(pivot, U, tempU) < 0) {
                        U = tempU;
                    }
 
                    // 시계 방향으로, 최소  기울기 감소
                    Point tempL = new Point(points[j].x, points[j].y - epsilon);
                    if(ccw(pivot, L, tempL) > 0) {
                        L = tempL;
                    }
                     
                    if(ccw(pivot, U, L) > 0) {
                        break;
                    }
                     
                    // 최소 기울기 선분보다 위에, 최대 기울기 선분보다 아래에 존재하는지 확인
                    // 최소 기울기 선분과 시계 방향이거나 동일선상에 존재 필요
                    // 최대 기울기 선분과 반시계 방향이거나 동일선상에 존재 필요
                    if(ccw(pivot, L , points[j]) >= 0 && ccw(pivot, U , points[j]) <= 0) {
                        // 기존 값이(DP[j]) DP[i]+1 보다 더 큰 경우에만 변경
                        if(DP[j] > DP[i] + 1) {
                            DP[j] = DP[i] + 1;
                        }
                    }
                }
            }
             
            System.out.println("#" + tc + " " + DP[N-1]);
        }
    }
     
    // 벡터의 외적을 이용한 ccw 확인
    private static int ccw(Point p, Point q, Point r) {
        // 점 p, q에대해 점 r의 x, y를 빼줘서 그래프를 원점에 맞춥니다.
        long result = ((q.x - p.x) * (r.y - p.y)) - ((q.y - p.y) * (r.x - p.x));
 
        if (result > 0)
            // 시계 반향
            return 1;
        else if (result < 0)
            // 반시계
            return -1;
        else 
            // 일직선
            return 0;
    }
}
 
class Point implements Comparable<Point>{
    long x, y;
     
    public Point(long x, long y) {
        this.x = x;
        this.y = y;
    }
 
    @Override
    public int compareTo(Point target) {
        if(this.x - target.x < 0) 
            return -1;
        else if(this.x - target.x > 0)
            return 1;
        else { // x 좌표가 같은 경우
            if(this.y - target.y < 0) return -1;
            else return 1;
        }
    }
}
