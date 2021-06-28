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

ll dp[300][300];
int n;
vi adj[300];
ll sz[300];
ll h[300];

bool path[300];

ll ans;

ll fast(ll b, ll e){
	if(e == 0) return 1;
	ll ans = fast(b, e/2);
	ans = (ans*ans)%MOD;
	if(e&1) ans = (ans*b)%MOD;
	return ans;
}

ll invmod(ll x){
	return fast(x, MOD - 2);
}

void pd(){
	ll meio = invmod(2);

	for(int i = 0; i <= 200; i++){
		for(int j = 0; j <= 200; j++){
			if(i == 0){
				dp[i][j] = 1;
				continue;
			}
			if(j == 0){
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = meio*dp[i][j - 1] + meio*dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	}
}

void dfs(int v, int p, int esp){
	if(p != -1) h[v] = h[p] + 1;

	path[v] = false;
	if(v == esp) path[v] = true;
	
	sz[v] = 1;

	for(auto x: adj[v]){
		if(x != p){
			dfs(x, v, esp);
			sz[v] += sz[x];
			if(path[x]) path[v] = true;
		}
	}
}

ll solve(int u, int v){
	h[u] = 0;
	dfs(u, -1, v);

	ll inv = invmod(n);

	ll t = 0;
	ll resp = 0;

	frr(i, n){
		if(path[i]){
			t = sz[i];
			for(auto x: adj[i]){
				if(h[x] > h[i] && path[x]) t -= sz[x];
			}
				
			ll a = (t*inv)%MOD;
			a = (a*dp[h[i]][h[v] - h[i]])%MOD;
			resp = (resp + a)%MOD;
		}
	}

	return resp;

}

int main(){

	fastio;
	pd();

	cin >> n;
	frr(i, n - 1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int v = 1; v <= n; v++){
		for(int u = v + 1; u <= n; u++){
			ans = (ans +  solve(u, v))%MOD;

			//dbg(solve(u, v));
		}
	}

	cout << ans << endl;

}
