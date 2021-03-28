#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

int N, Q, L;
int arr[65][65];
int dir[4][2] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void rotateByL(int y, int x){
    int temp[65][65];

	for(int i=0;i<L;i++)
		for(int j=0;j<L;j++)
			temp[i][j]=arr[y+L-1-j][x+i];
	for(int i=0;i<L;i++)
		for(int j=0;j<L;j++)
			arr[y+i][x+j]=temp[i][j];
}

void rotate()
{
    for(int i=0;i<N;i+=L)
        for(int j=0;j<N;j+=L)
            rotateByL(i, j);
}

void melt()
{
    int tmp[65][65];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            tmp[i][j] = arr[i][j];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!tmp[i][j])  continue;

            int ice = 0;
            for(int d=0;d<4;d++)
            {
                int ny = i+dir[d][0];
                int nx = j+dir[d][1];
                if(ny>=0 && ny<N && nx>=0 && nx<N && tmp[ny][nx])
                    ice++;
            }

            if(ice < 3)
                arr[i][j]--;
        }
    }
}

int chk()
{
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int bfs(int Y, int X, vector<vector<bool>>& visit)
{
    int ret = 1;
    queue<pair<int, int>> q;
    q.push({Y, X});

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d=0;d<4;d++)
        {
            int ny = y+dir[d][0];
            int nx = x+dir[d][1];

            if(ny>=0 && ny<N && nx>=0 && nx<N && !visit[ny][nx] && arr[ny][nx])
            {
                ret++;
                q.push({ny, nx});
                visit[ny][nx] = true;
            }
        }
    }

    if(ret == 1)
        return 0;

    return ret;
}

int chk2()
{
    vector<vector<bool>> visit(65, vector<bool>(65, false));

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[i][j] && !visit[i][j])
            {
                visit[i][j] = true;
                ans = max(bfs(i, j, visit), ans);
            }
        }
    }

    return ans;
}

int main()
{
    cin >> N >> Q;
    N = pow(2, N);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> arr[i][j];


    for(int i=0;i<Q;i++)
    {
        cin >> L;
        L = pow(2, L);
        rotate();
        melt();
        chk();
    }

    cout << chk() << endl;
    cout << chk2() << endl;


    return 0;
}