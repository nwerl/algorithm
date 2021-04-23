#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> v[1001];
int room[1001];
int visit[1001];
int N;
string answer = "No";

void dfs(int idx, int money)
{
    if(room[idx] > 0 && money<room[idx])
        money = room[idx];
    else if(room[idx] < 0)
    {
        if(money < -room[idx])
            return;
        else
            money += room[idx];
    }

    if(idx == N)
    {
        answer = "Yes";
        return;
    }

    visit[idx] = true;
    for(int i=0;i<v[idx].size();i++)
    {
        int next = v[idx][i];
        if(visit[next]) continue;
        dfs(next, money);
    }
    visit[idx] = false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        answer = "No";
        cin >> N;
        if(N == 0)  return 0;

        for(int i=0;i<1001;i++)
            v[i].clear();
        memset(room, 0, sizeof(room));

        for(int i=1;i<=N;i++)
        {
            char ch;
            int cost, nextRoom;
            cin >> ch >> cost >> nextRoom;

            if(ch == 'L')
                room[i] = cost;
            else if(ch == 'T')
                room[i] = -cost;

            while(nextRoom)
            {
                v[i].push_back(nextRoom);
                cin >> nextRoom;
            }
        }
        dfs(1, 0);

        cout << answer << endl;
    }
    


    return 0;
}