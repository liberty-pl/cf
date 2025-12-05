#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, result[10010];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n, value = 0;
        cin >> n;
        vector<long long> round(n);
        for (int j = 0; j < n; j++)
        {
            cin >> round[j];
        }
        for (int j = 0; j < n - 1; j++)
        {
            auto min = min_element(round.begin(), round.end());
            long long min_index = min - round.begin();
            if (min_index == n - j - 1)
            {
                if (round[0] > round[n - j - 2])
                {
                    value += round[n - j - 2];
                    round.erase(round.begin() + min_index);
                }
                else
                {
                    value += round[0];
                    round.erase(round.begin() + min_index);
                }
            }
            else if (min_index == 0)
            {
                if (round[1] > round[n - j - 1])
                {
                    value += round[n - j - 1];
                    round.erase(round.begin() + min_index);
                }
                else
                {
                    value += round[1];
                    round.erase(round.begin() + min_index);
                }
            }
            else
            {
                if (round[min_index + 1] > round[min_index - 1])
                {
                    value += round[min_index - 1];
                    round.erase(round.begin() + min_index);
                }
                else
                {
                    value += round[min_index + 1];
                    round.erase(round.begin() + min_index);
                }
            }
        }
        result[i] = value;
    }
    for (int i = 0; i < t; i++)
    {
        cout << result[i] << endl;
    }
}