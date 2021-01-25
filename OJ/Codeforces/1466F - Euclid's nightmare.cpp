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
vi ans;
int sz[500500];
int id[500500];

void init(){
	frr(i,500100){
		id[i] = i;
		sz[i] = i;
	}
}

int find(int u){
	if(u == id[u]) return u;
	return id[u] = find(id[u]);
}

bool merge(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v) return false;
	if(sz[u] > sz[v]) swap(u,v);
	id[u] = v;
	sz[v] += sz[u];
	return true;
}

ll fast(ll base,ll exp){
	if(exp == 0) return 1;
	ll ans = fast(base, exp/2);
	ans = ans*ans;
	ans%=MOD;
	if(exp&1) ans *= base;
	ans %= MOD;
	return ans;
}

int main(){

	fastio;

	int n,m;

	cin >> n >> m;
	init();

	frr(i,n){
		int k;
		cin >> k;
		if(k == 2){
			int u,v;
			cin >> u >> v;
			if(merge(u,v)) ans.pb(i);
		}
		if(k == 1){
			int u,v;
			cin >> u;
			v = m + 1;
			if(merge(u,v)) ans.pb(i);
		}
	}

	cout <<  fast(2,ans.size()) << ' ' << ans.size() << endl;

	for(auto x : ans){
		cout << x << ' ';
	}
	gnl;

}
