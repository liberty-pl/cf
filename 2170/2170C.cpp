#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> q(n);
        vector<int> r(n);
        for (int j = 0; j < n; j++)
        {
            cin >> q[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> r[j];
        }
        ll k;
        cin >> k;
        ll sum = 0;
        sort(r.begin(), r.end());
        auto it = upper_bound(r.begin(), r.end(),k);
        cout << *it << ' ';
        map<int, int> mpq;
        map<int, int> mpr;
        for (int j = 0; j < n; j++)
        {
            sum += (k - *it) / q[j];
        }
        for (int j = 0; j < n; j++)
        {
            mpq[q[j]]++;
            mpr[r[j]]++;
        }
        sum += min(mpq.size(), mpr.size());
        cout << sum << endl;
    }
    
    return 0;
}