#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N;
int arr[101][101];
bool visit[101][101];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int Y, int X)
{
    queue<pair<int, int>> q;
    q.push({Y, X});
    visit[Y][X] = true;

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d=0;d<4;d++)
        {
            int ny = y+dir[d][0];
            int nx = x+dir[d][1];

            if(ny >= 0 && ny<N && nx>=0 && nx<N && !visit[ny][nx])
            {
                visit[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 1;

    for(int k=0;k<=100;k++)
    {
        int sum = 0;
        memset(visit, false, sizeof(visit));

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(arr[i][j] <= k)
                {
                    visit[i][j] = true;
                }
            }
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(!visit[i][j])
                {
                    bfs(i, j);
                    sum++;
                }
            }
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}