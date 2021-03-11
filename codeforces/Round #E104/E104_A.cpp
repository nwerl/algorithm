#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		vector<int> arr(N);
		for(int i=0;i<N;i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());

		int sameCnt = 1;
		int ans = 0;

		for(int i=N-2;i>=0;i--)
		{
			if(arr[i] == arr[i+1])
				sameCnt++;
			else
			{
				ans += sameCnt;
				sameCnt = 1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}