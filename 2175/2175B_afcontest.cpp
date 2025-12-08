#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    using namespace std;
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> b(n);
    for (int i = 0; i < n;i++){
        b[i] = i+1;
    }
    b[r-1] = l-1;
    cout << b[0] << ' ';
    for (int i = 1; i < n; i++)
    {
        cout << (b[i] ^ b[i - 1]) << ' ';
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