#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100100;
const int LOGN = 20;

int memo[MAXN][LOGN];
int hgt[MAXN];
int vis[MAXN];
vector<int> adj[MAXN];

void init(int root){
	hgt[root] = 0;
	for(int i = 0; i < LOGN; i++) memo[root][i] = root;
}

void dfs(int v){
	vis[v] = 1;
	for(auto x : adj[v]){
		if(vis[x]) continue;

		hgt[x] = 1 + hgt[v];
		memo[x][0] = v;

		for(int i = 1; i < LOGN;i++){
			memo[x][i] = memo[memo[x][i - 1]][i-1];
		}

		dfs(x);
	}
}


int lca (int a,int b){
	if(hgt[a] < hgt[b])
		swap(a,b);

	for(int i = LOGN - 1;i>= 0;i--)
		if(hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];	

	if (a==b) return a;

	for(int i = LOGN;i>=0;i--){
		if(memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	}

	return (memo[a][0]);
}

int main(){

}
