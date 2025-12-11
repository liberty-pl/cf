#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, temp = 0, max_temp = 0, temp1 = 0;
    string a;
    bool first = true;   
    cin >> n >> a;
    for(char x:a){
        if (x == '0'){
            if(first){
                temp++;
            }
            temp1++;
            max_temp = max(temp1, max_temp);
        } else {
            temp1 = 0;
            first = false;
        }
    }
    cout << max(max_temp,temp1+temp) << '\n';
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