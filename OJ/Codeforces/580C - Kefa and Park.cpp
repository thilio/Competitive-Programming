#include<bits/stdc++.h>
using namespace std;
vector<int> V[112345];
int f[112345],cat[112345],m;
void DFS (int i,int s){
	int k,pk=1;
	if (cat[i]==1){
		s++;
		if (s>m)
			pk=0;
	}
	if (pk==1){
		if (cat[i]==0)
			s=0;
		f[i]=s;
		for (k=0;k<V[i].size();k++){
			if (f[V[i][k]]==-1)
				DFS (V[i][k],s);
		}
	}
	
}
int main(){
	int n,a,b,i,tot=0;
	scanf ("%d",&n);
	scanf ("%d",&m);
	for(i=1;i<=n;i++){
		scanf ("%d",&cat[i]);
		f[i]=-1;
	}
	for (i=0;i<(n-1);i++){
		scanf("%d",&a);
		scanf("%d",&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	DFS(1,0);
	for (i=2;i<=n;i++){
		if (V[i].size()==1 && f[i]>-1)
			tot++;
	}
	printf ("%d\n",tot);
	return (0);
}