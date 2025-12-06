#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    a.clear();
    std::map<i64, i64> u;
    u.clear();
    std::set<i64> v;
    v.clear();
    std::vector<i64> ans;
    ans.clear();
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        u[a[i]] = 1;
        v.insert(a[i]);
    }
    while(v.size()){
        int p = *v.begin();
        ans.push_back(p);
        v.erase(v.begin());
        for (int i = p; i <= k; i+=p)
        {
            if(!u[i]){
                std::cout << "-1\n";
                return;
            }
            auto it = v.find(i);
            if(it!=v.end()){
                v.erase(it);
            }
        }
    }
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
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