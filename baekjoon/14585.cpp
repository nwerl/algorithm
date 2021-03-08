#include<iostream>

using namespace std;

int N, M;
long long dp[303][303];

int main()
{
	cin >> N >> M;

	for(int i=0;i<N;i++)
	{
		int y, x;
		cin >> x >> y;
		dp[y+1][x+1] = M-(y+x);
		if(dp[y+1][x+1] <0)
			dp[y+1][x+1] = 0;
	}

	long long ans = 0;

	for(int i=1;i<=N+1;i++)
	{
		for(int j=1;j<=N+1;j++)
		{
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dp[i][j];
			ans = max(dp[i][j], ans);
		}
	}

	cout << ans << endl;



	return 0;
}