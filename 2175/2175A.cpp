#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    using namespace std;
    int n;
    cin >> n;
    map<int, int> color;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        color[temp]++;
    }
    vector<int> v;
    for (pair<int,int> x:color)
    {
        v.push_back(x.first);
    }
    auto it = lower_bound(v.begin(), v.end(), color.size());
    cout << *it << '\n';
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