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
ll n;
ll m;
vector<ll> edges;
vector<ll> fact;
vi adj[100100];

void clean(){
	frr(i,n) adj[i].clear();
	edges.clear();
	fact.clear();

}

ll dfs(int v, int pai){

	ll ans = 1;

	for(auto x : adj[v]){
		if(x == pai) continue;
		ll k = dfs(x,v);
		edges.pb(k*(n - k));
		ans += k;
	}

	return ans;
}


int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		clean();
		fr(i,n-1){
			int u,v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		cin >> m;
		fr(i,m){
			ll x;
			cin >> x;
			fact.pb(x);
		}

		while(fact.size() < n - 1) fact.pb(1);
		sort(all(fact));
		while(fact.size() > n - 1){
			ll y = fact[fact.size() - 1];
			fact.pop_back();
			fact[fact.size() - 1] *= y;
			fact[fact.size() - 1] %= MOD;
		}
		ll x = dfs(1, -1);
		sort(all(edges));

		fr(i,n-1) edges[i] %= MOD;

		ll resp = 0;
		fr(i,n-1){
			resp += edges[i]*fact[i];
			resp %=MOD;
		}

		cout << resp << endl;
	}

}
