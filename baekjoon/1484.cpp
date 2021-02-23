#include<iostream>

using namespace std;

int main()
{
	bool flag = false;
	int G;
	cin >> G;

	int a = 1, b = 1;
	while(1)
	{
		int sum = (a+b)*(a-b);

		if(a-b == 1 && sum>G)	break;

		if(sum > G)
			b++;
		else if(sum < G)
			a++;
		else if(sum == G)
		{
			flag = true;
			cout << a << endl;
			a++;
		}
	}

	if(!flag)
		cout << "-1" << endl;

	return 0;
}