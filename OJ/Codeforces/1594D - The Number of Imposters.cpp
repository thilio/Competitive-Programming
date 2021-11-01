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

int n, m;

vi adj[200200];
vi adjc[200200];
int comp[200200];
int vis[200200];
int we[200200];
vector<pii> good, bad;

void clear(){
	frr(i, n){
		adj[i].clear();
		adjc[i].clear();
		comp[i] = -1;
		vis[i] = -1;
		we[i] = 0;
	}
	good.clear();
	bad.clear();
}

void dfs(int v, int cc){
	comp[v] = cc;
	for(auto x: adj[v]){
		if(comp[x] == -1) dfs(x, cc);
	}
}

void dfsc(int v, int&b, int &w, int est){
	if(est == 0) b += we[v];
	else w += we[v];

	vis[v] = est;

	for(auto x: adjc[v]){
		if(vis[x] == -1){
			dfsc(x, b, w, 1 - est);
		}
		if(vis[x] == est){
			b = -INF;
			w = -INF;
		}
	}
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		clear();

		fr(i, m){
			int u, v;
			string s;
			cin >> u >> v >> s;

			if(s == "crewmate") good.pb({u, v});
			else bad.pb({u, v});
		}

		for(auto x: good){
			adj[x.fst].pb(x.snd);
			adj[x.snd].pb(x.fst);
		}

		int ncomp = 0;

		frr(i, n){
			if(comp[i] == -1){
				ncomp++;
				dfs(i, ncomp);
			}
		}

		frr(i, n) we[comp[i]]++;

		bool imp = false;

		for(auto x: bad){
			if(comp[x.fst] == comp[x.snd]) imp = false;
			adjc[comp[x.fst]].pb(comp[x.snd]);
			adjc[comp[x.snd]].pb(comp[x.fst]);
		}

		int ans = 0;

		

		frr(i, ncomp){
			if(vis[i] == -1){
				int black = 0;
				int white = 0;
				dfsc(i, black, white, 0);

				if(black < 0 || white < 0){
					imp = true;
				}
				ans += max(black, white);
			}
		}

		if(imp) cout << -1 << endl;
		else cout << ans << endl;
	}

}
