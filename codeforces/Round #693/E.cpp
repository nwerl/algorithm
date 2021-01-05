#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct node
{
	int w;
	int h;
	int idx;

	bool operator < (const node& n1)
	{
		return w < n1.w;
	}
};


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;

		vector<node> arr(N+1);
		for(int i=1;i<=N;i++)
		{
			cin >> arr[i].w >> arr[i].h;
			if(arr[i].h > arr[i].w)
			{
				arr[i].w ^= arr[i].h;
				arr[i].h ^= arr[i].w;
				arr[i].w ^= arr[i].h;
			}
			arr[i].idx = i;
		}

		sort(arr.begin(), arr.end());
		priority_queue<pair<int, int>> q;
		vector<int> ans(N+1, -1);

		int idx = 1;
		for(int i=1;i<=N;i++)
		{
			if(i>1 && arr[i].w != arr[i-1].w)
			{
				for(int j=idx;j<i;j++)
					q.push(make_pair(-arr[j].h, arr[j].idx));
				idx = i;
			}

			if(!q.empty())
			{
				if(arr[i].h > -q.top().first)
					ans[arr[i].idx] = q.top().second;
			}
		}

		for(int i=1;i<=N;i++)
			cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}