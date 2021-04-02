#include<iostream>
#include<vector>

using namespace std;

int N, L, M;
vector<pair<int, int>> fish;
int dir[4][2] = {{-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

int main()
{
    cin >> N >> L >> M;
    for(int i=0;i<M;i++)
    {
        int y, x;
        cin >> y >> x;
        fish.push_back({y-1, x-1});
    }
    
    int ans = 0;
    for(auto p : fish)
    {
        int y = p.first, x = p.second;
        for(int h=1;h<L/2;h++)
        {
            int w = L/2-h;
            if(w>N-1 || h >N-1) continue;
            for(int k=0;k<=w;k++)
            {
                int ret = 0;
                for(auto q : fish)
                {
                    int ny = q.first, nx = q.second;
                    if(ny>y+h || ny<y)  continue;
                    if(x-k+w>=nx && x-k<=nx)    ret++;
                }
                ans = max(ans, ret);
            }
        }
    }

    cout << ans << endl;

    return 0;
}