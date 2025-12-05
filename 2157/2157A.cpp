#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        vector<int>v(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
        }
        for (int i = 0; i < n; i++){
            if (mp[v[i]]>v[i]) {
                sum += mp[v[i]] - v[i];
                mp[v[i]] = v[i];
            } else if(mp[v[i]]<v[i]){
                sum += mp[v[i]];
                mp[v[i]] = 0;
            }
        }
        cout<<sum<<endl;
        
    }
    return 0;
}