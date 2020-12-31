#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

void recur(int start, int end, vector<int>& arr, vector<long long>& sum, unordered_set<long long>& set)
{
	if(start == end)
	{
		set.insert(arr[start]);
		return;
	}

	int down = upper_bound(arr.begin()+start, arr.begin()+end+1, (arr[start]+arr[end])/2)-arr.begin()-1;
	
	set.insert(sum[end]-sum[start-1]);

	if(down == end)	return;
	
	recur(start, down, arr, sum, set);
	recur(down+1, end, arr ,sum, set);
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		unordered_set<long long> set;
		int N, Q;
		cin >> N >> Q;
		vector<int> arr(N+1);
		vector<long long> sum(N+1);
		for(int i=1;i<=N;i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());

		for(int i=1;i<=N;i++)
			sum[i] = sum[i-1]+arr[i];

		recur(1, N, arr, sum, set);

		for(int i=0;i<Q;i++)
		{
			int s;
			cin >> s;
			if(set.find(s) != set.end())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}