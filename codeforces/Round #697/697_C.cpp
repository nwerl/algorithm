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
        int A, B, K;
        cin >> A >> B >> K;
        vector<pair<int, int>> v(K);
        vector<int> boy(A+1);
        vector<int> girl(B+1);

        for(int i=0;i<K;i++)
        {
            cin >> v[i].first;
            boy[v[i].first]++;
        }
        for(int i=0;i<K;i++)
        {
            cin >> v[i].second;
            girl[v[i].second]++;
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        for(int i=0;i<K-1;i++)
        {
            long long add = K - i - boy[v[i].first] - girl[v[i].second]+1;
            boy[v[i].first]--;
            girl[v[i].second]--;
            if(add < 0) continue;
            ans += add;
        }

        cout << ans << endl;
    }

    return 0;
}