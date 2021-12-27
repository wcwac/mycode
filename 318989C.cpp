#include<bits/stdc++.h>
using namespace std;
map<int,int> q;
int tt(string s){
    int now=0;
    for (auto i:s) now=now*10+i-'0';
    return now;
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;++i){
        string x;
        cin>>x;
        if (x.length()<=7)
        ++q[tt(x)];
    }
    int now=0;
    while (q[now]) ++now;
    cout<<now<<endl;
}