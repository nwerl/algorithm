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
        string s;
        cin >> s;
        int N = s.length();

        bool flag = false;

        string ans = "YES";

        for(int i=1;i<N;i++)
        {
            if(s[i] == '1' && s[i-1] == '1')
                flag = true;
            if(s[i] == '0' && s[i-1] == '0' && flag)
            {
                ans = "NO";
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}