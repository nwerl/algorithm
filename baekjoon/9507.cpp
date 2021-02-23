#include<iostream>

using namespace std;

int T;
long long dp[68];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;

	for(int i=4;i<68;i++)
	{
		for(int j=i-4;j<i;j++)
		{
			dp[i] += dp[j];
		}
	}
	
	while(T--)
	{
		int x;
		cin >> x;
		cout << dp[x] << "\n";
	}

	return 0;
}