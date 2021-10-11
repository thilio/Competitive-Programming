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
const int MOD = 998244353;

int n;
vi adj[200200];
int pai[200200];
int dist[200200];

int s, t;

vector<ll> M;

void dfs(int v, int p = -1){
	pai[v] = p;
	for(auto x: adj[v]){
		if(x != p){
			dist[x] = dist[v] + 1;
			dfs(x, v);
		}
	}
}

int find_diameter(){
	dist[1] = 0;
	dfs(1);

	s = 1;
	frr(i, n){
		if(dist[i] > dist[s]) s = i;
	}

	dist[s] = 0;
	dfs(s);

	t = s;
	frr(i, n){
		if(dist[i] > dist[t]) t = i; 
	}

	return dist[t];
}

int dfs_c(int v, int p, int val){
	int ans = 0;
	for(auto x: adj[v]){
		if(x != p){
			dist[x] = dist[v] + 1;
			ans += dfs_c(x, v, val);
		}
	}
	if(dist[v] == val) ans++;
	return ans;
}

int main(){

	fastio;

	cin >> n;


	fr(i, n - 1){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int D = find_diameter();

	int u = t;

	frr(i, D/2) u = pai[u];

	if(D%2 == 0){
		for(auto x: adj[u]){
			dist[x] = 0;
			M.pb(dfs_c(x, u, (D/2) - 1));
		}
	}
	else{
		dist[u] = 0;
		dist[pai[u]] = 0;
		M.pb(dfs_c(u, pai[u], D/2));
		M.pb(dfs_c(pai[u], u, D/2));
	}

	ll ans = 1;

	for(auto x: M){
		ans = (ans*(x + 1))%MOD;
	}

	for(auto x: M) ans = (ans - x + MOD)%MOD;
	ans = (ans - 1 + MOD)%MOD;

	cout << ans << endl;

}
