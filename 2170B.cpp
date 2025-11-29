#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        ll S = 0, zeros = 0;
        for (ll i = 0; i < n; ++i)
        {
            cin >> v[i];
            S += v[i];
            if (v[i] == 0){
                ++zeros;
            }
        }
        ll p = n - zeros;
        ll candidate = S - (n - 1);
        ll ans = min(p, candidate);
        cout << ans << '\n';
    }
    return 0;
}