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
string s;
string t;

vi adj[30];
vi comp;
int reach[30];
bool vis[30];
bool is_dag[2000100];


void clean(){
	fr(i, 30){
		adj[i].clear();
		reach[i] = 0;
	}
	comp.clear();
	ms(is_dag, false);
	ms(vis, false);
	is_dag[0] = true;
}

void dfs(int v){
	vis[v] = true;
	comp.pb(v);
	for(auto x: adj[v]){
		if(!vis[x]) dfs(x);
	}
}

int s_comp(){
	int k = comp.size();

	int big = 0;

	for(int i = 0; i < (1 << k); i++){
		int mask = 0;
		fr(j, k){
			if((1 << j)&i) mask += (1 << comp[j]);
		}
		if(is_dag[mask]) big = max(big, __builtin_popcount(mask));
	}

	return 2*k - big - 1;
}

void solve(){
	clean();

	cin >> n;
	cin >> s >> t;

	fr(i, n){
		if(s[i] != t[i]){
			adj[s[i] - 'a'].pb(t[i] - 'a');
			adj[t[i] - 'a'].pb(s[i] - 'a');
			reach[s[i] - 'a'] |= 1ll << (t[i] - 'a');
		}
	}

	for(int mask = 1; mask < (1 << 20); mask++){
		fr(i, 20){
			if(mask & (1 << i)){
				if(is_dag[mask^(1 << i)] && ((reach[i]&mask) == 0)) is_dag[mask] = true;
			}
		}
	}

	//fr(i, 8) dbg(is_dag[i]);

	int ans = 0;
	fr(i, 20){
		comp.clear();
		if(!vis[i]){
			dfs(i);
			ans += s_comp();
		}
	}

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
