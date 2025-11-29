#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int marblen, alice, bob=0;
        cin >> marblen >> alice;
        vector<int> marble(marblen);

        for (int j = 0; j < marblen; j++)
        {
            cin >> marble[j];
        }
        auto it = lower_bound(marble.begin(), marble.end(), alice);
        if (marblen%2==0){
            if (alice <= marble[1]){
                bob = alice + 1;
            }
            else if (alice >= marble[marblen-1]){
                bob = alice - 1;
            }
            else if (*it <= (marble[marblen/2]+marble[marblen/2-1])/2){
                bob = alice + 1;
            }
            else if (*it > (marble[marblen / 2] + marble[marblen / 2 - 1])/2){
                bob = alice - 1;
            }
        } else if (marblen % 2 != 0){
            if (alice <= marble[1])
            {
                bob = alice + 1;
            }
            else if (alice >= marble[marblen - 1])
            {
                bob = alice - 1;
            }
            else if (*it <= marble[marblen/2]){
                bob = alice + 1;
            }
            else if (*it > marble[marblen / 2]){
                bob = alice - 1;
            }
        }
        cout << bob << endl;
    }
}