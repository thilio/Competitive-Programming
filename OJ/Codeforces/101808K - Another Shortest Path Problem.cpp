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
const int nmax = 100100;
const int lmax = 19; 

vii nodes[100100];
int hgt[100100];
int vis[100100];
ll dist[100100];
int memo[100100][20];

int u,v,w;

void adfs(int s,int pai){
	vis[s] = 1;
	//dbg(pai);
	for(auto x : nodes[s]){
		int k = x.fst;
		int p = x.snd;

		if (vis[k] == 1 && k != pai){
			u = s;
			v = k;
			w = p;
			continue;
		}
		if(vis[k] == 1) continue;

		adfs(k,s);
	} 

}

void dfs (int s){

	vis[s] = 1;

	for(auto x: nodes[s]){
		//dbg(x.fst);
		int k = x.fst;
		int p = x.snd;
		if(vis[k]) continue;

		hgt[k] = hgt[s] + 1;
		memo[k][0] = s;
		dist[k] = dist[s] + p;
		for(int i = 1;i<=lmax;i++){
			//dbg(i);
			memo[k][i] = memo[memo[k][i-1]][i-1];
			//dbg(memo[k][i-1]);
		}

		dfs(k);
	}

}

int lca (int a,int b){
	if(hgt[a] < hgt[b])
		swap(a,b);

	for(int i = lmax;i>=0;i--){
		if(hgt[memo[a][i]] >= hgt[b])
			a = memo[a][i];
	}

	if(a==b) return a;

	for(int i = lmax;i>=0;i--){
		if(memo[a][i] != memo[b][i]){
			a = memo[a][i];
			b = memo[b][i];
		}
	}

	return (memo[a][0]);
}

ll dis (int a,int b){
	return (dist[a] + dist[b] - 2*dist[lca(a,b)]);
}

ll mn(ll a ,ll b){
	if(a<b) return a;
	return b;
}

void solve(){
	int n;
	int q;

	cin >> n >> q;

	fr(i,nmax){
		fr(j,lmax+1){
			memo[i][j] = 1;
		}
	}
	ms(vis,0);
	ms(hgt,0);
	ms(dist,0);

	fr(i,nmax)
		nodes[i].clear();

	u = v = w = 0;

	int a,b,c;
	fr(i,n){
		cin >> a >> b >> c;
		nodes[a].pb({b,c});
		nodes[b].pb({a,c});
	}
	

	adfs(1,0);
	ms(vis,0);

	int ct = 0;

	for(auto x: nodes[u]){
		if(x.fst == v){
			nodes[u].erase(nodes[u].begin() + ct);
		}
		ct++;
	}

	ct = 0;

	for(auto x: nodes[v]){
		if(x.fst == u){
			nodes[v].erase(nodes[v].begin() + ct);
		}
		ct++;
	}

	dfs(1);
	
	fr(i,q){
		int a,b;
		cin >> a >> b;
		ll ans = dis(a,b);
		ans =  mn(ans,dis(a,v) + dis(b,u) + w);
		ans = mn(ans,dis(a,u) + dis(b,v) + w);
		cout << ans << endl;

	}


}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
