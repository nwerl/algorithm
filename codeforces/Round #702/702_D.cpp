#include<iostream>
#include<vector>

using namespace std;

void recur(int left, int right, vector<int>& arr, vector<int>& ans, int depth)
{
	if(left == right)	return;

	int root = 0, rootIdx = -1;
	for(int i=left;i<right;i++)
	{
		if(arr[i] > root)
		{
			root = arr[i];
			rootIdx = i;
		}
	}

	ans[rootIdx] = depth;
	recur(left, rootIdx, arr, ans, depth+1);
	recur(rootIdx+1, right, arr, ans, depth+1);

	return;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		
		vector<int> arr(N);
		vector<int> ans(N);
		
		for(int i=0;i<N;i++)
		{
			cin >> arr[i];
		}

		recur(0, N, arr, ans, 0);

		for(int i=0;i<N;i++)
			cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}