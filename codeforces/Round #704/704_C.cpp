#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    string s, t;
    cin >> s >> t;
    int idx = 0;
    vector<int> left;
    

    for(int i=0;i<N;i++)
    {
        if(s[i] == t[idx])
        {
            left.push_back(i);
            idx++;
        }

        if(idx>=M)  break;
    }

    idx = M-1;
    vector<int> right;
    for(int i=N-1;i>=0;i--)
    {
        if(s[i] == t[idx])
        {
            right.push_back(i);
            idx--;
        }

        if(idx<0)  break;
    }
    reverse(right.begin(), right.end());

    int ans = 0;
    for(int i=0;i<M-1;i++)
    {
        ans = max(ans, abs(left[i] - right[i+1]));
        ans = max(ans, abs(left[i+1] - right[i]));
    }

    cout << ans << endl;

    return 0;
}