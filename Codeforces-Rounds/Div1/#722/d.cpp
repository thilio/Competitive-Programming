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
int n, m;
vector<pll> adj[700];
ll dist[700];
ll vis[700];

void dijkstra(int v){
	fr(i, n) dist[i] = llINF;
	fr(i, n) vis[i] = false;
	for(int i = 1; i < adj[v].size(); i++){
		dist[adj[v][i].fst] = adj[v][i].snd;
	}

	while(true){
		ll mn = llINF;
		int u = -1;
		fr(i, n){
			if(vis[i] == false){
				if(dist[i] < mn){
					mn = dist[i];
					u = i;
				}
			}
		}
		if(u == -1) break;
		vis[u] = true;

		fr(i, adj[u].size()){
			int t = adj[u][i].fst;
			ll w = adj[u][i].snd;
			if(i == 0){
				//if(u == v) continue;
				dist[t] = min(dist[t], dist[u] + 1);
			}
			else{
				t = (t + dist[u])%n;
				dist[t] = min(dist[t], dist[u] + w);
			}
		}
	}
}


int main(){

	fastio;

	cin >> n >> m;

	fr(i, n){
		adj[i].pb({(i + 1)%n, 1});
	}

	fr(i, m){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].pb({v, c});
	}

	fr(i, n){
		dijkstra(i);
		fr(j, n){ 
			if (j != i) cout << dist[j] << ' ';
			else cout << 0 << ' ';
		}
		gnl;
	}

}
