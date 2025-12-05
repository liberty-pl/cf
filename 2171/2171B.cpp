#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> &v)
{
    int s = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        s += v[i + 1] - v[i];
    }
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (v[0] != -1 && v[n - 1] != -1)
            cout << abs(v[n - 1] - v[0]) << endl;
        else{
            cout << 0 << endl;
            if (v[0] == -1 && v[n - 1] == -1)
            {
                v[0] = 0;
                v[n - 1] = 0;
            }
            else if (v[0] == -1)
            {
                v[0] = v[n - 1];
            }
            else
            {
                v[n - 1] = v[0];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == -1)
            {
                v[i] = 0;
            }

        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}