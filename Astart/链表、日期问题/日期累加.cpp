#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int year)
{
    if(year % 4 == 0 && year % 100 || year % 400 == 0)
        return 1;
    return 0;
}

int get_day(int y, int m)
{
    if(m == 2) return months[m] + is_leap(y);
    else return months[m];
}

int get_year_day(int y, int m)
{
    if(m <= 2) return 365 + is_leap(y);
    else return 365 + is_leap(y+1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int y, m, d, a;
        cin >> y >> m >> d >> a;
        if(m == 2 && d == 29) a--, m = 3, d = 1;
        while(a > get_year_day(y, m))
        {
            a -= get_year_day(y, m);
            y ++;
        }
        while(a--)
        {
            if(++d > get_day(y, m))
            {
                d = 1;
                if(++m > 12)
                {
                    m = 1;
                    y++;
                }
            }
        }
        printf("%04d-%02d-%02d\n", y, m ,d);
    }
    return 0;
}
