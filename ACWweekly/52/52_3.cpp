#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int Num;

bool Check(double i)
{
    if ((i * i) / (i - 1.0) >= Num)                              //大于等于标准结果
    {
        return true;
    }
    return false;                                       //小于标准结果
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &Num);
        if (Num == 0)                                      //0要特殊处理
        {
            printf("Y 0.0000000000 0.0000000000\n");
            continue;
        }
        if (Num < 4)                                       //即b<2的情况
        {
            printf("N\n");
            continue;
        }
        double L = 2, R = 1E20, Mid;                          //注意边界
        while (R - L > 1E-8)                                 //控制精度
        {
            Mid = (L + R) / 2.0;
            if (Check(Mid))
            {
                R = Mid;
            }
            else
            {
                L = Mid;
            }
        }
        printf("Y %.10f %.10f\n", Mid, Mid / (Mid - 1.0));
    }
    return 0;
}

