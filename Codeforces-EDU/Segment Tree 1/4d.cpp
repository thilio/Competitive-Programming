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

int n,q;

ll seg[400400];

void update(int node,int l,int r,int i ,ll val){
	if(i <l || i > r) return;
	if(l == r && i == l){
		seg[node] = (1ll << val);
		return;
	}

	int m = (l + r)/2;
	update(2*node,l,m,i,val);
	update(2*node + 1,m+1,r,i,val);

	seg[node] = seg[2*node]|seg[2*node + 1];
}

ll query(int node,int l,int r,int a,int b){
	if(a <= l && r <= b){
		return seg[node];
	}
	if(b < l || r < a){
		return 0;
	}

	int m = (l + r)/2;

	ll x = query(2*node,l,m,a,b);
	ll y = query(2*node + 1,m+1,r,a,b);
	return x|y;
	
}

int main(){

	fastio;

	cin >> n >> q;

	frr(i,n){
		ll x;
		cin >> x;
		update(1,1,n,i,x);
	}

	fr(i,q){
		int op;
		cin >> op;
		if(op == 2){
			ll j,val;
			cin >> j >> val;
			update(1,1,n,j,val);
			continue;
		}
		int a,b;
		cin >> a >> b;
		ll x = query(1,1,n,a,b);
		cout << __builtin_popcountll(x) << endl;
	}

}
