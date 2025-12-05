#include <bits/stdc++.h>
using namespace std;
int yihuo(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        a[i + 1] = a[i] ^ a[i + 1];
    }
    return a[a.size() - 1];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v2[i];
        }
        string winner;
        if (yihuo(v1) == yihuo(v2)) {
            winner = "Tie";
        } else {
            for (int i = 0; i < n; i++)
            {
                if (v1[i] != v2[i])
                {
                    if (i % 2 == 1)
                        winner = "Mai";
                    else
                        winner = "Ajisai";
                }
            }
            
        }
        cout << winner << endl;
            
    }
    return 0;
}