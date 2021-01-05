#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;



int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		vector<int> red;
		vector<int> blue;
		int redSum = 0;
		int blueSum = 0;
		string s;
		cin >> s;
		for(int i=0;i<N;i++)
			red.push_back((int)(s[i]-'0'));
		cin >> s;
		for(int i=0;i<N;i++)
			blue.push_back((int)(s[i]-'0'));

		for(int i=0;i<N;i++)
		{
			if(red[i] > blue[i])		redSum++;
			else if(red[i] < blue[i])	blueSum++;
		}

		if(redSum == blueSum)		cout << "EQUAL" << endl;
		else if(redSum > blueSum)	cout << "RED" << endl;
		else						cout << "BLUE" << endl;

	}
	return 0;
}