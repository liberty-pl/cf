#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, result[10010];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long a, b, n, times = 1;
        cin >> a >> b >> n;
        if (n*b <= a || a == b ){
            times = 1;
        } else {
            times = 2;
        }
        result[i] = times;
    }
    for (int i = 0; i < t; i++)
    {
        cout << result[i] << endl;
    }
    
    return 0;
}