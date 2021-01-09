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

struct no{
	ll v[41];
	ll inv;
};

no seg[400400];
int n,q;

void update(int node,int l,int r,int i,int val){
	if(i <l || i > r) return;
	if(l == r && l == i){
		frr(k,40) seg[node].v[k] = 0;
		seg[node].v[val] = 1;
		seg[node].inv = 0;
		return;
	}

	int m = (l + r)/2;

	update(2*node,l,m,i,val);
	update(2*node + 1,m+1,r,i,val);

	no x = seg[2*node];
	no y = seg[2*node + 1];

	frr(k,40) seg[node].v[k] = x.v[k] + y.v[k];
	seg[node].inv = x.inv + y.inv;

	int aux = 0;
	frr(k,40){
		seg[node].inv += x.v[k]*aux;
		aux += y.v[k];
	}
}

void query(int node,int l,int r,int a,int b,no &s){
	if(a <= l && r <= b){
		s = seg[node];
		return;
	}
	if(b < l || a > r){
		frr(k,40) s.v[k] = 0;
		s.inv = 0;
		return;
	}

	int m = (l + r)/2;

	no s1,s2;

	query(2*node,l,m,a,b,s1);
	query(2*node + 1,m+1,r,a,b,s2);

	frr(k,40){
		s.v[k] = s1.v[k] + s2.v[k];
	}

	s.inv = s1.inv + s2.inv;
	int aux = 0;
	frr(k,40){
		s.inv += s1.v[k]*aux;
		aux += s2.v[k];
	}
}

int main(){

	fastio;

	cin >> n >> q;

	frr(i,n){
		int a;
		cin >> a;
		update(1,1,n,i,a);
	}

	frr(i,q){
		int op;
		cin >> op;
		if(op == 1){
			int a,b;
			cin >> a >> b;
			no t;
			query(1,1,n,a,b,t);
			cout << t.inv << endl;
		}
		if(op == 2){
			int j,val;
			cin >> j >> val;
			update(1,1,n,j,val);
		}
	}



}
