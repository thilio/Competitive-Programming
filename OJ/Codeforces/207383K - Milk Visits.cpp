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

int memo[100100][20];
int hgt[100100];
int vis[100100];
// LCA
vi adj[100100];
int type[100100];
// GRAFO
vi ponta[100100];
vi anc[100100];
int freq[100100];

pair<pii,int> query[100100];
pair<pii,int> ans[100100];

//ALGORITMO
int n;
int q;

void dfs_lca(int v){
	vis[v] = 1;
	for(auto x : adj[v]){
		if(vis[x]) continue;

		hgt[x] = 1 + hgt[v];
		memo[x][0] = v;

		for(int i = 1; i< 20;i++){
			memo[x][i] = memo[memo[x][i - 1]][i-1];
		}

		dfs_lca(x);
	}
}


int lca (int a,int b){
	if(hgt[a] < hgt[b])
		swap(a,b);

	for(int i = 19;i>= 0;i--)
		if(hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];	

	if (a==b) return a;

	for(int i = 19;i>=0;i--){
		if(memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	}

	return (memo[a][0]);

}

void dfs(int v){
	vis[v] = 1;
	freq[type[v]]++;

	fr(i,ponta[v].size()){
		int ind = ponta[v][i];
		int qt = freq[query[ind].snd];

		if(ans[ind].fst.fst == -1) ans[ind].fst.fst = qt;
		else ans[ind].fst.snd = qt;
	}

	fr(i,anc[v].size()){
		int ind = anc[v][i];
		int qt = freq[query[ind].snd];

		ans[ind].snd = qt;
	}

	for(auto x:adj[v]){
		if(vis[x]) continue;

		dfs(x);
	}


	freq[type[v]]--;
}

int main(){

	fastio;
	hgt[1] = 0;
	fr(i,20)
		memo[1][i] = 1;

	cin >> n >> q;
	frr(i,n) cin >> type[i];

	fr(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs_lca(1);
	ms(vis,0);

	fr(i,q){
		ans[i].fst.fst = ans[i].fst.snd = -1;
	}

	fr(i,q){
		int a,b,t;
		cin >> a >> b >> t;
		ponta[a].pb(i);
		ponta[b].pb(i);
		anc[lca(a,b)].pb(i);

		query[i] = mp(mp(a,b),t);
	}

	dfs(1);

	fr(i,q){
		bool ok = false;
		if(max(ans[i].fst.fst,ans[i].fst.snd) > ans[i].snd) ok = true;
		if(type[lca(query[i].fst.fst,query[i].fst.snd)] == query[i].snd) ok =true;
		if(ok) cout << '1';
		else cout << '0';
	}
	gnl;




}
