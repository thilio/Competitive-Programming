#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
//#define endl '\n'
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
vector<short int> adj[20200];
int f[15][16384];
short int query[40004];
int cost[20002];
short int xredge[20002];
int ans[20002];
int aux[16384];

int dfs_light(int v){
	//dbg(v);
	int mx = 0;
	int vtx_mx = -1;
	int my = 1;
	for(int i = 0; i < adj[v].size(); i++){
		int x = adj[v][i];
		int sz = dfs_light(x);
		if(sz > mx){
			mx = sz;
			vtx_mx = i;
		}
		my += sz;
	}
	if(vtx_mx != -1) swap(adj[v][vtx_mx], adj[v][0]);
	return my;
}

void dfs(int v, int xr, int light = 0){

	//dbg(v);

	ans[v] = f[light][xr];

	for(int i = 1; i < adj[v].size(); i++){
		int x = adj[v][i];
		fr(j, 1ll << 14){
			f[light + 1][j] = min(f[light][j], f[light][j^xredge[x]] + cost[x]);
		}
		dfs(x,xr^xredge[x], light + 1);
	}

	if(!adj[v].empty()){
		int x = adj[v][0];
		fr(i, 1ll << 14){
			aux[i] = min(f[light][i], f[light][i^xredge[x]] + cost[x]);
		}
		fr(i, 1ll << 14) f[light][i] = aux[i]; 
		dfs(x, xr^xredge[x], light);
	}
}

int main(){

	fastio;

//	olar;

	cin >> n;

	int at = 0;
	int novo = 1;
	stack<short int> P;

	fr(i, n){
		string s;
		cin >> s;
		if(s == "DEL"){
			at = P.top();
			P.pop();
			query[i] = at;
		}
		else{
			adj[at].pb(novo);
			query[i] = novo;
			P.push(at);
			int val;
			cin >> val >> cost[novo];
			xredge[novo] = val;
			at = novo;
			novo++;
		}
	}

	//olar;

	dfs_light(0);


	fr(i, 1 << 14) f[0][i] = 2*MOD;
	f[0][0] = 0;

	dfs(0, 0);

	//dbg(f[0][0]);

	fr(i, n) cout << ans[query[i]] << endl;

}
