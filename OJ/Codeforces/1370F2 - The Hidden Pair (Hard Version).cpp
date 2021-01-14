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
int l;
int r;
vi adj[1010];
int vis[1010];
vi dist[1010];

int vtx;

pii query(int a,int b){
	cout << '?' << ' ' << b - a + 1 << endl;
	for(int i = a; i <=b ; i++) cout << i << ' ';
	gnl;

	int x,d;
	cin >> x >> d;

	return mp(x,d);
}

void dfs(int v,int h){
	dist[h].pb(v);
	vis[v] = 1;

	for(auto x: adj[v]){
		if(vis[x]) continue;
		dfs(x,h+1);
	}

}

bool query_d (int level){
	if(dist[level].size() == 0){
		return false;
	}
	cout << "? ";
	cout << dist[level].size() << endl;
	fr(i,dist[level].size()) cout << dist[level][i] << ' ';
	gnl;

	int d;
	cin >> vtx >> d;

	if(d == l) return true;
	return false;

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		dist[0].clear();
		frr(i,n) adj[i].clear();
		frr(i,n) dist[i].clear();
		frr(i,n) vis[i] = 0;

		frr(i,n-1){
			int a,b;
			cin >> a >> b;

			adj[a].pb(b);
			adj[b].pb(a);
		}

		pii aux = query(1,n);
		r = aux.fst;
		l = aux.snd;

		dfs(r,0);

		int lw = l/2;
		int up = l;

		int ans1 = -2;

		while(lw <= up){
			int mid = (lw + up)/2;
			if(query_d(mid)){
				lw = mid + 1;
				ans1 = vtx;
			}
			else up = mid - 1;
		}

		frr(i,n) dist[i].clear();
		frr(i,n) vis[i] = 0;

		dfs(ans1,0);

		bool ok = query_d(l);

		cout <<'!' << ' ' << ans1 << ' ' << vtx << endl;
		string s;
		getline(cin,s);
		while(s != "Correct") getline(cin,s);


	}

}