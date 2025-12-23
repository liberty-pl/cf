#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n, ans = 0, max_delta = -10000000;
    cin >> n;
    vector<int> v1(n+1), v2(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        v2[i] = v1[i] - v1[i + 1];
        ans += abs(v2[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(i == 0){
            if(abs(v2[0]) > max_delta){
                max_delta = abs(v2[0]);
            }
        } else if (i == n-1){
            if(abs(v2[n-2]) > max_delta){
                max_delta = abs(v2[n - 2]);
            }
        } else {
            if(-abs(v2[i-1]+v2[i])+abs(v2[i-1])+abs(v2[i]) > max_delta){
                max_delta = -abs(v2[i-1] + v2[i]) + abs(v2[i-1]) + abs(v2[i]);
            }
        }
    }
    cout << ans - max_delta << '\n';
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