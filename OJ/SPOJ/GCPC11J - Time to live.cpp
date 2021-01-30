#include<bits/stdc++.h>
using namespace std;
vector<int> V[1123456];
int f[1123456];
void DFS(int v,int t){
	int k;
	f[v]=t;
	t++;
	for (k=0;k<V[v].size();k++){
		if (f[V[v][k]]==-1)
			DFS (V[v][k],t);
	}
}
int main(){
	int c,ct,n,i,a,b,max=0,maxj=0,j;
	scanf("%d",&c);
	for (ct=0;ct<c;ct++){
		scanf ("%d",&n);
		for (i=0;i<n;i++){
			f[i]=-1;
		}
		for (i=0;i<n;i++){
			V[i].clear();
		}
		for (i=0;i<(n-1);i++){
			scanf("%d",&a);
			scanf("%d",&b);
			V[a].push_back(b);
			V[b].push_back(a);
		}
		max=0;maxj=0;
		DFS (0,0);
		for (j=0;j<n;j++){
			if (f[j]>max){
				maxj=j;
				max=f[j];
			}
			f[j]=-1;
		}
		DFS(maxj,0);
		max=0;
		for (j=0;j<n;j++){
			if (f[j]>max)
				max=f[j];
		}
		max=(max + max%2)/2;
		printf ("%d\n",max);
	}
	return (0);
}