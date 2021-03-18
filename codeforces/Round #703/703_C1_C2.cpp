#include<iostream>

using namespace std;

int query(int l, int r)
{
    if(l >= r)  return -1;
    cout << "?" << " " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    
    int second = query(1, N);
    if(second == 1 || query(1, second) != second)
    {
        int left = second, right = N;
        while(right - left > 1)
        {
            int mid = (left+right)/2;
            if(query(second, mid) == second)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        cout << "! " << right << endl;
    }
    else
    {
        int left = 1, right = second;
        while(right - left > 1)
        {
            int mid = (left+right)/2;
            if(query(mid, second) == second)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        cout << "! " << left << endl;
    }

    
    
    return 0;
}