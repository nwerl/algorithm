#include<iostream>

using namespace std;

int N;
int arr[501][501];

//이동 후 y 우 하 좌 상
int sand[4][9][2] = {{{-1, -1}, {1, -1}, {-1, 0}, {1, 0}, {0, -2}, {-2, 0}, {2, 0}, {-1, 1}, {1, 1}},
                    {{1, 1}, {1, -1}, {0, -1}, {0, 1}, {2, 0}, {0, -2}, {0, 2}, {-1, 1}, {-1, -1}},
                    {{1, 1}, {-1, 1}, {-1, 0}, {1, 0}, {0, 2}, {-2, 0}, {2, 0}, {1, -1}, {-1, -1}},
                    {{-1, -1}, {-1, 1}, {0, 1}, {0, -1}, {-2, 0}, {0, -2}, {0, 2}, {1, -1}, {1, 1}}};

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int per[9] = {10, 10, 7, 7, 5, 2, 2, 1, 1};

int move()
{
    int ans = 0;
    int y = N/2+1, x = N/2+1;
    int d = 0;
    int dirCnt = 0;
    int hold = 2;

    while(y>=1 && y<=N && x>=1 && x<=N)
    {
        y = y+dir[d][0];
        x = x+dir[d][1];
        int sumSand = 0;

        for(int i=0;i<9;i++)
        {
            int ny = y+sand[d][i][0];
            int nx = x+sand[d][i][1];
            int addSand = (arr[y][x]*per[i])/100;
            
            
            sumSand += addSand;

            if(!(ny>=1 && ny<=N && nx>=1 && nx<=N))
            {
                ans += addSand;
                continue;
            }

            arr[ny][nx] += addSand;
        }


        //alpha 남은모래 처리
        int ny = y+dir[d][0];
        int nx = x+dir[d][1];
        int remainedSand = arr[y][x] - sumSand;

        if(!(ny>=1 && ny<=N && nx>=1 && nx<=N))
            ans += remainedSand;
        else
            arr[ny][nx] += remainedSand;

        arr[y][x] = 0;

        dirCnt++;

        if(dirCnt == (int)(hold/2))
        {
            d = (d+1)%4;
            dirCnt = 0;
            hold++;
        }

        // for(int i=1;i<=N;i++)
        // {
        //     for(int j=1;j<=N;j++)
        //         cout << arr[i][j] << " ";
            
        //     cout << endl;
        // }
    }

    return ans;
}

int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> arr[i][j];
    
    cout << move() << endl;

    return 0;
}