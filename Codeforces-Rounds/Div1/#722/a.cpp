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

int n;
ll memo[100100][2];
ll l[100100];
ll r[100100];
vi adj[100100];

void clear(){
	frr(i, n){
		memo[i][0] = memo[i][1] = -1;
		adj[i].clear();
	}
}

ll dfs(int u, int p, int k){
	if(p == 0){
		ll &pdm = memo[u][k];
		pdm = 0;

		ll tent0 = 0;
		for(auto x: adj[u]){
			if(x == p) continue;
			tent0 += dfs(x, u, 0);
		}

		ll tent1 = 0;
		for(auto x: adj[u]){
			if(x == p) continue;
			tent1 += dfs(x, u, 1);
		}

		pdm = max(tent0, tent1);
		return pdm;
	}

	ll &pdm = memo[u][k];
	if(pdm != -1) return pdm;

	ll tent0 = 0;
	if(k == 0){
		tent0 += abs(l[u] - l[p]);
	}
	else{
		tent0 += abs(l[u] - r[p]);
	}
	for(auto x: adj[u]){
		if(x == p) continue;
		tent0 += dfs(x, u, 0);
	}

	ll tent1 = 0;
	if(k == 0){
		tent1 += abs(r[u] - l[p]);
	}
	else{
		tent1 += abs(r[u] - r[p]);
	}
	for(auto x: adj[u]){
		if(x == p) continue;
		tent1 += dfs(x, u, 1);
	}

	pdm = max(tent0, tent1);
	return pdm;

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		clear();
		frr(i, n){
			cin >> l[i] >> r[i];
		}
		frr(i, n -1){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		cout << dfs(1, 0, 0) << endl;
	}

}
