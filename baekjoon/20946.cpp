#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	vector<long long> v;

	for(long long i=2;i*i<=N;i++)
	{
		while(N%i == 0)
		{
			v.push_back(i);
			N/=i;
		}
	}

	if(N>1)	v.push_back(N);
	long long size = v.size();
	if(size < 2)
	{
		cout << "-1" << endl;
	}
	else if(size%2 == 0)
	{
		for(long long i=0;i<size;i+=2)
		{
			cout << v[i]*v[i+1] << " ";
		}
	}
	else
	{
		for(long long i=0;i<size-3;i+=2)
		{
			cout << v[i]*v[i+1] << " ";
		}

		cout << v[size-3]*v[size-2]*v[size-1];
	}

	return 0;
}