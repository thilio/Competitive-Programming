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

vector<pair<pii, ll>> edges;
vector<pair<int, ll> > query[660];
ll dist[660][660];

bool good[1000100];

ll A[660]; 

int n, m;

int main(){

	fastio;
	cin >> n >> m;

	fr(i, n){
		fr(j, n){
			dist[i][j] = llINF;
		}
	}

	fr(i, m){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
		edges.pb(mp(mp(u, v), w));
	}

	fr(i, n) dist[i][i] = 0;

	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int q;
	cin >> q;

	fr(i, q){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		query[u].pb({v, w});
		query[v].pb({u, w});
	}

	for(int v = 0; v < n; v++){
		fr(i, n){
			A[i] = llINF;
			for(auto x: query[v]){
				A[i] = min(A[i], dist[x.fst][i] - x.snd);
			}
			//if(v == 0) dbg(A[i]);
		}

		int j = 0;
		for(auto x: edges){
			if(-x.snd - dist[v][x.fst.fst] >= A[x.fst.snd]) good[j] = true;
			j++;
		}
	}

	int ans = 0;
	fr(i, m) if(good[i]) ans++;

	cout << ans << endl;

}
