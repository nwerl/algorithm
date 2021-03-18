#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        
        cin >> N;
        vector<long long> v(N);
        for(int i=0;i<N;i++)
            cin >> v[i];

        string ans = "YES";
        for(int i=0;i<N-1;i++)
        {
            long long add = v[i] - i;
            if(add>0)
                v[i+1] += add;

            if(v[i+1] < i+1)
            {
                ans = "NO";
                break;
            }
        }

        cout << ans << endl;   
    }
    return 0;
}