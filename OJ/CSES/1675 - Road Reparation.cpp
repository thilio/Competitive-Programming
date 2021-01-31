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

const int MAXN = 100100;
const int MAXM = 200100;

int n,m;
int id[MAXN],sz[MAXN];
bool mst[MAXM];
vector<pair<ll,pair<int,int>>> edges;

void init(){
	for(int i = 1; i <= n; i++){
		id[i] = i;
		sz[i] = 1;
	}
}

int find (int p){
	if(id[p] == p) return p;
	return (id[p] = find(id[p]));
}

void merge (int p, int q){
	p = find(p);
	q = find(q);
	if(p == q) return;
	if(sz[p] > sz[q]) swap(p,q);
	id[p] = q;
	sz[q] += sz[p];
}

void kruskal(){
	init();
	sort(edges.begin(), edges.end());
	for(int i = 0; i < m; i++){
		pair<int,int> e = edges[i].second;
		if(find(e.first) == find(e.second)) continue;
		merge(e.first,e.second);
		mst[i] = true;
	}
}

int main(){

	fastio;

	cin >> n >> m;
	edges.resize(m);
	fr(i,m) cin >> edges[i].snd.fst >> edges[i].snd.snd >> edges[i].fst;

	kruskal();

	if(sz[find(1)] != n){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		ll ans = 0;
		fr(i,m)
			if(mst[i]) ans += edges[i].fst;
		cout << ans << endl;
	}

}
