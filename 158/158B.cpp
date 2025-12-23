#include <bits/stdc++.h>
int main()
{
    using namespace std;
    int n, ans = 0, temp;
    cin >> n;
    vector<int> v(5, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v[temp]++;
    }
    ans += v[4];
    temp = min(v[3], v[1]);
    ans += temp;
    v[1] -= temp;
    v[3] -= temp;
    temp = v[2] / 2;
    ans += temp;
    v[2] -= temp * 2;
    temp = min(v[2], v[1] / 2);
    ans += temp;
    v[1] -= temp * 2;
    v[2] -= temp;
    temp = min(v[2], v[1]);
    ans += temp;
    v[1] -= temp;
    v[2] -= temp;
    temp = v[1] / 4 + (bool)(v[1] % 4);
    ans += temp;
    ans += v[2] + v[3];
    cout << ans;
    return 0;
}