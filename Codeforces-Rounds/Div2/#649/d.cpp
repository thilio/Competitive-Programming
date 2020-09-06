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

int n,m,k;

vi adj[100100];

int h[100100];
int pai[100100];
int vis[100100];

vi cycle;

int mn;
pii ext;

void dfs(int v,int p){
	pai[v] = p;
	vis[v] = 1;

	for(auto x : adj[v]){
		if(vis[x] && h[x] > h[v]) continue;
		if(vis[x] == 0){
			h[x] = h[v] + 1;
			dfs(x,v);
		}

		if(vis[x] && h[x] < h[v] && x != p){
			int len = h[v] - h[x] + 1;
			if(len < mn){
				mn = len;
				ext = mp(v,x);
			} 

		}

	}

}

void create_cycle(){
	int j = ext.fst;
	int x = ext.snd;

	while(j != x){
		cycle.pb(j);
		j = pai[j];
	}
	cycle.pb(x);
}

int main(){

	fastio;

	cin >> n >> m >> k;

	mn = n + 1;

	fr(i,m){
		int a,b;
		cin >> a >> b;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	h[1] = 1;

	dfs(1,-1);

	if(mn == n + 1){
		vi par;
		vi impar;

		par.clear();
		impar.clear();
		frr(i,n){
			if(h[i]%2) impar.pb(i);
			else par.pb(i);
		}

		k = (k + 1)/2;

		cout << 1 << endl;

		if(par.size() >= k){
			fr(i,k){
				cout << par[i] << ' ';
			}

			gnl;
		}
		else{
			fr(i,k){
				cout << impar[i] << ' ';
			}
			gnl;
		}

		return 0;

	}

	create_cycle();

	//fr(i,cycle.size()) dbg(cycle[i]);
	if(mn <= k){
		cout << 2 << endl;
		cout << mn << endl;
		fr(i,cycle.size()) cout << cycle[i] << ' ';
		gnl;
	}
	else{
		cout << 1 << endl;
		fr(i,(k+1)/2){
			cout << cycle[2*i] << ' ';
		}
		gnl;
	}
	





}
