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
		int one = 0, two = 0;
		for(int i=0;i<N;i++)
		{
			int candy;
			cin >> candy;
			if(candy == 1)	one+=candy;
			else			two+=candy;
		}
		if((one+two)%2==1)
		{
			cout << "NO" << endl;
			continue;
		}
		if((two/2)%2==1)
		{
			if(one == 0)
			{
				cout << "NO" << endl;
				continue;
			}
		}
		cout << "YES" << endl;
	}

	return 0;
}