#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> arr;
        vector<int> hash(M, 0);
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            int tmp;
            cin >> tmp;
            if(tmp%M != 0)
                hash[tmp%M]++;
            else
                ans = 1;
        }

        for(int i=1;i<=M/2;i++)
        {
            if(!hash[i] || !hash[M-i])    continue;
            
            if(hash[i] > hash[M-i])
            {
                hash[i] -= hash[M-i];
                hash[M-i] = 0;
            }
            else if(hash[i] < hash[M-i])
            {
                hash[M-i] -= hash[i];
                hash[i] = 0;
            }
            else
            {
                hash[M-i] = 0;
                hash[i] = 1;
            }
        }

        for(int i=1;i<M;i++)
            ans += hash[i];

        cout << ans << "\n";
    }

    return 0;
}