#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, R, C;
bool map[101][101];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void down(vector<pair<int,int>>& cluster)
{
    sort(cluster.begin(), cluster.end(), greater<pair<int, int>>());
    int fall = R;

    for(auto p : cluster)
    {
        int y = p.first, x = p.second;
        map[y][x] = false;
        
        while(y != R-1 && !map[y+1][x])
            y++;

        fall = min(fall, y-p.first);
    }

    for(auto p : cluster)
    {
        int y = p.first, x = p.second;
        map[y+fall][x] = true;
    }
}

bool bfs(int Y, int X, vector<vector<bool>>& visit)
{
    bool flag = false;
    vector<pair<int, int>> cluster;
    visit[Y][X] = true;
    queue<pair<int, int>> q;
    q.push({Y, X});
    cluster.push_back({Y, X});

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        

        for(int d=0;d<4;d++)
        {
            int ny = y+dir[d][0];
            int nx = x+dir[d][1];
            
            if(ny>=0 && ny<R && nx>=0 && nx<C && !visit[ny][nx] && map[ny][nx])
            {
                visit[ny][nx] = true;
                if(ny == R-1)
                    flag = true;

                q.push({ny, nx});
                cluster.push_back({ny, nx});
                
            }
        }
    }

    if(!flag)
    {
        down(cluster);
        return true;
    }
        

    return false;
}

void throwStick(int height, bool flag)
{
    int x = 0;
    int add = 1;
    if(!flag)
    {
        x = C-1;
        add = -1;
    }

    while(!map[height][x] && x>=0 && x<C)
        x+=add;
    if(!(x>=0 && x<C))   return;
    
    map[height][x] = false;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> R >> C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            char ch;
            cin >> ch;
            if(ch == 'x')
                map[i][j] = true;
            else if(ch == '.')
                map[i][j] = false;
        }
    }

    bool flag = true;
    cin >> N;
    for(int t=0;t<N;t++)
    {
        int height;
        cin >> height;

        height = R-height;
        throwStick(height, flag);
        flag = !flag;

        vector<vector<bool>> visit(R+1, vector<bool>(C+1, false));

        bool tmp = false;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(!visit[i][j] && map[i][j])
                    tmp = bfs(i, j, visit);
                
                if(tmp) break;
            }
            if(tmp) break;
        }
    }

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(!map[i][j])
                cout << '.';
            else
                cout << 'x';
        }
        cout << '\n';
    }


    return 0;
}