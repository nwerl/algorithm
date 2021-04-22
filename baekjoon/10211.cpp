#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<int> v(N+1);
        vector<vector<int>> dp(N+1, vector<int>(N+1));
        for(int i=1;i<=N;i++)
        {
            cin >> v[i];
        }

        int ans = INT_MIN;

        for(int i=1;i<=N;i++)
        {
            for(int j=i;j<=N;j++)
            {
                dp[i][j] = v[j] + dp[i][j-1];
                ans = max(ans, dp[i][j]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}