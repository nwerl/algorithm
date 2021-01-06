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
		int N, M;
		cin >> N >> M;
		vector<int> k(N);
		vector<int> c(M+2);
		int idx = 1;
		long long sum = 0;
		for(int i=0;i<N;i++)
			cin >> k[i];
		for(int i=1;i<=M;i++)
			cin >> c[i];

		sort(k.begin(), k.end(), greater<int>());

		for(int i=0;i<N;i++)
		{
			if(idx >= k[i])	sum += c[k[i]];
			else			sum += c[idx++];
		}

		cout << sum << endl;
	}

	return 0;
}