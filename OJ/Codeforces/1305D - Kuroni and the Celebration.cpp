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
bool erased[1010];
int vis[1010];
vi adj[1010];

void ans(int x){
	cout << "! " << x << endl;
}

int query(int a, int b){
	cout << "? " << a << ' ' << b << endl;
	int y; cin >> y;
	return y;
}

int find(int v){
	ms(vis, -1);
	vis[v] = 1;
	queue<int> q;
	q.push(v);

	int last = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		last = u;

		for(auto x: adj[u]){
			if(!erased[x] && vis[x] == -1){
				q.push(x); vis[x] = 1;	
			}
		}
	}

	return last;
}

pii find_long(){
	int v;
	frr(i, n) if(!erased[i]) v = i;

	int u = find(v);
	int y = find(u);

	return mp(u, y);
}

int main(){

	fastio;
	cin >> n;

	fr(i, n - 1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	fr(i, n/2){
		pii longe = find_long();
		int x = query(longe.fst, longe.snd);
		if(x == longe.fst || x == longe.snd){
			ans(x);
			return 0;
		}
		erased[longe.fst] = true;
		erased[longe.snd] = true;
	}

	frr(i, n){
		if(!erased[i]) ans(i);
	}
}
