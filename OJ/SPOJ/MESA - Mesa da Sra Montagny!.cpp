#include<bits/stdc++.h>
using namespace std;
vector<int> V[1123456];
int f[1123456];
void DFS (int i,int s){
	int k;
	f[i]=s;
	s*=-1;
	for (k=0;k<V[i].size();k++){
		if (f[V[i][k]]==0)
			DFS (V[i][k],s);
	}
}
int main(){
	int n,m,i,a,b,pk=1,ctg=1,k;
	while(scanf("%d",&n)==1){
		scanf("%d",&m);
		pk=1;
		for (i=1;i<(n+1);i++){
			f[i]=0;
			V[i].clear();
		}
		for (i=0;i<m;i++){
			scanf("%d",&a);
			scanf("%d",&b);
			V[a].push_back(b);
			V[b].push_back(a);
		}
		for (i=1;i<(n+1);i++){
			if (f[i]==0)
				DFS(i,1);
		}
		for (i=1;i<(n+1);i++){
			for (k=0;k<V[i].size();k++){
				if (f[i]*f[V[i][k]]>0)
					pk=0;
			}
		}
		printf ("Instancia %d\n",ctg);
		ctg++;
		if (pk==1)
			printf ("sim\n\n");
		else
			printf ("nao\n\n");
	}
	return (0);
}