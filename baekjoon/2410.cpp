#include<iostream>

using namespace std;

int N;
int dp[1000001][20];

int main()
{
	cin >> N;

	for(int i=0;i<20;i++)	dp[0][i] = 1;

	for(int i=1;i<=N;i++)
	{
		dp[i][0] = 1;
		for(int j=1;j<20;j++)
		{
			dp[i][j] = dp[i][j-1];
			if(i>=(1<<j))
				dp[i][j] += dp[i-(1<<j)][j];
			dp[i][j]%=1000000000;
		}
	}

	cout << dp[N][19] << endl;

	return 0;
}