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

struct edge{
	int u;
	int w;
	int c;
};

typedef struct edge edge;
vector<edge> v;
int d[2020];
int n,m;

edge make_edge(int a,int b,int d){
	edge e;
	e.u = a;
	e.w = b;
	e.c = d;
	return e;
}

void solve(){
	v.clear();
	cin >> n >> m;
	edge e;
	fr(i,m){
		cin >>e.u >> e.w >> e.c;
		v.pb(e); 
	}
	fr(i,n){
		if(i == 0) d[i] = 0;
		else d[i] = INF;
	}

	fr(j,n-1){
		fr(i,m){
			if(d[v[i].u] == INF) continue;
			d[v[i].w] = min(d[v[i].w],d[v[i].u] + v[i].c);
		}
	}

	bool ok = false;

	fr(i,m){
		if(d[v[i].u] == INF) continue;
		if(d[v[i].w] > d[v[i].u] + v[i].c) ok = true;
	}

	if(!ok) cout << "not ";

	cout << "possible" << endl;

}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}	

}
