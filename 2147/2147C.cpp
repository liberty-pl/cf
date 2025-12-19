#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    string a;
    i64 b, sum = 0;
    cin >> b;
    cin >> a;
    size_t pos = a.find("11011");
    for (int i = 1; i < b-1; i++)
    {
        if(a[i] == '0'){
            sum++;
        }
    }
    
    if(b<=3){
        if(a == "101"){
            cout << "NO\n";
        } else{
            cout << "YES\n";
        }
        return;
    } else{
        string slice1 = a.substr(0, 4);
        string slice2 = a.substr(b - 4, 4);
        if(pos == string::npos && slice1 != "1011" && slice2 != "1101"){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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