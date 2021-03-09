#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		long long d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		long long add = (r1+r2)*(r1+r2);
		long long sub = (r1-r2)*(r1-r2);


		if(d == 0)
		{
			if(r1 == r2)
				cout << "-1";
			else
				cout << "0";
		}
		else if(d < add && d > sub)
			cout << "2";
		else if(d == add || d == sub)
			cout << "1";
		else if(d < sub || d > add)
			cout << "0";

		cout << "\n";
	}

	return 0;
}