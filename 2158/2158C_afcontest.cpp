#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

i64 max_sum(vector<i64> v ,int s,int e){
    
    i64 max_all = , temp = 0;
    for (size_t i = s; i <= e; i++)
    {
        temp = temp + v[i];
        temp = max(temp, (i64)0);
        max_all = max(max_all, temp);
    }
    return max_all;
}

void solve() {
    int n, k;
    bool first = true;
    cin >> n >> k;
    vector<i64> a(n), b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    i64 mxall = 0;
    if (!(k%2)){
        cout << max_sum(a,0,n-1) << '\n';
    } else {
        for (size_t i = 0; i < n; i++)
        {
            i64 temp = max_sum(a, 0, i) + max_sum(a, i, n - 1) - a[i] + b[i];
            mxall = max(temp, mxall);
        }
        cout << mxall << '\n';
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