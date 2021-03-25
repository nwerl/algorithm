#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1e18;
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<long long> c(N);
        vector<long long> rem(2, INF);
        vector<long long> xy(2, N);
        long long sum = 0;
        for(int i=0;i<N;i++)
            cin >> c[i];
        long long ans = INF;
        for(int i=0;i<N;i++)
        {
            rem[i%2] = min(rem[i%2], c[i]);
            sum += c[i];
            xy[i%2]--;
 
            if(i>0)
            {
                long long tmp = xy[0]*rem[0]+xy[1]*rem[1]+sum;
                ans = min(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}