#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;

        for(int i=0;i<K-3;i++)
            cout << "1" << " ";
        
        N -= K-3;
        K = 3;
        

        if(N%2==0)
        {
            if((N/2)%2==0)
                cout << N/2 << " " << N/2/2 << " " << N/2/2 << endl;
            else
                cout << 2 << " " << (N-2)/2 << " " << (N-2)/2 << endl;
        }
        else
        {
            cout << 1 << " " << (N-1)/2 << " " << (N-1)/2 << endl;
        }
    }
    


    return 0;
}