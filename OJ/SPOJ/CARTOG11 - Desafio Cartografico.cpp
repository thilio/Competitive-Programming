#include<bits/stdc++.h>
using namespace std;
vector<int> V[1123456];
int f[1123456],ordem[1123456];
void DFS(int v,int t){
	int k;
	f[v]=1;
	ordem[v]=t;
	t++;
	for (k=0;k<V[v].size();k++){
		if (f[V[v][k]]==0)
			DFS (V[v][k],t);
	}
}
int main(){
	int n,i,a,b,max=0,maxj=0,j;
	scanf("%d",&n);
	for (i=0;i<(n-1);i++){
		scanf("%d",&a);
		scanf("%d",&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	DFS (1,0);
	for (j=0;j<(n+1);j++){
		if (ordem[j]>max){
			maxj=j;
			max=ordem[j];
		}
		ordem[j]=0;
		f[j]=0;
	}
	DFS(maxj,0);
	max=0;
	for (j=0;j<(n+1);j++){
		if (ordem[j]>max)
			max=ordem[j];
	}
	printf ("%d\n",max);
	return (0);
}