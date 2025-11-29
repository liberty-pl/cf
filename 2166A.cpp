#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,result[30];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        char cha[110];
        cin >> cha;
        char last_1 = cha[n - 1];
        int sum = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (cha[j] != last_1){
                sum++;
            }
        }
        result[i]=sum;
    }
    for (int i = 0; i < t; i++)
    {
        cout << result[i] << endl;
    }
    
    return 0;
}