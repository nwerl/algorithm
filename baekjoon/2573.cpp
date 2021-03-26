#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int arr[301][301];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int y, int x, vector<vector<bool>>& visit)
{
    queue<pair<int, int>> q;
    visit[y][x] = true;
    q.push({y, x});

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d=0;d<4;d++)
        {
            int ny = y+dir[d][0];
            int nx = x+dir[d][1];

            if(ny>=0 && ny<N && nx>=0 && nx<M && !visit[ny][nx] && arr[ny][nx])
            {
                q.push({ny, nx});
                visit[ny][nx] = true;
            }
        }
    }
}

bool melt()
{
    int arr2[301][301];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            arr2[i][j] = arr[i][j];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(arr[i][j])
            {
                for(int d=0;d<4;d++)
                {
                    int ny = i+dir[d][0];
                    int nx = j+dir[d][1];

                     if(ny>=0 && ny<N && nx>=0 && nx<M && !arr2[ny][nx])
                        if(--arr[i][j] < 1)
                            break;
                }
            }
        }
    }

    int set = 0;
    vector<vector<bool>> visit(301, vector<bool>(301, false));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(arr[i][j] && !visit[i][j])
            {
                bfs(i, j,visit);
                if(++set > 1)   return true;
            }
        }
    }

    return false;
}

bool chk()
{
    // cout << endl;
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=0;j<M;j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(arr[i][j])   return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> arr[i][j];

    int ans = 1;
    while(chk())
    {
        if(melt())
        {
            cout << ans << endl;
            return 0;
        }
        ans++;
    }

    cout << "0" << endl;


    return 0;
}