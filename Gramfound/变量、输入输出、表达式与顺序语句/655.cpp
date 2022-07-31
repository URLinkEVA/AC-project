#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a;
    cin >> a;
    
    printf("%d ano(s)\n", a/365); a %= 365;
    printf("%d mes(es)\n", a/30); a %= 30;
    printf("%d dia(s)\n", a);
    return 0;
}
