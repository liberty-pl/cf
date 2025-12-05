#include <iostream>
#include <string>
using namespace std;
int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        bool flag = true,flag1 = false;
        for (long long j = 0; j <= t.size()-1; j++)
        {
            if (t[j] == '*' && t[j+1]== '<'){
                cout << "-1" << endl;
                flag = false;
                break;
            }
            if (t[j] == '>' && t[j + 1] == '*')
            {
                cout << "-1" << endl;
                flag = false;
                break;
            }
            if (t[j] == '*' && t[j + 1] == '*')
            {
                cout << "-1" << endl;
                flag = false;
                break;
            }
            if (t[j] == '>' && t[j+1] == '<'){
                cout << "-1" << endl;
                flag = false;
                break;
            }
            if (t[j]=='*')
            {
                flag1 = true;
            }
        }
        if(flag){
            int sum1 = 0, sum2 = 0;
            for (long long k = 0; k < t.size(); k++)
            {
                if (t[k] == '>'){
                    sum1++;
                }
                if (t[k] == '<'){
                    sum2++;
                }
            }
            if(flag1){
                sum1++;
                sum2++;
            }
            if (sum1 >= sum2)  
            {
                cout << sum1 << endl;
            }
            else{
                cout << sum2 << endl;
            }          
        }
    }
    return 0;
}