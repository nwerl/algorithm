#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N*2);
    vector<bool> isRobot(N*2);
    queue<int> robot;
    for(int i=0;i<N*2;i++)
        cin >> arr[i];

    int ans = 0;
    int left = 0, right = N-1;
    while(++ans)
    {
        //one
        left = left-1==-1 ? 2*N-1 : left-1;
        right = right-1==-1 ? 2*N-1 : right-1;

        //two
        int size = robot.size();
        for(int i=0;i<size;i++)
        {
            int idx = robot.front();
            robot.pop();

            if(idx == right)
            {
                isRobot[idx] = false;
                continue;
            }

            int nextIdx = idx+1==2*N ? 0 : idx+1;
            
            if(arr[nextIdx] && !isRobot[nextIdx])
            {
                
                isRobot[idx] = false;
                arr[nextIdx]--;

                if(nextIdx != right)
                {
                    isRobot[nextIdx] = true;
                    robot.push(nextIdx);
                }
            }
            else
                robot.push(idx);
        }

        //three
        if(!isRobot[left] && arr[left])
        {
            isRobot[left] = true;
            arr[left]--;
            robot.push(left);
        }

        //four
        int cnt = 0;
        for(int i=0;i<N*2;i++)
        {
            if(!arr[i])
                cnt++;
        }

        if(cnt >= K) break;
    }


    cout << ans << endl;

    return 0;
}