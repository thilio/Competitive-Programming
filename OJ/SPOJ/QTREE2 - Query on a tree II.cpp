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
const int NMAX = 11233;
const int LMAX = 14;

vii nodes[11234];
int hgt[11234];
int vis[11234];
int dist[11234];
int memo[11234][15];

void dfs(int v){
	vis[v] = 1;
	for(auto x: nodes[v]){
		int k = x.fst;
		int p = x.snd;
		if(vis[k]) continue;
		dist[k] = dist[v] + p;
		hgt[k] = hgt[v] + 1;
		memo[k][0] = v;

		for(int i = 1;i <= LMAX;i++){
			memo[k][i] = memo[memo[k][i-1]][i-1];
		}

		dfs(k);
	}
}

int lca(int a,int b){
	if(hgt[a] < hgt[b])
		swap(a,b);

	for(int i = LMAX;i>= 0 ; i--){
		if(hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];
	}

	if(a==b) return a;

	for(int i = LMAX;i >= 0; i--){
		if(memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	}

	return (memo[a][0]);
}

void solve(){
	ms(hgt,0);
	ms(vis,0);
	ms(dist,0);

	fr(i,LMAX + 1){
		memo[1][i] = 1;
	}

	fr(i,NMAX)
		nodes[i].clear();

	int n;
	cin >> n;

	int u,v,w;

	fr(i,n-1){
		cin >> u >> v >> w;
		nodes[u].pb({v,w});
		nodes[v].pb({u,w});
	}

	dfs(1);

	string s;

	while (1){
		cin >> s;
		
		if(s == "DONE") break;
		if(s == "DIST"){ 
			cin >> u >> v;
			//dbg(lca(u,v));
			cout << dist[u] + dist[v] - 2*dist[lca(u,v)]<<endl;
		}
		else{

			cin >> u >> v >> w;
			int no = lca(u,v);
			if(w > hgt[u] - hgt[no] + 1){
				w = hgt[u] + hgt[v] + 2 - w - 2*hgt[no];
				u = v;
			}
		
			int x = hgt[u] - w + 1;
			for(int i = LMAX;i>=0;i--){
				if(hgt[memo[u][i]] >= x)
					u = memo[u][i];
			}

			cout << u << endl;
			
		
		}
	}

}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
		gnl;
	}

}
