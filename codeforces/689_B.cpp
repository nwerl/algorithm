#include<iostream>

using namespace std;

char cell[501][501];
bool cache[501][501][501];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin >> cell[i][j];

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				bool flag = false;
				for(int k=j;k<M;k++)
				{
					if(cell[i][k] != '*' || flag)
					{
						flag = true;
						cache[i][j][k] = false;
					}
					else					cache[i][j][k] = true;
				}
			}
		}

		int ans = 0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(cell[i][j] != '*')	continue;
				
				ans++;
				for(int k=1;k<N;k++)
				{
					if(j-k<0 || j+k>=M || i+k>=N || !cache[i+k][j-k][j+k])	break;
					ans += cache[i+k][j-k][j+k];
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}