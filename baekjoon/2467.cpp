#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0;i<N;i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int left = 0, right = N-1;

    int ret1, ret2;

    int ans = 2e9;
    while(left < right)
    {
        int sum = abs(v[left] + v[right]);
        if(ans > sum)
        {
            ans = sum;
            ret1 = v[left], ret2 = v[right];
        }

        if(v[left]+v[right] < 0)
            left++;
        else
            right--;
    }

    cout << ret1 << " " << ret2 << endl;

    return 0;
}