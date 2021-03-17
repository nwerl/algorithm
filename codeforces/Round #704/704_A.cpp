#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        vector<long long> v(3, 0);
        long long P;
        cin >> P >> v[0] >> v[1] >> v[2];

        long long ans = LLONG_MAX;
        for(int i=0;i<3;i++)
        {
            if(P > v[i])
            {
                long long tmp = -1;
                if(P%v[i] == 0)
                    tmp = 0;
                else
                {
                    tmp = (P/v[i]+1)*v[i]-P;
                }
                ans = min(ans, tmp);
            }
            else
            {
                ans = min(ans, v[i] - P);
            }
        }

        cout << ans << endl;
    }

    return 0;
}