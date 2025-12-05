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
    char s[200];
    cin >> s;
    char b[200];
    memcpy(b, s, sizeof(s));
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1'){
            for (int j = i; j <= i+k; j++)
            {
                b[j] = '1';
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '0'){
            sum++;
        }
    }
    cout << sum << endl;
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