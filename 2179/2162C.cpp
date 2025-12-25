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
    i64 tempxor = a ^ b, tempn = 0, tempa = a, tempb = b;
    vector<i64> ans;
    while(tempa != 1){
        tempa = tempa >> 1;
        tempb = tempb >> 1;
    }
    if(tempb>1){
        cout << -1 << '\n';
        return;
    }
    if(tempxor <= a){
        cout << 1 << '\n' << tempxor << '\n';
    } else {
        while(tempxor != 1){
            tempxor = tempxor >> 1;
            tempn++;
        }
        int ans1 = tempxor << tempn, ans2 = a ^ b ^ ans1;
        cout << 2 << '\n'
             << ans2 << ' ' << ans1 << '\n';
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