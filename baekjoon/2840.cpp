#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<char> arr(N, '?');
    vector<int> alpha(26, -1);

    int nextIdx = 0, nextChar = '?';
    for(int i=0;i<K;i++)
    {
        int num;
        char ch;
        cin >> num >> ch;

        nextIdx = (nextIdx+num)%N;

        if((arr[nextIdx] != '?' && arr[nextIdx] != ch) || (alpha[ch-'A'] != -1 && alpha[ch-'A'] != nextIdx))
        {
            cout << "!" << endl;
            return 0;
        }
        arr[nextIdx] = ch;
        alpha[ch-'A'] = nextIdx;
    }

    for(int i=0;i<N;i++)
    {
        cout << arr[nextIdx--];
        nextIdx = nextIdx < 0 ? N-1 : nextIdx;
    }

    return 0;
}