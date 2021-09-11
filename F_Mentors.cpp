#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e4;
ll f[N];

int main()
{
    int r,n,m;
    cin>>r>>n>>m;
    f[n]=1;
    for (int i=n-1;i>=1;--i){
        for (int j=i+1;j<=n;++j){
            if (j!=r){
                f[i]=f[i]+f[j];
            }
        }
        f[i]%=m;
    }
    for (int i=1;i<=n;++i) cout<<f[i]<<endl;
    cout<<f[1]<<endl;


    return 0;
}
