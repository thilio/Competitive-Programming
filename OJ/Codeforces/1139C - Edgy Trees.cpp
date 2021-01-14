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
int n,m;
vi adj[100100];
ll k;
ll ans = 1;

int vis[100100];

ll dfs(int v){
	vis[v] = 1;

	ll resp = 1;

	//dbg(v);
	//dbg(adj[v].size());
	for(auto x : adj[v]){
		if(vis[x] == 0){
			resp += dfs(x);
		}
	}

	//dbg(resp);

	return resp;
}

int main(){

	fastio;

	cin >> n >> k;
	m = n-1;
	fr(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		if(c == 1) continue;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	frr(i,k){
		ans *= n;
		ans %= MOD;
	}

	frr(i,n){
		if(vis[i] == 0){
			ll x = dfs(i);
			ll aux = 1;
			//dbg(x);
			frr(i,k){
				aux *= x;
				aux %= MOD;
			}

			

			

			ans += MOD;
			
			ans -= aux;
			
			ans%= MOD;
			
		}
	}

	cout << ans << endl;



}
