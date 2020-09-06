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
ll cost[200200];
int prob[200200];
pii subv[200200];
vi adj[200200];

ll ans;

void dfs_cost(int v,int p,ll c){
	cost[v] = min(cost[v],c);

	for(auto x : adj[v]){
		if(x == p) continue;
		dfs_cost(x,v,cost[v]);
	}
}

pii dfs_subv(int v,int p){

	for(auto x : adj[v]){
		if(x == p) continue;
		pii h = dfs_subv(x,v);
		subv[v].fst += h.fst;
		subv[v].snd += h.snd;
	}

	if(prob[v] == 1) subv[v].fst++;
	if(prob[v] == 2) subv[v].snd++;

	return subv[v];
}

ll dfs(int v,int p){
	ll k = 0;
	for(auto x : adj[v]){
		if(x == p) continue;
		k += dfs(x,v);
	}

	subv[v].fst-=k;
	subv[v].snd-=k;
	int mn = min(subv[v].fst,subv[v].snd);
	ans += 2*mn*cost[v];
	return k + mn;
}

int main(){

	fastio;
	cin >> n;
	frr(i,n){
		int a,b;
		cin >> cost[i];
		cin >> a >> b;
		if(a == b) continue;
		if(a == 0) prob[i] = 1;
		else prob[i] = 2;
	}

	fr(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs_cost(1,0,INF);
	pii aux = dfs_subv(1,0);

	if(aux.fst != aux.snd){
		cout << "-1" << endl;
		return 0;
	}

	int x = dfs(1,0);

	cout << ans << endl;


}
