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
		vector<int> arr(N);
		vector<int> c(3, 0);

		for(int i=0;i<N;i++)
		{
			cin >> arr[i];
			arr[i]%=3;
			c[arr[i]]++;
		}

		vector<int> big;
		vector<int> small;
		long long ans = 0;

		for(int i=0;i<3;i++)
		{
			if(c[i] > N/3)
				big.push_back(i);
			else if(c[i] < N/3)
				small.push_back(i);
		}

		if(big.size() == 2)
		{
			for(int i=0;i<2;i++)
			{
				int sub = -(big[i] - small[0]);
				if(sub < 0)	sub = 3 + sub;
				ans = ans + (c[big[i]]-N/3)*sub;
			}
		}
		else if(big.size() == 1)
		{
			for(int i=0;i<small.size();i++)
			{
				int sub = -(big[0] - small[i]);
				if(sub < 0)	sub = 3 + sub;
				ans = ans + (N/3-c[small[i]])*sub;
			}
		}

		cout << ans << endl;
	}
}