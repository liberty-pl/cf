#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n, sum = 0;
    cin >> n;
    vector<i64> v1(n),v2(n);
    for (i64 i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 1; i < n; i++)
    {
        v2[i] = v1[i] - v1[i - 1];
    }
    for (int i = 2; i < n-1; i++)
    {
        if(v2[i]>=v2[i+1]+v2[i-1]){
            sum++;
            v2[i+1] = 2e18;
        }
    }
    cout << n - sum - 1 << '\n';
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