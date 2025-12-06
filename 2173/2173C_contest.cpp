#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    using namespace std;
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    vector<i64> b(n);
    for (i64 i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool flag = true,flag_al = true;
    vector<i64> mm;
    for (int j = 0; j < n; j++){
        for (int i = 1; i <= k / a[j]; i++)
        {
            auto it = find(a.begin(), a.end(), i * a[j]);
            if (it == a.end()){
                flag = false;
                if (j == 0){
                    flag_al = false;
                }
                break;
            }
        }
        if (flag) {
            mm.push_back(a[j]);
        }
        if (!flag_al){
            break;
        }
    }
    bool flag_2 = true;
    for (int i = 0; i < n; i++)
    {
        bool flag_1 = true;
        for (int j = 0; j < mm.size(); j++)
        {
            if(a[i]%mm[j] == 0) {
                flag_1 = false;
                b.push_back(mm[j]);
                break;
            } 
        }
        if (flag_1) {
            flag_2 = false;
            break;
        }
    }
    sort(b.begin(),b.end());
    vector<i64> c;
    c.push_back(b[0]);
    for (int i = 0; i < n; i++)
    {
        if(b[i]!=b[i+1]){
            c.push_back(b[i + 1]);
        }
    }
    cout << c.size() << '\n';
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << ' ';
    }
    cout << '\n';
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