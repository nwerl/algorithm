#include<stdio.h>
#include<queue>

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
double p[4];
bool visit[29][29];
int T, E, W, S, N;

double dfs(int y, int x, int cnt)
{
    if(cnt == T)
        return 1.0;

    double ret = 0.0;
    for(int d=0;d<4;d++)
    {
        int ny = y+dir[d][0];
        int nx = x+dir[d][1];

        if(!visit[ny][nx])
        {
            visit[ny][nx] = true;
            ret += p[d]*dfs(ny, nx, cnt+1);
            visit[ny][nx] = false;
        }
    }

    return ret;
}

int main()
{
    scanf("%d %d %d %d %d", &T, &E, &W, &S, &N);
    p[0] = (double)E/100, p[1] = (double)W/100, p[2] = (double)S/100, p[3] = (double)N/100;
    visit[14][14] = true;

    
    printf("%.9f", dfs(14,14,0));

    return 0;
}