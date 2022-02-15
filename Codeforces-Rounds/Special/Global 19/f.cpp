#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
//#define endl '\n'
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

ll h[200200];
int root = 0;
vi adj[200200];

ll dp[200200];

ll dfs(int v, int p = -1){

	vector<ll> f;

	for(auto x: adj[v]){
		if(x != p){
			f.pb(dfs(x, v));
			dp[v] += dp[x];
		}
	}

	sort(all(f));
	reverse(all(f));

	if(f.size() == 0){
		dp[v] = h[v];
		return h[v];
	}
	else if(v == root){
		if(f.size() == 1){
			dp[v] += h[root] + h[root] - f[0];
		}
		else{
			dp[v] += 2*h[root] - f[0] - f[1];
		}
		return h[root];
	}
	else{
		if(h[v] > f[0]){
			dp[v] += h[v] - f[0];
			return h[v];
		}
		else
			return f[0];
	}
}

int main(){

	fastio;

	int n;

	cin >> n;

	frr(i, n){
		cin >> h[i];
		if(h[i] > h[root]) root = i; 
	}

	fr(i, n - 1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	//dbg(root);

	dfs(root);
	cout << dp[root] << endl;

}
