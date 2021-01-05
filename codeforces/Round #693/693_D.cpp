#include<iostream>
#include<vector>
#include<queue>
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
		priority_queue<long long> odd;
		priority_queue<long long> even;
		for(int i=0;i<N;i++)
		{
			int a;
			cin >> a;
			if(a%2==1)	odd.push(a);
			else		even.push(a);
		}

		long long bob = 0, alice = 0;
		for(int i=0;i<N;i++)
		{
			if(i%2==0)
			{
				if(!even.empty())
				{
					if(!odd.empty() && odd.top() > even.top())	odd.pop();
					else
					{
						alice+=even.top();
						even.pop();
					}
				}
				else
				{
					odd.pop();
				}
			}
			else
			{
				if(!odd.empty())
				{
					if(!even.empty() && even.top() > odd.top())	even.pop();
					else
					{
						bob+=odd.top();
						odd.pop();
					}
				}
				else
				{
					even.pop();
				}
			}
		}

		if(bob>alice)	cout << "Bob" << endl;
		else if(alice>bob)	cout << "Alice" << endl;
		else			cout << "Tie" << endl;
	}

	return 0;
}