#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        vector<bool> v1(n);
        vector<bool> v2(n);
        for(int i=0;i<k1;i++)   v1[i] = true;
        for(int i=0;i<k2;i++)   v2[i] = true;

        if(w == 0 && b == 0)
        {
            cout << "YES" << endl;
            continue;
        } 

        if(!(w*2 <= (k1+k2) && b*2 <= 2*n-(k1+k2)))
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }

    return 0;
}