#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<int> v(N);
        vector<bool> chk(N+1, false);

        for(int i=0;i<N;i++)
            cin >> v[i];

        int tar = N;
        int idx = N-1;
        while(idx >= 0)
        {
            for(int i=tar;i>=1;i--)
            {
                if(!chk[i])
                {
                    tar = i;
                    chk[i] = true;
                    break;
                }
            }
            int bp; 
            for(bp=idx;bp>=0;bp--)
            {
                chk[v[bp]] = true;
                if(v[bp] == tar)
                    break;
            }

            for(int i=bp;i<=idx;i++)
                cout << v[i] << " ";

            idx = bp-1;
        }
        
        cout << "\n";
        
    }

    return 0;
}