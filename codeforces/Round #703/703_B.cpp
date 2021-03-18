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
        int N;
        cin >> N;
        vector<int> x(N);
        vector<int> y(N);
        for(int i=0;i<N;i++)
            cin >> y[i] >> x[i];

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        long long X = 1, Y = 1;
        if(N%2 == 0)
        {
            X = x[N/2] - x[N/2-1] + 1;
            Y = y[N/2] - y[N/2-1] + 1;
        }
        
        cout << X*Y << endl;
    }
    return 0;
}