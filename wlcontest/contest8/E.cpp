#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    static string ranks = "0123456789TJQKA";
    static string suits = "SHCD";
    auto read = [](){
        string s;
        cin >> s;
        return (find(ranks.begin(), ranks.end(), s[0]) - ranks.begin()) * 4
            + (find(suits.begin(), suits.end(), s[1]) - suits.begin());
    };
    auto write = [&](int x, int y) {
        cout << " " << ranks[x] << suits[y];
    };
    int T;
    auto Alice = [&](vector<int> a, vector<int> b) {
        set<int> sr;
        for (int ai : a) sr.insert(ai / 4);
        for (int bi : b) sr.insert(bi / 4);
        if (a[0] / 4 != a[1] / 4) {
            //Full House
            if (a[0] / 4 != b[0] / 4 and a[0] / 4 != b[1] / 4 and a[1] / 4 != b[0] / 4 and a[1] / 4 != b[1] / 4) {
                cout << "YES";
                for (int i = 0; i < 4; i += 1)
                    if (i != a[0] % 4) write(a[0] / 4, i);
                for (int i = 0; i < 4; i += 1)
                    if (i != a[1] % 4) write(a[1] / 4, i);
                return;
            }
            if (a[0] / 4 == b[0] / 4 or a[0] / 4 == b[1] / 4) swap(a[0], a[1]);
            //高牌
            if (a[0] / 4 == b[0] / 4 or a[0] / 4 == b[1] / 4) {
                cout << "YES";
                for (int i = 2, k = 6; i <= 14; i += 1)
                    if (not sr.count(i) and k) write(i, (k -= 1) % 4);
                return;
            }
            //三张
            if (b[0] / 4 == b[1] / 4) {
                cout << "YES";
                for (int i = 0; i < 4; i += 1)
                    if (i != a[0] % 4) write(a[0] / 4, i);
                for (int i = 2, k = 3; i <= 14; i += 1)
                    if (not sr.count(i) and k) write(i, (k -= 1) % 4);
                return;
            }
            //对子
            cout << "YES";
            if (b[1] / 4 != a[1] / 4) swap(b[0], b[1]);
            for (int i = 0; i < 4; i += 1)
                if (i != a[0] % 4) write(a[0] / 4, i);
            for (int i = 2, k = 3; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, (k -= 1) % 4);
            return;
        }
        //对子
        if (b[0] / 4 != b[1] / 4 or a[0] / 4 == b[0] / 4) {
            cout << "YES";
            for (int i = 2, k = 6; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, (k -= 1) % 4);
            return;
        }
        //三张
        cout << "YES";
        for (int i = 0; i < 4; i += 1)
            if (i != a[0] % 4 and i != a[1] % 4) write(a[0] / 4, i);
        for (int i = 2, k = 4; i <= 14; i += 1)
            if (not sr.count(i) and k) write(i, (k -= 1) % 4);
        return;
    };
    auto Bob = [&](vector<int> a, vector<int> b) {
        set<int> sr;
        for (int ai : a) sr.insert(ai / 4);
        for (int bi : b) sr.insert(bi / 4);
        //Flush
        if (b[0] % 4 == b[1] % 4 and (a[0] % 4 != b[0] % 4) and (a[1] % 4 != b[0] % 4)) {
            cout << "YES";
            for (int i = 2, k = 6; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, b[0] % 4), k -= 1;
            return;
        }
        if (b[0] / 4 != b[1] / 4) {
            //Full House
            if (a[0] / 4 != b[0] / 4 and a[0] / 4 != b[1] / 4 and a[1] / 4 != b[0] / 4 and a[1] / 4 != b[1] / 4) {
                cout << "YES";
                for (int i = 0; i < 4; i += 1)
                    if (i != b[0] % 4) write(b[0] / 4, i);
                for (int i = 0; i < 4; i += 1)
                    if (i != b[1] % 4) write(b[1] / 4, i);
                return;
            }
            //对子
            if (a[0] / 4 == a[1] / 4) {
                if (b[0] / 4 == a[0] / 4) swap(b[0], b[1]);
                if (b[0] / 4 < a[0] / 4) {
                    //Straight
                    if (a[0] / 4 - b[0] / 4 <= 4) {
                        cout << "YES";
                        int s = max(a[0] / 4 - 4, 2);
                        for (int i = s; i <= s + 4; i += 1)
                            if (i != b[0] / 4 and i != a[0] / 4) {
                                write(i, i % 2 * 2);
                                write(i, i % 2 * 2 + 1);
                            }
                        return;
                    }
                    if (b[1] / 4 == 14 and b[0] / 4 <= 5) {
                        cout << "YES";
                        for (int i = 2; i <= 5; i += 1)
                            if (i != b[0] / 4) {
                                write(i, i % 2 * 2);
                                write(i, i % 2 * 2 + 1);
                            }
                        return;
                    }
                    if (a[0] / 4 != 14 and b[0] / 4 != 14) {
                        cout << "YES";
                        for (int i = 0, k = 3; i < 4; i += 1)
                            if (k) write(14, i), k -= 1;
                        for (int i = 0; i < 4; i += 1)
                            if (i != b[0] % 4) write(b[0] / 4, i);
                        return;
                    }
                    cout << "NO";//A A vs 7 A
                    return;
                }
                cout << "YES";
                for (int i = 0, k = 2; i < 4; i += 1)
                    if (i != b[0] % 4 and k) write(b[0] / 4, i), k -= 1;
                for (int i = 2, k = 4; i <= 14; i += 1)
                    if (not sr.count(i) and k) write(i, (k -= 1) % 4);
                return;
            }
            //对子
            if (b[0] / 4 == a[0] / 4 or b[0] / 4 == a[1] / 4) swap(b[0], b[1]);
            if (b[0] / 4 == a[0] / 4 or b[0] / 4 == a[1] / 4) {
                cout << "NO"; //K J KS JH
                return;
            }
            cout << "YES";
            for (int i = 0, k = 2; i < 4; i += 1)
                if (i != b[0] % 4 and k) write(b[0] / 4, i), k -= 1;
            if (a[0] / 4 > 8) {
            for (int i = 2, k = 4; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, (k -= 1) % 4);
            }
            else {
                for (int i = 14, k = 4; i >= 2; i -= 1)
                    if (not sr.count(i) and k) write(i, (k -= 1) % 4);
            }
            return;
        }
        //对子
        if (a[0] / 4 != a[1] / 4) {
            cout << "YES";
            for (int i = 2, k = 6; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, (k -= 1) % 4);
            return;
        }
        if (a[0] / 4 == b[0] / 4) {
            cout << "NO"; //KS KH KC KD
            return;
        }
        //三张
        cout << "YES";
        for (int i = 0, k = 2; i < 4; i += 1)
            if (i != b[0] % 4 and i != b[1] % 4 and k) write(b[0] / 4, i), k -= 1;
        for (int i = 2, k = 4; i <= 14; i += 1)
            if (not sr.count(i) and k) write(i, (k -= 1) % 4);
        return;
    };
    auto Draw = [&](vector<int> a, vector<int> b) {
        set<int> sr;
        for (int ai : a) sr.insert(ai / 4);
        for (int bi : b) sr.insert(bi / 4);
        if (a[0] / 4 > a[1] / 4) swap(a[0], a[1]);
        if (b[0] / 4 > b[1] / 4) swap(b[0], b[1]);
        if (a[0] / 4 == b[0] / 4 and a[1] / 4 == b[1] / 4) {
            cout << "YES";
            for (int i = 2, k = 3; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, 2 * k % 4), write(i, (2 * k + 1) % 4), k -= 1;
            return;
        }
        if (a[0] / 4 == a[1] / 4) {
            cout << "NO"; //KS KH QS QH
            return;
        }
        if (b[0] / 4 == b[1] / 4) {
            if (a[0] / 4 == b[0] / 4 or a[1] / 4 == b[0] / 4) {
                if (a[0] / 4 != b[0] / 4) swap(a[0], a[1]);
                cout << "YES";
                for (int i = 0; i < 4; i += 1)
                    if (i != a[0] % 4 and i != b[0] % 4 and i != b[1] % 4) write(a[0] / 4, i);
                for (int i = 0, k = 1; i < 4; i += 1)
                    if (i != a[1] % 4 and k) write(a[1] / 4, i), k -= 1;
                for (int i = 2, k = 2; i <= 14; i += 1)
                    if (not sr.count(i) and k) write(i, 2 * k % 4), write(i, (2 * k + 1) % 4), k -= 1;
                return;
            }
            cout << "NO";//3S 4S QC QD
            return;
        }
        if (a[0] / 4 == b[0] / 4 or a[0] / 4 == b[1] / 4 or a[1] / 4 == b[0] / 4 or a[1] / 4 == b[1] / 4) {
            if (a[0] / 4 == b[0] / 4 or a[0] / 4 == b[1] / 4) swap(a[0], a[1]);
            if (b[0] / 4 == a[1] / 4) swap(b[0], b[1]);
            if (a[0] / 4 > b[0] / 4) {
                if (a[0] / 4 > a[1] / 4 and b[0] / 4 < b[1] / 4) {
                    cout << "YES";
                    for (int i = 0; i < 4; i += 1)
                        if (i != b[0] % 4 and i != b[0] % 4) write(b[0] / 4, i);
                    for (int i = 0; i < 4; i += 1)
                        if (i != a[0] % 4) {
                            write(a[0] / 4, i);
                            break;
                        }
                    for (int i = 2; i <= 14; i += 1)
                        if (not sr.count(i)) {
                            write(i, 0);
                            write(i, 1);
                            break;
                        }
                    return;
                }
                cout << "YES";
                for (int i = 0; i < 4; i += 1)
                    if (i != b[1] % 4 and i != a[1] % 4) write(b[1] / 4, i);
                for (int i = 0; i < 4; i += 1)
                    if (i != b[0] % 4) write(b[0] / 4, i);
                for (int i = 0; i < 4; i += 1)
                    if (i != a[0] % 4) {
                        write(a[0] / 4, i);
                        break;
                    }
                return;
            }
            cout << "YES";
            for (int i = 0, k = 1; i < 4; i += 1)
                if (i != b[0] % 4 and k) write(b[0] / 4, i), k -= 1;
            for (int i = 0, k = 1; i < 4; i += 1)
                if (i != a[0] % 4 and k) write(a[0] / 4, i), k -= 1;
            for (int i = 2, k = 2; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, 2 * k % 4), write(i, (2 * k + 1) % 4), k -= 1;
            return;
        }
        if (a[0] / 4 < b[0] / 4 and b[0] / 4 < a[1] / 4 and a[1] / 4 < b[1] / 4) {
            cout << "YES";
            for (int i = 0, k = 1; i < 4; i += 1)
                if (i != a[0] % 4 and k) write(a[0] / 4, i), k -= 1;
            for (int i = 0, k = 1; i < 4; i += 1)
                if (i != a[1] % 4 and k) write(a[1] / 4, i), k -= 1;
            for (int i = 0, k = 1; i < 4; i += 1)
                if (i != b[0] % 4 and k) write(b[0] / 4, i), k -= 1;
            for (int i = 0, k = 1; i < 4; i += 1)
                if (i != b[1] % 4 and k) write(b[1] / 4, i), k -= 1;
            for (int i = 2, k = 1; i <= 14; i += 1)
                if (not sr.count(i) and k) write(i, 2 * k % 4), write(i, (2 * k + 1) % 4), k -= 1;
            return;
        }
        if (a[0] / 4 < b[0] / 4 and b[0] / 4 < b[1] / 4 and b[1] / 4 < a[1] / 4) {
            cout << "YES";
            for (int i = 0; i < 4; i += 1)
                if (i != a[0] % 4) {
                    write(a[0] / 4, i);
                    break;
                }
            for (int i = 0; i < 4; i += 1)
                if (i != a[1] % 4) {
                    write(a[1] / 4, i);
                    break;
                }
            for (int i = 0; i < 4; i += 1)
                if (i != b[0] % 4) {
                    write(b[0] / 4, i);
                    break;
                }
            for (int i = 0; i < 4; i += 1)
                if (i != b[1] % 4) {
                    write(b[1] / 4, i);
                }
            return;
        }
        if (b[0] / 4 < a[0] / 4 and a[0] / 4 < b[1] / 4 and b[1] / 4 < a[1] / 4) {
            cout << "YES";
            for (int i = 0; i < 4; i += 1)
                if (i != a[0] % 4) {
                    write(a[0] / 4, i);
                    break;
                }
            for (int i = 0; i < 4; i += 1)
                if (i != a[1] % 4) {
                    write(a[1] / 4, i);
                    break;
                }
            for (int i = 0; i < 4; i += 1)
                if (i != b[0] % 4) {
                    write(b[0] / 4, i);
                }
            for (int i = 0; i < 4; i += 1)
                if (i != b[1] % 4) {
                    write(b[1] / 4, i);
                    break;
                }
            return;
        }
        cout << "NO";
    };
    for (cin >> T; T; T -= 1) {
        vector<int> a(2), b(2);
        for (int& ai : a) ai = read();
        for (int& bi : b) bi = read();
        //Alice(a, b); cout << "\n";
        //Bob(a, b); cout << "\n";
        Draw(a, b); cout << "\n";
    }
}
