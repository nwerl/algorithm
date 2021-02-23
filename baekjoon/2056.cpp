#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int t[10001];
vector<int> k[100001];
int cnt[10001];
int dp[10001];

int main()
{
	int N;
	cin >> N;

	for(int i=1;i<=N;i++)
	{
		cin >> t[i];
		int K;
		cin >> K;
		cnt[i] = K;
		while(K--)
		{
			int x;
			cin >> x;
			k[x].push_back(i);
		}
	}

	queue<int> q;

	for(int i=1;i<=N;i++)
		if(!cnt[i])
			q.push(i);

	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		dp[x] += t[x];

		for(int i=0;i<k[x].size();i++)
		{
			int dest = k[x][i];
			dp[dest] = max(dp[dest], dp[x]);

			if(--cnt[dest] == 0)
				q.push(dest);
		}
	}

	int ans = 0;
	for(int i=1;i<=N;i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;

	return 0;
}