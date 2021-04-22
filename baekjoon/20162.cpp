#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> dp(N);

    for(int i=0;i<N;i++)
    {
        cin >> v[i];
        dp[i] = v[i];
    }


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i] > v[j])
                dp[i] = max(dp[j]+v[i], dp[i]);
        }
    }

    int ans = 0;
    for(int i=0;i<N;i++)
        ans = max(ans, dp[i]);

    cout << ans << endl;


    return 0;
}