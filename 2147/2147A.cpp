#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 a, b;
    cin >> a >> b;
    if(b > a){
        cout << 2 << '\n';
        return;
    }
    if(b == a || b == 1){
        cout << -1 << '\n';
        return;
    }
    if (a-1 > b){
        cout << 3 << '\n';
    } else {
        cout << -1 << '\n';
    }
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