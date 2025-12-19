#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n,k;
    cin >> n >> k;
    if(k%2){
        for (i64 i = 0; i < k; i++)
        {
            cout << n << ' ';
        }
        cout << '\n';
    } else {
        i64 maxa = 0, maxb = 0, maxn = -1;
        for (i64 i = n; i >= 0;i--){
            for (i64 j = n; j >= 0; j--){
                if((i^j) == n){
                    if(i+j>maxn){
                        maxa = j;
                        maxb = i;
                        maxn = i + j;
                    }
                }
            }
        }
        cout << maxa << ' ' << maxb << ' ';
        for (i64 i = 0; i < k - 2; i++)
            cout << n << ' ';
        cout << '\n';
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