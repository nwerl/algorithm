#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, x;
		cin >> N >> x;
		vector<int> arr(N);
		long long maxi = 0, mini = 0;
		for(int i=0;i<N;i++)
		{
			cin >> arr[i];
			maxi += (arr[i]%x)==0 ? arr[i]/x : arr[i]/x+1;
			mini += arr[i];
		}
		mini = (mini%x)==0 ? mini/x : mini/x+1;

		cout << mini << " " << maxi << endl;
	}
	return 0;
}