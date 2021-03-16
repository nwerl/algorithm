#include<iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long N;
        cin >> N;

        while(N%2==0)
            N/=2;

        N==1?cout << "NO" << endl : cout << "YES" << endl;
    }

    return 0;
}