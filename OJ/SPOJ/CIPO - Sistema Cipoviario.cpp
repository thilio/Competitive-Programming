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
typedef pair<int,pii> pi;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int n,m;
int t = 1;
vector<pi> ed;
int sz[10000],id[10000];

int find(int p){
	if(id[p] == p) return p;
	return (id[p] = find(id[p]));
}

void merge (int p,int q){
	p = find(p);
	q = find(q);
	if(p==q) return;
	if(sz[p] > sz[q]) swap(p,q);
	id[p] = q;
	sz[q] += sz[p];
}

ll kruskal(){
	ll res = 0;
	fr(i,m){
		pi aux = ed[i];
		int u = aux.snd.fst;
		int v = aux.snd.snd;
		if(find(u) == find(v)) continue;
		merge(u,v);
		res += aux.fst;
	}
	return res;
}

void solve(){
	ed.clear();
	frr(i,n){
		sz[i] = 1;
		id[i] = i;
	}
	fr(i,m){
		pi aux;
		cin >> aux.snd.fst >> aux.snd.snd >> aux.fst;
		ed.pb(aux);
	}
	sort(all(ed));
	cout << "Instancia "<<t++<<endl;
	cout << kruskal() << endl;
	gnl;

}

int main(){

	fastio;
	while(cin >> n >> m){
		solve();
	}

}
