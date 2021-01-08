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
int c[212345];
int adj[212345];
int vis[212345];
int visc[212345];
vi adjr[212345];

int minct(int j){
	int ct = c[j];
	int k = adj[j];

	while(k!=j){
		if(c[k] < ct)
			ct = c[k];
		k = adj[k];
	}

	return ct;
}

int find_cycle(int v){
	int k = v;
	while(visc[k] == 0){
		visc[k] = 1;
		k =adj[k];
	}

	return k;
}

void dfs(int v){
	//dbg(adjr[v].size());
	vis[v] = 1;
	for(int i = 0;i<adjr[v].size();i++){
		if(vis[adjr[v][i]] == 0)
			dfs(adjr[v][i]);
	}
}

int solve(int i){

	int ci = find_cycle(i);
	//dbg(ci);
	dfs(ci);
	return minct(ci);

}


int main(){

	fastio;
	cin >> n;

	frr(i,n)
		cin >> c[i];

	frr(i,n){
		int a;
		cin >> a;
		adj[i] = a;
		adjr[a].pb(i);
	}

	ll ans = 0;

	frr(i,n){
		if(vis[i]) continue;
	//	dbg(i);
		
		ans+= solve(i);
	}

	cout << ans << endl;

	




}
