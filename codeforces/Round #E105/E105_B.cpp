#include<iostream>
#include<vector>

using namespace std;

int N, U, R, D, L;

bool recur(int i, vector<int>& dir, vector<int>& cnt)
{
	for(int d=0;d<4;d++)
	{
		if((dir[d] == 0 || dir[d] == 1 ) && (cnt[d] > dir[d]))
			return false;
	}


	if(i == 4)
		return true;

	

	bool flag = false;

	if(dir[i] == N)
	{
		cnt[(i+1)%4]++;
		cnt[(i+3)%4]++;
		flag = flag || recur(i+1, dir, cnt);
		cnt[(i+1)%4]--;
		cnt[(i+3)%4]--;
	}
	else if(dir[i] == N-1)
	{
		cnt[(i+1)%4]++;
		flag = flag || recur(i+1, dir, cnt);
		cnt[(i+1)%4]--;
		cnt[(i+3)%4]++;
		flag = flag || recur(i+1, dir, cnt);
		cnt[(i+3)%4]--;
	}
	else
		flag = flag || recur(i+1, dir, cnt);

	return flag;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		vector<int> dir(4, 0);
		cin >> N >> U >> R >> D >> L;
		dir[0] = U, dir[1] = R, dir[2] = D, dir[3] = L;
		vector<int> cnt(4, 0);
		
		recur(0, dir, cnt) ? cout << "YES" << "\n" : cout << "NO" << "\n";
	}

	return 0;
}