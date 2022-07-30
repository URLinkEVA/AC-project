#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    printf("%d:%d:%d", t/3600, t%3600/60, t%60);
    return 0;
}
