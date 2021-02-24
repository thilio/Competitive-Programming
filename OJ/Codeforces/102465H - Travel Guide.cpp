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

vii adj[100100];
int n,m;
int dist[3][100100];
int mark[100100];

vector<pair<int,pii>> v;
map<int,int> comp;
vi compre;

int seg[2000000];

int query(int node,int l,int r,int a,int b){
	if(b < l || a > r) return INF;
	if(a <= l && r <= b) return seg[node];
	int m = (l + r)/2;
	int q1 = query(2*node, l,m,a,b);
	int q2 = query(2*node + 1,m + 1,r,a,b);
	return min(q1,q2);
}

void update(int node,int l,int r,int val,int pos){
	if(pos < l || pos > r) return;
	if(l == r){
		seg[node] = val;
		return;
	}
	int m = (l + r)/2;
	update(2*node,l,m,val,pos);
	update(2*node + 1,m + 1,r,val,pos);

	seg[node] = min(seg[2*node], seg[2*node + 1]);
}

void dijkstra(int v){
	fr(i,n) dist[v][i] = -1;
	priority_queue<pii, vii, greater<pii>> pq;
	pq.push(mp(0, v));

	while(!pq.empty()){
		pii at = pq.top();
		pq.pop();

		if(dist[v][at.snd] != -1) continue;
		dist[v][at.snd] = at.fst;

		for(auto x: adj[at.snd]){
			if(dist[v][x.fst] == -1) pq.push(mp(x.snd + at.fst, x.fst));
		} 
	}
}

int main(){

	fastio;

	cin >> n >> m;

	for(int i =0; i < 2000000;i++) seg[i] = INF;

	fr(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}

	dijkstra(0);
	dijkstra(1);
	dijkstra(2);

	fr(i,n){
		fr(j,3) compre.pb(dist[j][i]);
	}
	sort(all(compre));
	int tot = 2;
	for(auto x: compre){
		if(!comp.count(x)) comp[x] = tot++;
	}

	fr(i,n){
		int a,b,c;
		a = comp[dist[0][i]];
		b = comp[dist[1][i]];
		c = comp[dist[2][i]];
		v.pb(mp(a,mp(b,c)));
	}

	sort(all(v));

	int ans = 0;

	int i = 0;
	int j = 0;
	while(i < n){
		j = i;
		while(v[i].fst == v[j].fst && j < n){
			j++;
		}
		for(int k = i; k < j; k++){
			if(query(1,1,tot,1, v[k].snd.fst) <= v[k].snd.snd) mark[k] = 1;
		}
		for(int k = i; k < j; k++){
			if(mark[k]) continue;
			if(query(1,1,tot,1, v[k].snd.fst) < v[k].snd.snd) mark[k] = 1;
			if(query(1,1,tot,1, v[k].snd.fst - 1) <= v[k].snd.snd) mark[k] = 1;
			if(mark[k] == 0){
				update(1,1,tot,v[k].snd.snd,v[k].snd.fst);
			}	
		}
		i = j;
	}
	fr(i,n) if(mark[i]) ans++;

	cout << n - ans << endl;
}
