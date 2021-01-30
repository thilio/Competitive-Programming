#include<bits/stdc++.h>
using namespace std;
vector<int> V[1123];
int f[1123];
void DFS (int i){
	int k;
	f[i]=1;
	for (k=0;k<V[i].size();k++){
		if (f[V[i][k]]==0)
			DFS (V[i][k]);
	}
}
int main(){
	pair <int, int> A[1123],dist,num;
	int pk,n,i,d,j,x,y,t;
	scanf("%d",&n);
	while (n!=0){
		for (i=1;i<=n;i++){
			scanf ("%d",&A[i].first);
			scanf ("%d",&A[i].second);
			V[i].clear();
			f[i]=0;
		}
		x=A[1].first;
		y=A[1].second;
		sort (A+1,A+n+1);
		pk=1;
		if (n>3){
			for (i=1;i<=n;i++){
				dist.first=dist.second=4000;
				num.first=num.second=0;
				for (j=1;j<=n;j++){
					if (j==i) continue;
					d=(A[j].first-A[i].first)*(A[j].first-A[i].first) + (A[j].second-A[i].second)*(A[j].second-A[i].second);
					if(d<dist.first){
						dist.second=dist.first;
						dist.first=d;
						num.second=num.first;
						num.first=j;
					}
					else if (d<dist.second){
						dist.second=d;
						num.second=j;
					}
				}
				V[i].push_back(num.first);
				V[i].push_back(num.second);
			}
			for(i=1;i<=n;i++){
				if (A[i].first==x && A[i].second==y)
					t=i;
			}
			DFS(t);
			for (i=1;i<=n;i++){
				pk=pk*f[i];
			}
		}
		if (pk==1)
			printf ("All stations are reachable.\n");
		else
			printf("There are stations that are unreachable.\n");
		scanf("%d",&n);
	} 
	return (0);
}