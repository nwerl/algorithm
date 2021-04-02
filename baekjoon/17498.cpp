#include<iostream>
#include<vector>

using namespace std;

const long long MIN = 1e12;
int N, M, D;
vector<vector<long long>> v;
vector<vector<long long>> dp;

long long jump(int y, int x, int d, long long ori)
{
    long long ret = -MIN;
    
    int left = x, right = x;

    for(int i=y;i<y+d;i++)
    {
        if(i < 0 && left < 0 && right >= M)  return ret;
    
        if(i >=0 && left >= 0)
            ret = max(ret, dp[i][left] + ori*v[i][left]);
        if(i >=0 && right < M)
            ret = max(ret, dp[i][right] + ori*v[i][right]);

        left--; right++;
    }

    return ret;
}

int main()
{
    cin >> N >> M >> D;
    v = vector<vector<long long>>(N, vector<long long>(M));
    dp = vector<vector<long long>>(N, vector<long long>(M));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> v[i][j];
            dp[i][j] = -MIN;
        }
    }

    for(int i=0;i<M;i++)
        dp[0][i] = 0;

    long long ans = -MIN;
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int d=1;d<=D;d++)
            {
                dp[i][j] = max(dp[i][j], jump(i-d, j, d, v[i][j]));
            }
        }
    }

    for(int i=0;i<M;i++)
        ans = max(ans, dp[N-1][i]);
        

    cout << ans << endl;

    return 0;
}