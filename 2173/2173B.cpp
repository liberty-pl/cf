#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    using namespace std;
    int n;
    i64 k = 0;
    cin >> n;
    vector<i64> v1(n);
    vector<i64> v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    vector<i64> maxi(n);
    vector<i64> mini(n);
    maxi[0] = max(-v1[0], v2[0]);
    mini[0] = min(-v1[0], v2[0]);
    for (int i = 1; i < n; i++)
    {
        maxi[i] = max(maxi[i - 1] - v1[i], v2[i] - mini[i - 1]);
        mini[i] = min(mini[i - 1] - v1[i], v2[i] - maxi[i - 1]);
    }
    cout << maxi[n - 1] << endl;
    /* solution(easier)
    ll mx = 0, mn = 0;
    for (int i = 1; i <= n; ++i) {
        ll new_mx = max(mx - a[i], b[i] - mn);
        ll new_mn = min(mn - a[i], b[i] - mx);
        mx = new_mx, mn = new_mn;
    }
    cout << mx << endl;
    */
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