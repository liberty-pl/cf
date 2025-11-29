#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k,times = 0;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];    
        }
        map<int,int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(v[i]) == mp.end())
            {
                mp[v[i]] = 1;
            }
            else
            {
                mp[v[i]]++;
            }
        }
        while (true)
        {
            bool moved = false;
            for (auto it = mp.begin(); it != mp.end(); ++it)
            {
                if (it->second > k)
                {
                    mp[it->first + 1] += it->second - 1;
                    it->second = 1;
                    times++;
                    moved = true;
                    
                }
            }
            if (!moved) break;
        }
        cout << times << endl;
    }
    return 0;
}