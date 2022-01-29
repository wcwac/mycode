#include<bits/stdc++.h>
#define maxn 100010
#define ll long long
using namespace std;
int n,m,a[maxn],bk[maxn],rb[maxn],ans[maxn];
vector<int>b[maxn];
void dfs(int p){
	bk[p]=1;
	if(b[p].size())for(int i=0;i<b[p].size();i++){
		rb[b[p][i]]--;ans[b[p][i]]=max(ans[p]+1,ans[b[p][i]]);
		if(rb[b[p][i]]==0)dfs(b[p][i]);
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1])b[i-1].push_back(i),rb[i]++;
		if(a[i]<a[i-1])b[i].push_back(i-1),rb[i-1]++;
	}
	if(a[1]>a[n])b[n].push_back(1),rb[1]++;
	if(a[1]<a[n])b[1].push_back(n),rb[n]++;
	for(int i=1;i<=n;i++){
		if(bk[i]||rb[i])continue;
		if(a[i]!=0)ans[i]=1;
		else ans[i]=0;dfs(i);
	}
	for(int i=1;i<=n;i++)printf("%lld%c",(ll)ans[i]*(ll)m,i==n?'\n':' ');
    return 0;
}