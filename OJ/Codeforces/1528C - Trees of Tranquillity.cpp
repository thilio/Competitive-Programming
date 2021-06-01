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

int tin[300300], tout[300300];
vi sonk[300300], sons[300300];
int t = 1;
int n;
int ans;
set<pii> S;

void clear(){
	frr(i, n){
		tin[i] = tout[i] = 0;
		sonk[i].clear();
		sons[i].clear();
	}
	ans = 0;
}

void dfs_t(int v){
	tin[v] = t++;
	for(auto x: sonk[v]) dfs_t(x);
	tout[v] = t++;
}

int add(int v){
	auto it = S.lower_bound({tin[v], v});
	if(it != S.end() && tout[(*it).second] < tout[v]) return -1;
	if(it == S.begin()){
		S.insert({tin[v], v});
		return 0;
	}
	it--;
	if(tout[(*it).second] < tin[v]){
		S.insert({tin[v], v});
		return 0;
	}
	else{
		int u = (*it).snd;
		S.erase(it);
		S.insert({tin[v], v});
		return u;	
	}
}

void dfs(int v){
	int y = add(v);
	ans = max(ans,(int)S.size());
	for(auto x: sons[v]) dfs(x);
	if(y >= 0){
		S.erase({tin[v], v});
		if(y > 0) S.insert({tin[y], y});
	}
}

void solve(){
	cin >> n;
	clear();

	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		sons[x].pb(i);
	}
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		sonk[x].pb(i);
	}

	dfs_t(1);
	dfs(1);
	cout << ans << endl;

}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
