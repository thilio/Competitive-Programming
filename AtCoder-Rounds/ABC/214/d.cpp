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

int id[100100];
ll sz[100100];
int n;

vector<pair<ll, pii>> v;

void init(){
	frr(i, n) id[i] = i;
	frr(i, n) sz[i] = 1;
}

int find(int i){
	if(id[i] == i) return i;
	else return id[i] = find(id[i]);
}

ll merge(int u, int v, ll w){
	u = find(u);
	v = find(v);
	ll su = sz[u];
	ll sv = sz[v];

	if(su > sv) swap(u, v);

	id[u] = v;
	sz[v] += sz[u];

	return w*su*sv;
}

int main(){

	fastio;
	
	cin >> n;
	init();

	fr(i, n - 1){
		int u, u1, w;
		cin >> u >> u1 >> w;
		v.pb(mp(w, mp(u, u1)));
	}

	sort(all(v));

	ll ans = 0;
	for(auto x: v){
		ans += merge(x.snd.fst, x.snd.snd, x.fst);
	}

	cout << ans << endl;



}
