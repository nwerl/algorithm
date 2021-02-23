#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

int N;
long long arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int i=0;i<N;i++)
		cin >> arr[i];

	sort(arr, arr+N);

	int lo = 0, hi = N-1;
	long long mini = LLONG_MAX;
	long long ans1 = arr[lo], ans2 = arr[hi];


	while(lo < hi)
	{
		long long mid = arr[lo]+arr[hi];

		if(mini > abs(mid))
		{
			mini = abs(mid);
			ans1 = arr[lo], ans2 = arr[hi];
		}

		if(mid < 0)
			lo++;
		else if(mid > 0)
			hi--;
		else
			break;
	}

	cout << ans1 << " " << ans2;

	return 0;
}