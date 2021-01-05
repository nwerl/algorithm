#include<iostream>
#include<vector>

using namespace std;
int N;

long long recur(int idx, vector<int>& arr, vector<long long>& dp)
{
	if(idx >= N)	return 0;
	if(dp[idx])	return dp[idx];
	
	return dp[idx] = recur(idx+arr[idx], arr, dp)+arr[idx];
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N;
		vector<int> arr(N+1);
		vector<long long> dp(N+1);
		for(int i=0;i<N;i++)
			cin >> arr[i];

		long long ans = 0;
		for(int i=0;i<N;i++)
			ans = max(ans,recur(i, arr, dp));

		
		cout << ans << endl;
	}

	return 0;
}