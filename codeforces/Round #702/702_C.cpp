#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	vector<long long> v;

	for(long long i=1;i<=10000;i++)
		v.push_back(i*i*i);


	while(T--)
	{
		long long x;
		cin >> x;

		int lo = 0, hi = 9999;
		bool flag = false;

		while(lo <= hi)
		{
			long long sum = v[lo]+v[hi];

			if(sum > x)
				hi--;
			else if(sum < x)
				lo++;
			else
			{
				flag = true;
				break;
			}
		}

		flag ? cout << "YES" << "\n" : cout << "NO" << "\n";
	}

	return 0;
}