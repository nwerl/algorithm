#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		vector<int> arr(N, 0);
		for(int i=0;i<N;i++)
			cin >> arr[i];

		int ans = 0;
		for(int i=0;i<N-1;i++)
		{
			int mini = min(arr[i], arr[i+1]);
			int maxi = max(arr[i], arr[i+1]);

			while(mini*2 < maxi)
			{
				ans++;
				if(maxi%2 == 1)
					maxi += 1;
				maxi /= 2;
			}
		}

		cout << ans << endl;
	}
	return 0;
}