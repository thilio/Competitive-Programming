#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

int n;
ll sz[200200];
ll h[200200];
ll ans[200200];
vi adj[200200];

void dfs_pre(int v, int p){
	sz[v] = 1;
	if(p == -1) h[v] = 0;
	else h[v] = h[p] + 1; 

	for(auto x: adj[v]){
		if(x != p){
			dfs_pre(x, v);sz[v] += sz[x];
		}
	}
}

void dfs(int v, int p){
	for(auto x: adj[v]){
		if(x != p){
			ans[x] = ans[v] - sz[x] + (n - sz[x]);
			dfs(x, v);	
		}
	}
}

int main(){

	fastio;

	cin >> n;

	fr(i, n - 1){
		int u, v; cin >> u >> v;
		adj[u].pb(v);adj[v].pb(u);
	}

	dfs_pre(1, -1);

	frr(i, n) ans[1] += h[i];

	dfs(1, - 1);

	frr(i, n){
		cout << ans[i] << endl;
	}




}
