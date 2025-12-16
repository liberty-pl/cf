#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 NEG_INF = -9000000000000000000LL;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

i64 max_sum(vector<i64> v, int s, int e){
    
    i64 max_all = v[0] , temp = 0;
    for (i64 i = s; i <= e; i++)
    {
        temp += v[i];
        max_all = max(temp, max_all);
        if(temp < 0){
            temp = 0;
        }
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
    i64 mxall = -1000000000;
    if (!(k%2)){
        cout << max_sum(a,0,n-1) << '\n';
    } else {
        vector<i64> max_sum_after(n, NEG_INF), max_sum_before(n, NEG_INF);
        max_sum_before[0] = a[0];
        max_sum_after[n - 1] = a[n-1];
        for (int i = 1; i < n; i++)
        {
            max_sum_before[i] = max(a[i], a[i] + max_sum_before[i - 1]);
        }
        for (int i = n-2; i >= 0; i--)
        {
            max_sum_after[i] = max(a[i], a[i] + max_sum_after[i + 1]);
        }
        
        for (size_t i = 0; i < n; i++)
        {
            i64 temp = max_sum_after[i] + max_sum_before[i] - a[i] + b[i];
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