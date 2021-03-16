#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1000001;

int main()
{
    int T;
    cin >> T;
    vector<bool> dp(MAX);
    dp[2020] = true;
    dp[2021] = true;
    
    for(int i=4040;i<MAX;i++)
        dp[i] = dp[i-2020] || dp[i-2021];

    while(T--)
    {
        int N;
        cin >> N;

        dp[N] ? cout << "YES" << endl : cout << "NO" << endl;

    }

    return 0;
}