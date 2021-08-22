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

int n;
vi adj[30], ans[30];

void go(int v, int f){
	if(f == adj[v].size()) return;

	int u = adj[v][f];

	for(auto x: ans[u]){
		go(v, f + 1);
		ans[v].pb(x);
	}

	reverse(all(ans[u]));
	go(v, f + 1);
}

void dfs(int v){
	ans[v].pb(v);
	for(auto x: adj[v]) dfs(x);
	go(v, 0);
}

int main(){

	fastio;
	cin >> n;

	for(int i = 2; i <= n; i++){
		int p; cin >> p;
		adj[p].pb(i);
	}

	dfs(1);

	cout << ans[1].size() - 1 << endl;
	for(int i = 1; i < ans[1].size(); i++) cout << ans[1][i] << ' ';
	gnl;

}
