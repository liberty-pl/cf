#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), odd, even;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int x : a)
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
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<>());
    if (even.size() == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << odd.back() << ' ';
            }
        }
        cout << '\n';
        return;
    }
    if (odd.size() == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> ans(n, odd.back());
    for (int i = 0; i < even.size() + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ans[i] += even[j];
        }
    }
    for (int i = even.size() + 1; i < n; i++)
    {
        if ((i - even.size() - 1) % 2 == 0)
        {
            ans[i] = ans[even.size()] - even.back();
        }
        else
        {
            ans[i] = ans[even.size()];
        }
    }
    if (odd.size() % 2 == 0 && n%2 == 1)
    {
        for (int i = n-3; i >= 0; i-=2)
        {
            ans[i] = odd.back();
        }
        ans[n - 1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}