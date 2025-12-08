#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    using namespace std;
    string s,t,sortedt;
    cin >> s >> t;
    for (char x : s){
        size_t pos = t.find(x);
        if (pos == string::npos){
            cout << "Impossible\n";
            return;
        } else {
            t.erase(pos, 1);
        }
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < s.size(); j++)
        {
            if(t[i]<s[j]) {
                s.insert(j, 1,t[i]);
                flag = false;
                break;
            }
        }
        if (flag)
        s += t[i];
    }
    cout << s << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}