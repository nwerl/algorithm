#include<iostream>
#include<climits>

using namespace std;

int dp[11][11];
int dp2[11][11];
char str[21];
int N;

int recur(int start, int end)
{
    if(dp[start][end] != INT_MIN)   return dp[start][end];

    for(int i=1;end-i>=start;i++)
    {
        int add = 0;
        char sign = str[end*2-i*2+1];
        switch(sign)
        {
            case '+':
                add = recur(start, end-i)+recur(end-i+1, end);
                break;
            case '-':
                add = recur(start, end-i)+recur(end-i+1, end);
                break;
            case '*':
                add = recur(start, end-i)*recur(end-i+1, end);
                break;
        }
        dp[start][end] = max(dp[start][end], add);
    }

    return dp[start][end];
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        char ch;
        cin >> ch;
        str[i] = ch;
    }
    str[N] = '\0';

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            dp[i][j] = INT_MIN;
            dp2[i][j] = INT_MAX;
        }
    }

    for(int i=0;i<=N/2;i++)
        dp[i][i] = dp2[i][i] = str[i*2]-'0';
        
    

    cout << recur(0, N/2) << endl;


    return 0;
}