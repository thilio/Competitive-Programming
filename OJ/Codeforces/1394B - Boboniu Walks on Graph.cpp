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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k;
ll xr[200200];
ll complete;
vector<pii> adj[200200];

ll c[11][11];

ll ran(){
	return uniform_int_distribution<ll>(0, (1ll << 60) - 1)(rng);
}

int rec(int p, ll xx){
	if(p == 0 && xx == complete) return 1;
	if(p == 0 && xx != complete) return 0;

	ll ans = 0;
	frr(i, p){
		ans += rec(p - 1, xx^c[p][i]);
	}
	return ans;
}

int main(){

	fastio;
	cin >> n >> m >> k;
	frr(i, n){
		xr[i] = ran();
		complete ^= xr[i];
	}

	fr(i, m){
		int u, v, w;
		cin >> u >> v >> w;
		//adj[v].pb({w, u});
		adj[u].pb({w, v});
	}

	frr(i, n) sort(all(adj[i]));

	frr(i, n){
		fr(j, adj[i].size()){
			c[adj[i].size()][j + 1] ^= xr[adj[i][j].snd];
		}
	}

	cout << rec(k, 0) << endl;





}	
