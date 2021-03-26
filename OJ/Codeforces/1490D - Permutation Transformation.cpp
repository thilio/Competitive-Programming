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

vi adj[110];
int v[110];
int level[110];

int build(int l, int r){
	if(l == r) return l;
	int mx = l;
	//olar;
	for(int i = l ; i <= r; i++){
		if(v[i] > v[mx]) mx = i;
	}
	//dbg(mx);

	if(mx > l) adj[v[mx]].pb(v[build(l, mx - 1)]);
	if(mx < r) adj[v[mx]].pb(v[build(mx + 1, r)]);
	return mx;
}

void dfs(int v, int p){
	level[v] = p;

	for(auto x: adj[v]) dfs(x, p + 1);

}

int main(){

	fastio;

	int T;
	cin >> T;

	while(T--){
		int n;
		cin >> n;

		frr(i, n) adj[i].clear();

		frr(i, n) cin >> v[i];

		int root = v[build(1, n)];

		dfs(root, 0);

		frr(i, n) cout << level[v[i]] << ' ';
		gnl;
	}

}
