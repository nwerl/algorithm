#include<stdio.h>

int N, M;
int arr[9][9];

int vi[82]; 
int vj[82]; int VirusCounter;

bool chk[9][9];
bool visited[9][9];

int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int output;

int max(int a, int b)
{
	return (a>b)?a:b;
}

void dfs(int pi, int pj)
{

	visited[pi][pj] = true;

	for(int i=0;i<4;i++)
	{
		int ni = pi + dir[i][0];
		int nj = pj + dir[i][1];

		if(ni>=0 && ni<N && nj>=0 && nj<M)
		{
			if(!visited[ni][nj])
			{
				dfs(ni, nj);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);


	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 2)
			{
				vi[VirusCounter] = i;
				vj[VirusCounter++] = j;
				chk[i][j] = true;
			}
			else if(arr[i][j] == 1)
			{
				chk[i][j] = true;
			}
		}
	}



	for(int ai=0;ai<N;ai++)
	{
		for(int aj=0;aj<M;aj++)
		{
			for(int bi=0;bi<N;bi++)
			{
				for(int bj=0;bj<M;bj++)
				{
					for(int ci=0;ci<N;ci++)
					{
						for(int cj=0;cj<M;cj++)
						{
							if(!(ai==bi && aj==bj) && !(ai==ci && aj==cj) && !(bi==ci && cj==bj) && !chk[ai][aj] && !chk[bi][bj] && !chk[ci][cj])
							{
								for(int i=0;i<N;i++)
								{
									for(int j=0;j<M;j++)
									{
										visited[i][j] = chk[i][j];
									}
								}
								visited[ai][aj] = true; visited[bi][bj] = true; visited[ci][cj] = true;
								
								for(int v=0;v<VirusCounter;v++)
								{
									dfs(vi[v], vj[v]);
								}

								int tmp = 0;
								for(int i=0;i<N;i++)
								{
									for(int j=0;j<M;j++)
									{
										if(!visited[i][j])
										{
											tmp++;
										}
									}
								}
								output = max(output, tmp);
							}
						}
					}
				}
			}
		}
	}

	printf("%d", output);

	return 0;
}