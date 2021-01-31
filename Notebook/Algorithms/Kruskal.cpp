#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100100;
const int MAXM = 100100;

int n,m;
int id[MAXN],sz[MAXN];
bool mst[MAXM];
vector<pair<int,pair<int,int>>> edges;

void init(){
	for(int i = 1; i <= n; i++){
		id[i] = i;
		sz[i] = 1;
	}
}

int find (int p){
	if(id[p] == p) return p;
	return (id[p] = find(id[p]));
}

void merge (int p, int q){
	p = find(p);
	q = find(q);
	if(p == q) return;
	if(sz[p] > sz[q]) swap(p,q);
	id[p] = q;
	sz[q] += sz[p];
}

void kruskal(){
	init();
	sort(edges.begin(), edges.end());
	for(int i = 0; i < m; i++){
		pair<int,int> e = edges[i].second;
		if(find(e.first) == find(e.second)) continue;
		merge(e.first,e.second);
		mst[i] = true;
	}
}

int main(){

}
