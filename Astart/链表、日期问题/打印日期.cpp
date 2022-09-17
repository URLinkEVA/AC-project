#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

int is_leap(int year)
{
    if(year % 4 == 0 && year % 100 || year % 400 == 0)
        return 1;
    else return 0;
}

int get_day(int y, int m) // y年m月
{
    if(m == 2) return months[m] + is_leap(y);
    return months[m];
}

int main()
{
    int y, s;
    while(cin >> y >> s)
    {
        int m = 1, d = 1;
        s--;
        while (s -- )
        {
            if ( ++ d > get_day(y, m))
            {
                d = 1;
                if ( ++ m > 12)
                {
                    m = 1;
                    y ++ ;
                }
            }
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}
