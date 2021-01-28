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
	int v;
	int w;
	int cost;
};

typedef struct edge edge;

int n,m,k;
int id[100100];
int r[100100];
int type[100100];
vector<edge> v;

int find(int a){
	if(id[a] == a) return a;
	return id[a] = find(id[a]);
}

void merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(r[a] > r[b]) swap(a,b);
	id[a] = b;
	if(r[a] == r[b]) r[b]++;
}

int main(){

	fastio;
	cin >> n >> m >> k;
	int t = 1;
	int p = 1;

	frr(i,n){
		id[i] = i;
		r[i] = 1;
	}


	fr(i,k){
		int c;
		cin >> c;
		fr(l,c){
			type[p + l] = t;
		}
		t++;
		p += c;
	}

	fr(i,m){
		edge a;
		cin >> a.v >> a.w >> a.cost;
		v.pb(a);
		if(a.cost == 0)
			merge(a.v,a.w);
	}

	bool ok = true;

	frr(i,n-1){
		if(find(i) != find(i + 1) && type[i] == type[i+1])
			ok = false;
	}

	if(!ok){
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";
	int dist[550][550];

	frr(i,k){
		frr(j,k)
			dist[i][j] = INF;

	}

	frr(i,k) dist[i][i] = 0;

	fr(i,v.size()){
		edge a = v[i];
		dist[type[a.v]][type[a.w]] = min(dist[type[a.v]][type[a.w]],a.cost);
		dist[type[a.w]][type[a.v]] = min(dist[type[a.w]][type[a.v]],a.cost);
	}

	frr(l,k){
		frr(i,k){
			frr(j,k){
				dist[i][j] = min(dist[i][j],dist[i][l] + dist[l][j]);
			}
		}
	}

	frr(i,k){
		frr(j,k){
			if(dist[i][j] == INF) dist[i][j] = -1;
		}
	}

	frr(i,k){
		frr(j,k){
			cout << dist[i][j] << ' ';
		}

		gnl;
	}

}
