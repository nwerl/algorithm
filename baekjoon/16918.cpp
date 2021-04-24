#include<iostream>
#include<vector>

using namespace std;

int dir[4][2] ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    int R, C, N;
    cin >> R >> C >> N;
    vector<vector<char>> map(R, vector<char>(C));
    vector<vector<char>> map2(R, vector<char>(C));
    vector<vector<vector<char>>> bomb(2, vector<vector<char>>(R, vector<char>(C)));
        
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin >> map[i][j];
            bomb[1][i][j] = '.';
            if(map[i][j] == 'O')
                bomb[0][i][j] = 'O';
            else
                bomb[0][i][j] = '.';
        }
    }

    int next = 1;
    for(int n=2;n<=N;n++)
    {
        if(n%2==0)
        {
            for(int i=0;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    if(map[i][j] == '.')
                        bomb[next][i][j] = 'O';
                    map[i][j] = 'O';
                }
            }
        }
        else
        {
            next = (next+1)%2;

            for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                    map2[i][j] = map[i][j];

            for(int i=0;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    if(map2[i][j] == 'O' && bomb[next][i][j] == 'O')
                    {
                        bomb[(next+1)%2][i][j] = '.';
                        map[i][j] = '.';
                        for(int d=0;d<4;d++)
                        {
                            int ny = i+dir[d][0];
                            int nx = j+dir[d][1];
                            if(ny>=0 && ny<R && nx>=0 && nx<C)
                            {
                                map[ny][nx] = '.';
                                bomb[(next+1)%2][ny][nx] = '.';
                            }
                        }
                    }
                }
            }
            
            for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                    bomb[next][i][j] == '.';
        }
    }

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
    
        

    return 0;
}