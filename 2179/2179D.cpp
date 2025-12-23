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
    int lim = 1 << n;
    vector<int> ans(lim);
    int s = 0;
    ans[s++] = lim - 1;
    for (int k = n - 1; k >= 0; k--)
    {
        int start = (1 << k) - 1;
        int step = 1 << (k + 1);
        for (int i = start; i < lim; i += step)
        {
            ans[s++] = i;
        }
    }
    for (int i = 0; i < lim; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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