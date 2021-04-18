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
const int NMAX = 50005;
const int LMAX = 18;

int hgt[50005];
int vis[50005];
int memo[50005][19];
vii nodes[50005];
int dist [50005];

void dfs(int v){
	vis[v] = 1;
	for(auto x: nodes[v]){
		int k = x.fst;
		int p = x.snd;
		 		
		if (vis[k]) continue;
		
		hgt[k] = hgt[v] + 1;
		dist[k] = dist[v] + p;
		memo[k][0] = v;

		for(int i = 1;i<= LMAX;i++){
			memo[k][i] = memo[memo[k][i-1]][i-1];
		}

		dfs(k);
	}
}

int lca(int u, int v){
	if (hgt[u] < hgt[v]) swap(u,v);

	for(int i = LMAX;i>=0;i--){
		if(hgt[memo[u][i]] >= hgt[v])
			u = memo[u][i];
	}
	if(u==v) return u;

	for(int i = LMAX;i>= 0 ;i--){
		if(memo[u][i] != memo[v][i]){
			//dbg(i);
			u = memo[u][i];
			v = memo[v][i];
		}
	}
	

	return (memo[u][0]);
}



int main(){

	fastio;
	int n;
	cin >> n;

	int u,v,w;
	fr(i,n-1){
		cin >> u >> v >> w;
		nodes[u].pb(mp(v,w));
		nodes[v].pb(mp(u,w));
	}

	fr(i,LMAX + 1){
		memo[0][i] = 0;
	}



	int m;
	cin >> m;

	dfs(0);

	//fr(i,n) cout << memo[i][1] << endl;

	fr(i,m){
		cin >> u >> v;
		int x = lca(u,v);
		//dbg(x);
		cout << dist[v] + dist[u] - 2*dist[x]<< endl;
	}

}
