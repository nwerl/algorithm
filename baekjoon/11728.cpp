#include<iostream>

using namespace std;

int N, M;
int a[1000001];
int b[1000001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> a[i];
	for(int i=0;i<M;i++)
		cin >> b[i];

	int a_idx = 0, b_idx = 0;
	
	while(a_idx < N && b_idx < M)
	{
		if(a[a_idx] < b[b_idx])
			cout << a[a_idx++] << " ";
		else if(a[a_idx] >= b[b_idx])
			cout << b[b_idx++] << " ";
	}

	while(a_idx < N)
		cout << a[a_idx++] << " ";
	while(b_idx < M)
		cout << b[b_idx++] << " ";

	return 0;
}