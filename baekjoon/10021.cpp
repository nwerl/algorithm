#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, C;
int parent[2001];

struct node
{
    int from;
    int to;
    int cost;
};

bool cmp(node n1, node n2)
{
    return n1.cost < n2.cost;
}

vector<node> edge;

int find(int u)
{
    if(u == parent[u])
        return u;

    return parent[u] = find(parent[u]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if(u == v)
        return false;
    
    parent[u] = v;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    vector<pair<int, int>> arr;
    for(int i=0;i<N;i++)
    {
        int y, x;
        cin >> y >> x;
        arr.push_back({y, x});
        parent[i] = i;
    }

    for(int i=0;i<N;i++)
    {
        int y1 = arr[i].first, x1 = arr[i].second;
        for(int j=i+1;j<N;j++)
        {
            int y2 = arr[j].first, x2 = arr[j].second;
            edge.push_back({i, j, (y1-y2)*(y1-y2) + (x1-x2)*(x1-x2)});
        }
    }

    sort(edge.begin(), edge.end(), cmp);

    long long ans = 0;
    int cnt = 0;

    for(int i=0;i<edge.size();i++)
    {
        if(edge[i].cost < C)    continue;

        if(merge(edge[i].from, edge[i].to)){
            cnt++;
            ans += edge[i].cost;
        }
    }

    if(cnt < N-1)   ans = -1;

    cout << ans << endl;
    
    return 0;
}