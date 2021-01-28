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
vector<pll> adj[100100];
ll dist[100100];
ll vis[100100];

void dfs(int v){
	vis[v] = 1;

	fr(i,adj[v].size()){
		pll x = adj[v][i];
		if(vis[x.fst]) continue;
		dist[x.fst] = dist[v] + x.snd;
		dfs(x.fst);
	}
}
int main(){

	fastio;

	cin >> n;

	ll ans = 0;
	fr(i,n-1){
		ll u,v,c;
		cin >> u >> v >> c;
		adj[u].pb(mp(v,c));
		adj[v].pb(mp(u,c));
		ans += 2*c;
	}
	dist[1] = 0;
	dfs(1);

	ll mx = 0;
	frr(i,n){
		if(dist[i] > mx) mx = dist[i];
	} 

	ans -= mx;
	cout << ans << endl;



}
