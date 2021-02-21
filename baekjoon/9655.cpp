#include<iostream>
#include<string>

using namespace std;

int N;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	(N%2==0)? cout << "CY" : cout << "SK";

	return 0;
}