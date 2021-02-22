#include<iostream>

using namespace std;

int N, M, K;
int dp[16][16];

int main()
{
	cin >> N >> M >> K;

	if(K == 0)
	{
		dp[0][0] = 1;

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(j>0)
					dp[i][j] = dp[i][j-1];
				if(i>0)
					dp[i][j] += dp[i-1][j];
			}
		}

		cout << dp[N-1][M-1] << endl;
		return 0;
	}

	K--;
	dp[0][0] = 1;
	int ky = K/M, kx = K%M;

	for(int i=0;i<=ky;i++)
	{
		for(int j=0;j<=kx;j++)
		{
			if(j>0)
				dp[i][j] = dp[i][j-1];
			if(i>0)
				dp[i][j] += dp[i-1][j];
		}
	}

	int a = dp[ky][kx];
	dp[ky][kx] = 1;

	for(int i=ky;i<N;i++)
	{
		for(int j=kx;j<M;j++)
		{
			if(j>kx)
				dp[i][j] = dp[i][j-1];
			if(i>ky)
				dp[i][j] += dp[i-1][j];
		}
	}

	cout << a*dp[N-1][M-1] << endl;



	return 0;
}