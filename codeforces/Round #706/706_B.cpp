#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int MAX = 1000000001;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        set<int> set;
        for(int i=0;i<N;i++)
        {
            cin >> arr[i];
            set.insert(arr[i]);
        }
        if(K == 0)
        {
            cout << N << endl;
            continue;
        }
        sort(arr.begin(), arr.end());
        int add = K;
        int idx = 0;

        for(int i=0;i<N;i++)
        {
            if(idx != arr[i])
            {
                int val = (idx + arr[N-1])/2;
                if((idx+arr[N-1])%2==1) val++;
                set.insert(val);
                add = 0;
                break;
            }
            idx++;
        }

        cout << set.size() + add << endl;
    }

    return 0;
}