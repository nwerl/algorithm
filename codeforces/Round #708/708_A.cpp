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
        vector<int> a;
        vector<int> b;
        vector<bool> chk(101, false);
        for(int i=0;i<N;i++)
        {
            int tmp;
            cin >> tmp;
            if(chk[tmp])
                b.push_back(tmp);
            else
            {
                chk[tmp] = true;
                a.push_back(tmp);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        a.insert(a.end(), b.begin(), b.end());

        for(int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}