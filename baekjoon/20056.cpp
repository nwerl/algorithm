#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

struct node
{
    int m;
    int s;
    int d;
};

struct qNode
{
    int r;
    int c;
    int m;
    int s;
    int d;
};

void move(queue<qNode>& q, int N)
{
    int size = q.size();
    vector<node> v[N+1][N+1];
    for(int i=0;i<size;i++)
    {
        int r = q.front().r;
        int c = q.front().c;
        int s = q.front().s;
        int m = q.front().m;
        int d = q.front().d;
        q.pop();

        int y = r+dir[d][0]*(s%N);
        int x = c+dir[d][1]*(s%N);
        y = y<1 ? N+y : y;
        x = x<1 ? N+x : x;
        y = y>N ? y-N : y;
        x = x>N ? x-N : x;

        v[y][x].push_back({m, s, d});
    }


    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int sz = v[i][j].size();
            if(sz == 1) q.push({i, j, v[i][j][0].m, v[i][j][0].s, v[i][j][0].d});
            if(sz <= 1) continue;

            int m = 0, s = 0, dFlag = 0, dStart = 1;
            for(int k=0;k<sz;k++)
            {
                m += v[i][j][k].m;
                dFlag += v[i][j][k].d%2;
                s += v[i][j][k].s;
            }
            m/=5;
            s/=sz;
            
            if(!m)  continue;
            if(dFlag == 0 || dFlag == sz)
                dStart = 0;
            
            for(int d=dStart;d<8;d+=2)
                q.push({i, j, m, s, d});
        }
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    queue<qNode> q;
    for(int i=0;i<M;i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        q.push({r, c, m, s, d});
    }
    
    for(int i=0;i<K;i++)
        move(q, N);

    int ans = 0;
    while(!q.empty())
    {
        ans += q.front().m;
        q.pop();
    }

    cout << ans << endl;

    return 0;
}