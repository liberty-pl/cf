#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    using namespace std;
    int n, sum = 0, odd = 0, even = 0;
    cin >> n;
    map<int,int> mp;
    for (int i = 0; i < 2*n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    int delta=0,delta1 = 0;
    for (auto&& pair : mp){
        if (pair.second%2 == 0){
            sum += 2;
            even += 1;
        } else {
            sum += 1;
            odd += 1;
        }
        
    }
    if (odd == 0 && (n - even)%2 != 0)
        cout << sum - 2<< '\n';
    else
        cout << sum << '\n';
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