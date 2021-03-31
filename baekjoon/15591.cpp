#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct node
{
    int dest;
    int cost;
};

int N, Q;
vector<node> arr[5001];
bool visit[5001];
const int MAX = 1000000001;

int dfs(int v, int mini, int k)
{
    int ret = 0;
    for(int i=0;i<arr[v].size();i++)
    {
        int next = arr[v][i].dest;
        int cost = arr[v][i].cost;
        if(!visit[next])
        {
            int nextMin = min(mini, cost);
            if(nextMin >= k)
                ret++;
            visit[next] = true;

            ret += dfs(next, nextMin, k);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for(int i=0;i<N-1;i++)
    {
        int s, e, c;
        cin >> s >> e >>c;
        arr[s-1].push_back({e-1, c});
        arr[e-1].push_back({s-1, c});
    }

    for(int i=0;i<Q;i++)
    {
        memset(visit, false, sizeof(visit));
        int k, v;
        cin >> k >> v;
        visit[v-1] = true;
        cout << dfs(v-1, MAX, k) << '\n';
    }

    return 0;
}