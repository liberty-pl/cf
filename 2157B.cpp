#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int c;
    cin >> c;
    while (c--) {
        ll n, x, y,t = 0;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        x = abs(x);
        y = abs(y);
        for (ll i = 0; i < s.size(); i++) {
            if (s[i] == '4') {
                t++;
            }
        }
        if (x + y <= n + n - t && max(x , y) <= n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}