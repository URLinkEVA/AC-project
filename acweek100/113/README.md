# AcWing 5053. abc

# AcWing 5054. 拼接字符串

## 字符串清除非字母
```
#include <iostream>
using namespace std;
int main() {
    string line;
    string tmp = "";
    line =  "Okqf_";
    for (int i = 0; i < line.size(); ++i) {
        if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
            tmp = tmp + line[i];
        }
    }
    line = tmp;
    cout << line;
    return 0;
}
```

# AcWing 5055. 画矩形
