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
		char ch = 'a';
		for(int i=0;i<N;i++)
		{
			if(i%3==0)	ch = 'a';
			cout << ch++;
		}
		cout << endl;
	}

	return 0;
}