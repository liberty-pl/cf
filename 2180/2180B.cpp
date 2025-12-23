#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string m[1010];
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    string ans = m[0];
    for (int i = 1; i < n; i++)
    {
        if(ans +m[i] > m[i]+ans){
            ans = m[i] + ans;
        } else {
            ans += m[i];
        }
    }
    cout << ans << '\n';
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