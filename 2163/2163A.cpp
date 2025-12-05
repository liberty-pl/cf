#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t, instance[110][110], ifOK[110];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m;
        cin >> m;
        ifOK[i] = 1;
        for (int j = 0; j < m; j++)
        {
            cin >> instance[i][j];
        }
        sort(instance[i], instance[i] + m);
        for (int k = 1; k <= m - 2; k += 2)
        {
            if (instance[i][k] != instance[i][k + 1])
            {
                ifOK[i] = 0;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (ifOK[i] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}