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
const int MOD = 1e9+7;

vector<pll> adj[400400];

int s, t;

ll dist[400400][2];

int n;

void dfs(int v, int p, int type){

	for(auto x: adj[v]){
		ll c; int u;
		tie(u, c) = x;
		if(u == p) continue;
		dist[u][type] = dist[v][type] + c;
		dfs(u, v, type);
	}
}

int main(){

	fastio;

	cin >> n;

	fr(i, n - 1){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].pb({v, c});
		adj[v].pb({u, c});
	}

	frr(i, n){
		int d;
		cin >> d;
		adj[i].pb({i + n, d});
		adj[i + n].pb({i, d});
	}

	dist[1][0] = 0;

	dfs(1, -1, 0);

	s = 1;
	frr(i, 2*n){
		if(dist[i][0] > dist[s][0]) s = i;
	}

	dist[s][0] = 0;

	dfs(s, -1, 0);

	t = s;

	frr(i, 2*n){
		if(dist[i][0] > dist[t][0]) t = i;
	}

	dist[t][1] = 0;

	dfs(t, -1, 1);


	//frr(i, 2*n) dbg(dist[i][0]);
	//gnl;
	//frr(i, 2*n) dbg(dist[i][1]);

	frr(i, n){
		if(i == s - n){
			cout << dist[i][1] << endl;
		}
		else if(i == t - n){
			cout << dist[i][0] << endl;
		}
		else{
			cout << max(dist[i][0], dist[i][1]) << endl;
		}
	}


}
