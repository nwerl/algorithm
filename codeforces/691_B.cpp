#include<iostream>

using namespace std;

int dir[4][2] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
long long dp[1001];

int main()
{
	int N;
	cin >> N;

	if(N%2 == 0)
		cout << ((N/2)+1)*((N/2)+1) << endl;
	else
		cout << ((N+1)/2)*((N+1)/2+1)*2 << endl;

	return 0;
}