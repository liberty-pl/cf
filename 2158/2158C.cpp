#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    using namespace std;
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    vector<i64> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max1 = -2e9;
    for (int i = 0; i < n; i++)
    {
        i64 temp;
        cin >> temp;
        b[i] = abs(temp);
    }
    
    if (k%2){
        auto it = max_element(b.begin(), b.end());
        int b_max = *it;
        
        if(it != b.end()){
            a[it-b.begin()] += b_max;
        } else {
            a[0] += b[0];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            if (sum > max1){
                max1 = sum;
            }
        }
        
    }
    cout << max1 << '\n';
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