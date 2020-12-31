#include<iostream>
#include<vector>

using namespace std;

int N, M;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		vector<int> arr(N+1);
		for(int i=1;i<=N;i++)
			cin >> arr[i];
		vector<int> r(M+1);
		vector<double> p(M+1);

		for(int i=1;i<=M;i++)
			cin >> r[i] >> p[i];

		//1. 정렬 범위
		int pos;
		for(pos=N;pos>=1;pos--)
			if(arr[pos] != pos)
				break;

		if(pos == 0)
		{
			cout << "1.000000" << endl;
			continue;
		}

		double x = 0;

		vector<bool> isNeeded(M+1, false);
		for(int i=1;i<=M;i++)
		{
			if(r[i] >= pos)
				isNeeded[i] = true;
		}

		cout << fixed;
		cout.unsetf(ios::scientific);
		cout.precision(6);
		vector<vector<double>> dp(M+1, vector<double>(2, 0));
		dp[0][0] = 1, dp[0][1] = 0;
		for(int i=1;i<=M;i++)
		{
			if(!isNeeded[i])
			{
				dp[i][0] = dp[i-1][0]*(1-p[i])+dp[i-1][1]*(1-p[i]);
				dp[i][1] = dp[i-1][0]*p[i]+dp[i-1][1]*p[i];
			}
			if(isNeeded[i])
			{
				dp[i][0] = dp[i-1][0]*(1-p[i])+dp[i-1][1]*(1-p[i]);
				dp[i][1] = 0;
			}
		}

		cout << 1-dp[M][0]-dp[M][1] << endl;
	}

	return 0;
}