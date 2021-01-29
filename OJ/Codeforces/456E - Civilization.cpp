#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int id[300300],sz[300300],path[300300];
pii vis[300300];
vi adj[300300];

pii dfs1(int v){
	vis[v].fst = 1;
	pii ans = mp(0,v);
	for(auto x : adj[v]){
		if(vis[x].fst == 1) continue;
		pii aux = dfs1(x);
		aux.fst++;
		if(ans < aux) ans = aux;
	}

	return ans;
}

pii dfs2(int v){
	vis[v].snd = 1;
	pii ans = mp(0,v);
	for(auto x : adj[v]){
		if(vis[x].snd == 1) continue;
		pii aux = dfs2(x);
		aux.fst++;
		if(ans < aux) ans = aux;
	}

	return ans;
}



void find_path(int v){
	pii aux = dfs1(v);
	pii help = dfs2(aux.snd);
	int maior = help.fst;
	path[v] = maior+1;
}


int find(int p){
	if(id[p] == p) return p;
	return(id[p] = find(id[p]));
}

void merge(int p,int q){
	p = find(p);
	q = find(q);
	if(p == q) return;
	if(sz[p] > sz[q]) swap(p,q);
	id[p] = q;
	sz[q] += sz[p];
	path[q] = max(path[q],max(path[p],path[q]/2 + path[p]/2 + 2)); 
}

int main(){

	fastio;
	int n,m,q;
	cin >> n;
	frr(i,n){
		id[i] = i;
		sz[i] = 1;
	}
	cin >> m;
	cin >> q;

	fr(i,m){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
		merge(a,b);
	}

	map<int,bool> ma;

	frr(i,n){
		int a = find(i);
		if(ma[a] == false){
			find_path(a);
			ma[a] = true;
		}
	}

	fr(i,q){
		int op;
		cin >> op;
		if(op == 1){
			int p;
			cin >> p;
			p = find(p);
			cout << path[p] - 1 << endl;

		}
		else{
			int a,b;
			cin >> a >> b;
			merge(a,b);
		}
	}




}
