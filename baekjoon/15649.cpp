#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> v;
bool visit[9];

void recur(int r)
{
    if(r == 0)
    {
        for(int i : v)
            cout << i << " ";
        cout << '\n';
        return;
    }

    for(int j=1;j<=N;j++)
    {
        if(visit[j])    continue;
        visit[j] = true;
        v.push_back(j);
        recur(r-1);
        v.pop_back();
        visit[j] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    cin >> N >> M;

    recur(M);


    return 0;
}