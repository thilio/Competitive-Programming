#include<bits/stdc++.h>
using namespace std;
vector<int> V[1123456];
int f[1123456];
void DFS (int i){
	int k;
	f[i]=1;
	for (k=0;k<V[i].size();k++){
		if (f[V[i][k]]==0)
			DFS (V[i][k]);
	}
}
int main(){
	int n,m,i,a,b,pk=1;
	cin>>n;
	cin>>m;
	if (m!=(n-1))
		cout<<"NO\n";
	else{
		for (i=0;i<(n-1);i++){
		cin>>a;
		cin>>b;
		V[a].push_back(b);
		V[b].push_back(a);
		}
		DFS(1);
		for (i=1;i<(n+1);i++){
			pk=pk*f[i];
		}
		if (pk==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return (0);
}