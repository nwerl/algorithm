#include<iostream>

using namespace std;

int N, S, M;
int v[1001];
bool dp[101][1001];

int main()
{
	cin >> N >> S >> M;

	for(int i=1;i<=N;i++)
		cin >> v[i];

	dp[0][S] = true;

	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if(j-v[i]>=0)
				dp[i][j] = dp[i][j] || dp[i-1][j-v[i]];	
			if(j+v[i]<=M)
				dp[i][j] = dp[i][j] || dp[i-1][j+v[i]];
		}
	}

	int ans = -1;

	for(int j=0;j<=M;j++)
	{
		if(dp[N][j])
		{
			ans = j;
		}
	}

	cout << ans << endl;
	return 0;
}