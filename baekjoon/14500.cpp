#include<stdio.h>
#include<algorithm>

using namespace std;

int N, M;
int arr[501][501];
bool chk[501][501];

int output;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void fuck(int y, int x)
{
	int sum = 0;
	if(x<M-1 && x<M-2 && y>0)
	{
		sum += arr[y][x];
		sum += arr[y][x+1];
		sum += arr[y][x+2];
		sum += arr[y-1][x+1];
		output = max(output, sum);
		sum = 0;
	}
	if(x<M-1 && x<M-2 && y<N-1)
	{
		sum += arr[y][x];
		sum += arr[y][x+1];
		sum += arr[y][x+2];
		sum += arr[y+1][x+1];
		output = max(output, sum);
		sum = 0;
	}
	if(y<N-1 && y<N-2 && x<M-1)
	{
		sum += arr[y][x];
		sum += arr[y+1][x];
		sum += arr[y+2][x];
		sum += arr[y+1][x+1];
		output = max(output, sum);
		sum = 0;
	}
	if(x<M-1 && y>0 && y<N-1)
	{
		sum += arr[y][x];
		sum += arr[y][x+1];
		sum += arr[y-1][x+1];
		sum += arr[y+1][x+1];
		output = max(output, sum);
		sum = 0;
	}
}

void dfs(int y, int x, int depth, int sum)
{
	if(depth>3)
	{
		output = max(output, sum);
		return;
	}

	for(int i=0;i<4;i++)
	{
		int ny = y+dir[i][0];
		int nx = x+dir[i][1];

		if(ny>=0 && ny<N && nx>=0 && nx<M && !chk[ny][nx])
		{
			chk[y][x] = true;
			dfs(ny, nx, depth+1, sum+arr[y][x]);
			chk[y][x] = false;
		}
	}
}

int main()
{
	scanf("%d %d" ,&N ,&M);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			dfs(i, j, 0, 0);
			fuck(i, j);
		}
	}

	printf("%d", output);

	return 0;
}