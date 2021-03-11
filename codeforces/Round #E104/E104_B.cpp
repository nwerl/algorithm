#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, K;
		cin >> N >> K;

		if(N%2 == 0)
		{
			cout << (K-1)%N + 1 << "\n";
			continue;
		}		

		int add = 0;
		if(K > N/2)
			add = (K-((N/2)+1))/(N/2)+1;
		cout << (K-1+add)%N + 1 << "\n";


	}

	return 0;
}