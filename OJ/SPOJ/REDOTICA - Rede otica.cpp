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

int id[1123],sz[1123];
vector<pair<int,pii>> ed;
int freq[11234];
int n,m;
ll ans;
int t = 1;

int find(int p){
	if(id[p] == p) return p;
	return (id[p] = find(id[p]));
}

void merge(int p,int q){
	p = find(p);
	q = find(q);
	if(p==q) return;
	if(sz[p] > sz[q]) swap(p,q);
	id[p]= q;
	sz[q] += sz[p];
}

void kruskal(){
	
	fr(i,ed.size()){
		pair<int,pii> a = ed[i];
		int u = a.snd.fst;
		int v = a.snd.snd;
		if(find(u) == find(v)) continue;
		merge(u,v);
		freq[i] = 1;
	}

	
}

void solve(){
	ed.clear();
	ms(freq,0);
	frr(i,n){
		id[i] = i;
		sz[i] = 1;
	}
	fr(i,m){
		pair<int,pii> aux;
		cin >> aux.snd.fst >> aux.snd.snd >> aux.fst;
		ed.pb(aux);
	}
	sort(all(ed));
	kruskal();
	cout << "Teste "<<t++ <<endl;

	fr(i,ed.size()){
		if(freq[i]){
			cout << min(ed[i].snd.snd,ed[i].snd.fst) << ' '<< max(ed[i].snd.snd,ed[i].snd.fst)<<endl;
		}
	}
	gnl;


}

int main(){

	fastio;
	cin >> n >> m;
	while(n && m){
		solve();
		cin >> n >> m;
	}

}
