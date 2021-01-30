#include<bits/stdc++.h>
using namespace std;

int vis[112345],key[112345],open[112345];
vector <int> nodes[112345]; 

void BFS(int n){
	queue <int> fpi;
	fpi.push(1);

	while (!fpi.empty()){

		while (!fpi.empty()){
			int v = fpi.front();
			fpi.pop();
			vis[v]=1;
			if (v == n) return;
			open[key[v]]=0;
			if (vis[key[v]]==1)
				fpi.push(key[v]);
			
			for (int i=0;i<nodes[v].size();i++){
				int filho = nodes[v][i];
				if (vis[filho]==1) continue;
				vis[filho]=1;
				if(open[filho]==0)
					fpi.push(filho);
			}

		}

	}
}

void run (int n,int k,int m){
	int i,a,b;
	//cout << n <<endl;
	for (i=1;i<=n;i++){
		vis[i]=0;
		key[i]=0;
		open[i]=0;
		nodes[i].clear();
	}
	for (i=0;i<k;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		key[a]=b;
		open[b]=1;
	}
	for (i=0;i<m;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	BFS(n);
	if(vis[n])
		printf("Y\n");
	else
		printf("N\n");
	

}

int main(){
	int a,b,c;
	//cout << "a" <<endl;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);

	while (a!=-1){
		run (a,b,c);
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);

	}
	return (0);
}