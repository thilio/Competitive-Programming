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

vi adj[100100];
int h[100100];
int folha[100100];
int vis[100100];

bool par[2];

int dfs(int v){
	vis[v] = 1;

	for(auto x : adj[v]){
		if(vis[x] == 1) continue;
		h[x] = h[v] + 1;
		folha[v] += dfs(x);
	}

	if(adj[v].size() == 1) return 1;
	return 0;

}

int main(){

	fastio;

	int n;
	cin >> n;

	fr(i,n-1){
		int a,b;
		cin >> a >> b;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	frr(i,n){
		if(adj[i].size() > 1){
			int x = dfs(i);
			break;
		}
	}

	//frr(i,n) dbg(h[i]);

	frr(i,n){
		if(adj[i].size() == 1){
			par[h[i]%2] = true;
		}
	}

	bool ok = par[0] && par[1];

	if(!ok) cout << 1 << ' ';
	else cout << 3 << ' ';

	int sum = 0;
	frr(i,n){
		if(folha[i] > 0){
			sum += folha[i] - 1;
		}
	}

	cout << n - 1 - sum << endl;




}
