#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    vector<vector<int>> dp(N, vector<int>(K+1));
    for(int i=0;i<N;i++)
    {
        cin >> v[i];
        dp[i][K] = 1;
    }

    
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=K;k>=0;k--)
            {
                if(k>0 && v[i] < v[j])
                    dp[i][k-1] = max(dp[i][k-1], dp[j][k]+1);
                else if(v[i] >= v[j])
                    dp[i][k] = max(dp[i][k], dp[j][k]+1);
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int k=0;k<=K;k++)
        {
            ans = max(dp[i][k], ans);
        }
    }

    cout << ans << endl;


    return 0;
}