#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int idx = -1;

		vector<int> v(3);

		if(s[0] == s[n-1])
		{
			cout << "NO" << "\n";
			continue;
		}

		v[s[0]-'A'] = 1;
		v[s[n-1]-'A'] = -1;
		
		for(int i=0;i<3;i++)
		{
			if(!v[i])
			{
				idx = i;
				break;
			}
		}

		bool flag = false;
		v[idx] = -1;
		for(int k=0;k<2;k++)
		{
			v[idx] = -v[idx];
			int cnt = 0;
			for(int i=0;i<n;i++)
			{
				cnt += v[s[i]-'A'];
				if(cnt<0)	break;
			}

			if(!cnt)	flag = true;
		}

		flag ? cout << "YES" << "\n" : cout << "NO" << "\n";
	}

	return 0;
}