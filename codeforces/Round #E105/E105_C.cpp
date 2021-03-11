#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		vector<int> box(N);
		vector<int> pos(N);
		for(int i=0;i<N;i++)
			cin >> box[i];
		for(int i=0;i<M;i++)
			cin >> pos[i];

		sort(box.begin(), box.end());
		sort(pos.begin(), pos.end());
	}

	return 0;
}