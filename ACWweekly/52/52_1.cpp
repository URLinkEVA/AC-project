#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int res = 0;
    
    for(int i = 1;i < 10000;i++)
    {
        int tmp = i*(i + 1)/2;
        if(tmp > n)
        {
            break;
        }
        else
        {
            res++;
            n -= tmp;
        }
    }
    cout<< res <<endl;
    return 0;
}
