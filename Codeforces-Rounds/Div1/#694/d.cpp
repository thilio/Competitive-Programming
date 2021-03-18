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

vi adj[300300];
bool vis[300300];
bool mark[300300];

void dfs(int v){
	vis[v] = 1;
	bool ok = false;

	for(auto x: adj[v]){
		if(vis[x]) ok |= mark[x];
	}

	if(!ok) mark[v] = true;

	for(auto x: adj[v]) if(!vis[x]) dfs(x);
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;

		frr(i,n){
			adj[i].clear();
			mark[i] = false;
			vis[i] = false;
		}

		fr(i, m){
			int u,v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		dfs(1);

		bool connected = true;
		frr(i, n){
			if(!vis[i]) connected = false;
		}

		if(!connected) cout << "NO" << endl;
		else{
			cout << "YES" << endl;

			int ans = 0;
			frr(i, n) ans += (mark[i]);
			cout << ans << endl;
			
			frr(i,n) if(mark[i]) cout << i << ' ';
			gnl;
		}
	}

}
