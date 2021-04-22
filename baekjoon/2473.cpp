#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> v(N);
    for(int i=0;i<N;i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    long long MIN = __LONG_LONG_MAX__;
    int ans[3];
    for(int i=0;i<N;i++)
    {
        int left = i+1, right = N-1;
        while(left < right)
        {
            long long sum = v[left]+v[right]+v[i];
            if(MIN > llabs(sum))
            {
                MIN = llabs(sum);
                ans[0] = v[i];
                ans[1] = v[left];
                ans[2] = v[right];
            }

            if(sum < 0)
                left++;
            else
                right--;
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    
    return 0;
}