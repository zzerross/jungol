
#include <cstdio>
#define INF 87654321
using namespace std;

int M[14][14];
int visited[14];
int N;
int small = INF;

void dfs(int cur,int len, int tot){
    if (tot > small)return;
    if (len == N && M[cur][1] != 0){
        if (tot + M[cur][1] < small){
            small = tot + M[cur][1];
            return;
        }
    }
    for (int i = 2; i <= N; ++i){
        if (i == cur)continue;
        if (M[cur][i] != 0 && visited[i] == 0){
            visited[i] = 1;
            dfs(i,len+1,tot+M[cur][i]);
            visited[i] = 0;//다시 나왔으면 방문안한거로 처리
        }
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)for (int j = 1; j <= N; ++j)scanf("%d",&M[i][j]);
    dfs(1,1,0);
    printf("%d\n", small);
    return 0;
}

