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
typedef pair<ll, pii> edge;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

const int MAXN = 200100;
const int LOGN = 20;

int memo[MAXN][LOGN];
ll maxc[MAXN][LOGN];
int hgt[MAXN];
int vis[MAXN];
vii adj[MAXN];

int id[MAXN];
int sz[MAXN];

int n, m;
map<pii, ll> mst;

void dfs(int v){
	vis[v] = 1;
	for(auto y : adj[v]){
		int  x = y.fst;
		ll c = y.snd;
		if(vis[x]) continue;

		hgt[x] = 1 + hgt[v];
		memo[x][0] = v;
		maxc[x][0] = c;

		for(int i = 1; i < LOGN;i++){
			memo[x][i] = memo[memo[x][i - 1]][i-1];
			maxc[x][i] = max(maxc[x][i-1], maxc[memo[x][i - 1]][i-1]);
		}

		dfs(x);
	}
}


int lca(int a,int b){
	if(hgt[a] < hgt[b])
		swap(a,b);

	for(int i = LOGN - 1;i>= 0;i--){
		if(hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];	
	}

	if (a==b) return a;

	for(int i = LOGN - 1;i>=0;i--){
		if(memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	}

	return (memo[a][0]);

}

void init(int root){
	hgt[root] = 0;
	for(int i = 0; i < LOGN; i++) memo[root][i] = root;
	for(int i = 0; i < LOGN; i++) maxc[root][i] = 0;
}

int find(int i){
	if(i == id[i]) return i;
	return id[i] = find(id[i]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(sz[u] < sz[v]) swap(u, v);
	id[v] = u;
	sz[u] += sz[v];
}

ll kruskal(vector<edge> v){
	sort(all(v));
	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}

	ll c = 0;

	for(auto x: v){
		if(find(x.snd.fst) == find(x.snd.snd)) continue;
		merge(x.snd.snd, x.snd.fst);
		c += x.fst;
		mst[x.snd] = x.fst;
		mst[{x.snd.snd, x.snd.fst}] = x.fst;
	}

	return c;
}

int main(){
	fastio;

	cin >> n >> m;
	vector<edge> aux;

	fr(i, m){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		aux.pb(mp(c, mp(a,b)));
	}

	ll ans = kruskal(aux);

	for(auto x: mst){
		adj[x.fst.fst].pb({x.fst.snd, x.snd});
	}

	init(1);
	dfs(1);

	//frr(i, n) dbg(maxc[i][1]);	

	for(auto x: aux){
		//dbg(x.snd.fst);
		//dbg(x.snd.snd);
		if(mst[x.snd] != 0){
			cout << ans << endl;
			continue;
		}

		int w = lca(x.snd.fst, x.snd.snd);
		
		//dbg(w);

		ll mx = 0;
		int u, v;
		tie(u, v) = x.snd;

		for(int i = LOGN - 1; i>= 0; i--){
			if(hgt[memo[u][i]] >= hgt[w]){
				mx = max(mx, maxc[u][i]);
				u = memo[u][i];
			}
			if(hgt[memo[v][i]] >= hgt[w]){
				mx = max(mx, maxc[v][i]);
				v = memo[v][i];
			}
		}

		cout << ans - mx + x.fst << endl;
	}

}