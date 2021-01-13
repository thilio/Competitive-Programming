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

ll seg[1000100];
int n,q;
ll x;

void update(int node,int l,int r,int j,int val){
	if(j < l || j > r) return;
	if(l == r) {
		seg[node] = val;
		return;
	}

	int m = (l + r)/2;
	update(2*node,l,m,j,val);
	update(2*node + 1,m + 1, r, j, val);

	seg[node] = seg[2*node] + seg[2*node + 1];
}

ll query_seg(int node,int l, int r,int a,int b){
	
	if(b < l || a > r) return 0;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;
	return query_seg(2*node,l,m,a,b) + query_seg(2*node + 1,m + 1,r,a,b);
}

ll query(int node,int l,int r,int a,int b){
	if(b < l || a > r) return 0;
	if(a <= l && r <= b){
		ll len = r - l + 1;
		return query_seg(1,0, (1 << n) - 1, l^(x&(~(len - 1))), r^(x&(~(len - 1))));
	}

	int m = (l + r)/2;
	return query(2*node,l,m,a,b) + query(2*node + 1,m + 1,r,a,b);	
}


int main(){

	fastio;
	cin >> n >> q;

	fr(i,(1 << n)){
		ll y;
		cin >> y;
		update(1,0,(1<<n) - 1,i,y);
	}


	fr(i,q){
		int op;
		cin >> op;
		if(op == 1){
			ll pos,k;
			cin >> pos >> k;
			pos--;
			update(1,0,(1 << n) -1,pos^x,k);

		}
		if(op == 2){
			int k;
			cin >> k;
			x ^= (1ll << k) - 1ll;

		}
		if(op == 3){
			int k;
			cin >> k;
			x ^= (1ll << k);
		}
		if(op == 4){
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			cout << query(1,0,(1 << n) - 1,l,r)<< endl;
		}
	}

}
