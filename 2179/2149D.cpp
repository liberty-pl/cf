#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 n, ans1 = 2e18, ans2 = 2e18, temp1 = 0, temp2 = 0;
    string x;
    cin >> n >> x;
    vector<int> a, b;
    for (int i = 0; i < x.size(); i++)
    {
        if(x[i] == 'a'){
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    for (int i = 0; i < a.size(); i++)
        a[i] = a[i] - i;
    for (int i = 0; i < b.size(); i++)
        b[i] = b[i] - i;
    temp1 = 0;
    for (int j = 0; j < a.size(); j++)
    {
        i64 t = (a.size() - 1) / 2;
        temp1 += abs(a[t] - a[j]) - abs(t - j);
    }
    
    temp2 = 0;
    for (int j = 0; j < b.size(); j++)
    {
        i64 t = (b.size() - 1) / 2;
        temp2 += abs(b[t] - b[j]) - abs(t - j);
    }
    
    cout << min(temp1, temp2) << '\n';
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