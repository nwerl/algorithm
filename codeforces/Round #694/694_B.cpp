#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, x;
		cin >> N >> x;
		queue<int> q;
		vector<int> arr(N);
		vector<int> tmp(N);
		long long sum = 0;
		for(int i=0;i<N;i++)
		{
			cin >> arr[i];
			tmp[i] = arr[i];
			sum += arr[i];
		}


		bool flag = false;
		while(!flag)
		{
			for(int i=0;i<N;i++)
			{
				if(tmp[i]%x != 0)
				{
					flag = true;
					break;
				}
				tmp[i]/=x;	
				sum += arr[i];
			}
		}

		cout << sum << endl;
	}

	return 0;
}