#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N;
        scanf("%d", &N);
        vector<int> mine;
        vector<int> dia;
        for(int i=0;i<2*N;i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if(x == 0)  mine.push_back(abs(y));
            if(y == 0)  dia.push_back(abs(x));
        }
        sort(mine.begin(), mine.end());
        sort(dia.begin(), dia.end());

        double ans = 0;
        for(int i=0;i<mine.size();i++)
        {
            if(i >= dia.size()) break;
            ans += sqrt(1.0*mine[i]*mine[i]+ 1.0*dia[i]*dia[i]);
        }

        printf("%.15lf\n", ans);
    }

    return 0;
}