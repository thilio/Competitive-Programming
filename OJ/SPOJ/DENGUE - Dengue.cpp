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
	int c,ct,n,i,a,b,max=0,maxt=1000,maxtj,j,ctg=1;
	scanf("%d",&n);
	while(n!=0){
		maxt=1000;
		for (i=1;i<=n;i++){
			f[i]=-1;
		}
		for (i=0;i<(n-1);i++){
			scanf("%d",&a);
			scanf("%d",&b);
			V[a].push_back(b);
			V[b].push_back(a);
		}
		for (i=1;i<=n;i++){
			DFS (i,0);
			max=0;
			for (ct=1;ct<=n;ct++){
				if (f[ct]>max){
					max=f[ct];
				}
			}
			if (max<maxt){
				maxt=max;
				maxtj=i;
			}
			for (j=1;j<=n;j++){
				f[j]=-1;
			}
		}
		for (i=1;i<=n;i++){
			V[i].clear();
		}
		printf ("Teste %d\n",ctg);
		ctg++;
		printf("%d\n\n",maxtj);
		scanf ("%d",&n);
	}
	return (0);
}