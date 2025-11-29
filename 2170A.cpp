#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 2){
            cout << 9 << endl;
            continue;
        }
        int t1 = 3 * n * n - 1 - n;
        int t2 = 4 * n * n - 4 - n;
        int t3 = 5 * n * n - 5 * n - 5;
        vector<int> v{t1, t2, t3};
        auto it = max_element(v.begin(), v.end());
        cout << *it << endl;
    }
    
    return 0;
}