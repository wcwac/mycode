#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        string str;
        int n,k;
        cin>>n>>k>>str;
        int flag=1;
        if (k*2>=str.length()){
            cout<<"NO\n";
            continue;
        }
        for (int i=0;i<k;++i){
            if (str[i]!=str[n-i-1]) {
                flag=0;
                // cout<<i<<"?"<<str.length()-1-i;
            }
        }
        if (flag) cout<<"YES\n";
        else cout<<"NO\n";
    }




    return 0;
}