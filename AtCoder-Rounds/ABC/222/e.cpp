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

int n, m, k;
int A[1010];
vi adj[1010];

int w[1010];
int h[1010];
int pai[1010];

int total;
int goal;

ll memo[1010][100100];

void dfs(int v){
	for(auto x: adj[v]){
		if(x != pai[v]){
			pai[x] = v;
			h[x] = h[v] + 1;
			dfs(x);
		}
	}
}

void count(int u, int v){
	if(h[u] < h[v]) swap(u, v);

	while(h[u] != h[v]){
		w[u]++;
		u = pai[u];
	}

	while(u != v){
		w[u]++;
		w[v]++;
		u = pai[u];
		v = pai[v];
	}
}

ll dp(int ind, int red){
	if(red > goal) return 0;
	if(ind == n + 1){
		if(red == goal) return 1;
		else return 0;
	}
	ll & pdm = memo[ind][red];
	if(pdm != -1) return pdm;

	pdm = (dp(ind + 1, red) + dp(ind + 1, red + w[ind]))%MOD;
	return pdm;
}

int main(){

	fastio;

	cin >> n >> m >> k;

	frr(i, m) cin >> A[i];

	fr(i, n - 1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}


	dfs(1);

	for(int i = 1; i < m; i++){
		count(A[i], A[i + 1]);
	}

	for(int i = 2; i <= n; i++) total += w[i];

	if(total + k < 0 || total - k < 0 || (total + k)%2 != 0){
		cout << 0 << endl;
		return 0;
	}

	goal = (total + k)/2;

	ms(memo, -1);

	cout << dp(2, 0) << endl;





}
