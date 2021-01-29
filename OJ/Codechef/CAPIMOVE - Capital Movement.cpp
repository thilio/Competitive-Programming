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
vi adj[50500];
vector<pii> v;
int vis[50500],hgt[50500],memo[50500][20];

void dfs(int v){
	vis[v] = 1;
	for(auto x: adj[v]){
		if(vis[x] == 1) continue;
		hgt[x] = hgt[v] + 1;
		memo[x][0] = v;
		frr(i,17)
			memo[x][i] = memo[memo[x][i-1]][i-1];

		dfs(x);
	}
}

int lca(int u,int v){
	if(hgt[u] < hgt[v]) swap(u,v);

	for(int i = 17;i>=0;i--){
		if(hgt[memo[u][i]] >= hgt[v])
			u = memo[u][i];
	}

	if(u==v) return u;

	for(int i = 17; i >= 0;i--){
		if(memo[u][i] != memo[v][i]){
			u = memo[u][i];
			v = memo[v][i];
		}
	}

	return (memo[u][0]);
}

int dist(int u,int v){
	return (hgt[u] + hgt[v] - 2*hgt[lca(u,v)]);
}


int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){

		fr(i,50500){
			ms(memo[i],0);
		}

		ms(vis,0);
		ms(hgt,0);


		cin >> n;
		v.clear();
		fr(i,n){
			pii a;
			cin >> a.fst;
			a.snd = i + 1;
			v.pb(a); 
		}

		sort(all(v));
		reverse(all(v));

		fr(i,50500){
			adj[i].clear();
		}

		fr(i,n-1){
			int a,b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		fr(i,18)
			memo[1][i] = 1;

		dfs(1);


		frr(i,n){
			fr(j,n){
				if(dist(i,v[j].snd) > 1){
					cout << v[j].snd << ' ';
					break;
				}
				
			}
		}

		gnl;



	}

}
