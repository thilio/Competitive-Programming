#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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
const int MOD = 998244353;

int n;
map<int, int> cord;
vi aux;
int a[300300];

ll seg[1200300];

void update(int node, int l, int r, int val, int pos){
	if(pos < l || pos > r) return;
	if(l == r){
		seg[node] = (seg[node] + val)%MOD;
		return;
	}

	int m = (l + r)/2;
	update(2*node, l, m, val, pos);
	update(2*node + 1, m + 1, r, val, pos);

	seg[node] = (seg[2*node] + seg[2*node + 1])%MOD;
}

ll query(int node, int l, int r, int a, int b){
	if(b < l || a > r) return 0;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;

	return (query(2*node, l, m, a, b) + query(2*node + 1, m + 1, r, a, b))%MOD;
}

ll fast(ll base, ll e){
	if(e == 0) return 1;
	ll ans = fast(base, e/2);
	ans = (ans*ans)%MOD;
	if(e&1) ans = (ans*base)%MOD;
	return ans;
}

int main(){

	fastio;

	cin >> n;

	ll inv = fast(2, MOD - 2);

	fr(i, n){
		cin >> a[i];
		aux.pb(a[i]);
	}

	sort(all(aux));
	int val = 0;
	for(auto x: aux){
		if(!cord.count(x)) cord[x] = ++val;
	}

	fr(i, n) a[i] = cord[a[i]];

	ll ans = 0;

	for(int i = 0; i < n; i++){
		ll x = query(1, 1, val, 1, a[i]);
		ans = (ans + x*fast(2, i - 1))%MOD;
		ll y = fast(inv, i);
		update(1, 1, val, y, a[i]);
	}

	cout << ans << endl;




}
