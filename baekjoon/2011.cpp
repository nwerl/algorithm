#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 1000000;
string s;
int dp[5001][2];

int main()
{
	cin >> s;

	int n = s.length();

	if(s[0] == '0')
	{
		cout << "0" << endl;
		return 0;
	}

	dp[0][0] = 1;

	for(int i=1;i<n;i++)
	{
		if(s[i] != '0')
			dp[i][0] = (dp[i-1][0]+dp[i-1][1])%MOD;
		
		int tmp = (s[i-1]-'0')*10+(s[i]-'0');

		if(tmp == 0)
		{
			cout << "0" << endl;
			return 0;
		}
		
		if(s[i-1] != '0' && tmp>=1 && tmp<=26)
		{
			if(i == 1)	dp[i][1] = 1;	
			else	dp[i][1] = (dp[i-2][0]+dp[i-2][1])%MOD;
		}

		//cout << dp[i][0] << " " <<dp[i][1] << endl;
	}

	cout << (dp[n-1][0]+dp[n-1][1])%MOD << endl;

	return 0;
}