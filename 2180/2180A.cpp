#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 l, a, b;
    cin >> l >> a >> b;
    if (b%l==0){
        cout << a << '\n';
        return;
    }
    i64 g = std::gcd(b, l);
    i64 ans = a + ((l - 1 - a) / g) * g;
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