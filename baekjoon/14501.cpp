#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int arr[17][2];
int dp[17];
int output;

int dfs(int day)
{
	int nDay = day + arr[day][0];
	for(int i=nDay;i<=N+1;i++)
	{
		if(dp[i])	dp[day] = max(dp[day], dp[i]+arr[day][1]);
		else	dp[day] = max(dp[day], dfs(i)+arr[day][1]);
	}

	return dp[day];
}


int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	arr[0][0] = 1;
	arr[N+1][0] = 987654321;

	dfs(0);

	for(int i=1;i<=N;i++)
		output = max(output, dp[i]);
	
	printf("%d", output);

	return 0;
}