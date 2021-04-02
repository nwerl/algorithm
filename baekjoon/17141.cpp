#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int MAX = 987654321;

int N, M;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int board[51][51];
vector<pair<int, int>> virusYX;
int virus[10];
int ans = MAX;

int bfs()
{
    bool visit[51][51];
    memset(visit, false, sizeof(visit));
    queue<pair<int, int>> q;

    for(int i=0;i<M;i++)
    {
        int Y = virusYX[virus[i]].first;
        int X = virusYX[virus[i]].second;
        q.push({Y, X});
        visit[Y][X] = true; 
    }
    
    int ret = 0;

    while(!q.empty())
    {
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int d=0;d<4;d++)
            {
                int ny = y+dir[d][0];
                int nx = x+dir[d][1];

                if(ny>=0 && ny<N && nx>=0 && nx<N && !visit[ny][nx] && board[ny][nx] != 1)
                {
                    q.push({ny, nx});
                    visit[ny][nx] = true;
                }
            }
        }
        if(!q.empty())
            ret++;
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!visit[i][j] && board[i][j] != 1)
                return MAX;
        }
    }

    return ret;
}

void combi(int n, int r)
{
    if(r == 0)
        ans = min(ans, bfs());
    else if(n<r)
        return;
    else
    {
        virus[r-1] = n-1;
        combi(n-1, r-1);
        combi(n-1, r);
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 2)
                virusYX.push_back({i, j});
        }
    }
    
    combi(virusYX.size(), M);
        
    ans==MAX ? cout << "-1" << endl : cout << ans << endl;


    return 0;
}