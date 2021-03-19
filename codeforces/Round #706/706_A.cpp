#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;
        string s;
        cin >> s;
        if(K == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        if(N%2 == 0 && K == N/2)
        {
            cout << "NO" << endl;
            continue;
        }
        string ans = "NO";

        for(int i=0;i<N;i++)
        {
            if(s[i] != s[N-i-1])
                break;

            if(i == K-1)
            {
                ans = "YES";
                break;
            }
        }

        cout << ans << endl;
        
    }

    return 0;
}