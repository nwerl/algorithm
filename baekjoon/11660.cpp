#include<iostream>

using namespace std;

int N, M;
int arr[1025][1025];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> arr[i+1][j+1];
			arr[i+1][j+1] += arr[i][j+1]+arr[i+1][j]-arr[i][j];	
		}
	}

	for(int i=0;i<M;i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[x2][y2]-arr[x1-1][y2]-arr[x2][y1-1]+arr[x1-1][y1-1] << "\n";
	}

	return 0;
}