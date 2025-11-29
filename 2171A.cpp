#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,result[110];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        if (n % 2 == 0){
            result[i] = n / 4 + 1;
        }
        else
            result[i] = 0;
    }
    for (int i = 0; i < t; i++)
    {
        cout << result[i] << endl;
    }
    
    return 0;
}