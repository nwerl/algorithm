#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long N;
		cin >> N;

		for(long long ans=N;;ans++)
		{
			vector<bool> digit(10);

			for(long long foo=ans;foo>0;foo/=10)
				digit[foo%10] = true;

			bool flag = false;
			for(int i=1;i<10;i++)
			{
				if(digit[i] && ans%i!=0)
				{
					flag = true;
					break;
				}
			}
			
			if(!flag)
			{
				cout << ans << endl;
				break;
			}
		}
	}

	return 0;
}