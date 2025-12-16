#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve()
{
    i64 n;
    cin >> n;
    vector<i64> a(n), odd, even;
    for (i64 i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i64 x : a)
    {
        if (x % 2)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
        }
    }
    
    if (odd.size() == 0) {
        for (int i = 0; i < n; i++)
        {
            cout << "0 ";
        }
        cout << '\n';
        return;
    }
    auto it = max_element(odd.begin(), odd.end());
    int max_odd = *it;
    if(even.size() == 0){
        for (int i = 0; i < n; i++)
        {
            if (i%2 == 0){
                cout << max_odd << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
        return;
    }
    vector<i64> ans(n, odd.back());
    sort(even.begin(),even.end(),greater<>());
    ans[0] = max_odd;
    for (i64 i = 1; i < even.size()+1; i++)
    {
        ans[i] = ans[i - 1] + even[i-1];
    }
    for (i64 i = even.size() + 1; i < n; i++)
    {
        if ((i - even.size()) % 2) {
            ans[i] = ans[i - 1] - even.back();
        } else {
            ans[i] = ans[i - 1] + even.back();
        }
    }
    if (odd.size()%2 == 0){
        ans[n - 1] = 0;
    }
    for (i64 i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}