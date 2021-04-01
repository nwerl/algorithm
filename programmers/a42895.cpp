#include <string>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> v(9);

void setUnion(int a, int b)
{
    for(auto i : v[a])
    {
        for(auto j : v[b])
        {
            v[a+b].insert(i+j);
            v[a+b].insert(i-j);
            v[a+b].insert(i*j);
            if(j)
                v[a+b].insert(i/j);
        }
    }
}

int solution(int N, int number) {
    int answer = 0;
    int tmp = N;
    for(int i=1;i<=8;i++)
    {
        v[i].insert(tmp);
        tmp = tmp*10+N;
    }
    
    for(int i=2;i<=8;i++)
    {
        for(int j=1;j<i;j++)
        {
            setUnion(i-j, j);
        }
    }
    
    for(int i=1;i<=8;i++)
    {
        if(v[i].find(number) != v[i].end())
            return i;
    }
    
    return -1;
}