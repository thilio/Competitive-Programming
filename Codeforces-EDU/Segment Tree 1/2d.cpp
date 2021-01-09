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

ll seg[400400];
ll v[100100];

void update(int node,int l,int r,int i,int val){
	if(i < l || i > r) return;

	if(l == r && i == l){
		v[i] = val;
		seg[node] = v[i];
		return;
	}

	int m  = (l+r)/2;

	update(2*node,l,m,i,val);
	update(2*node + 1,m+1,r,i,val);

	seg[node] = max(seg[2*node],seg[2*node + 1]);
}

int find(int node,int l,int r,int x,int lx){
	if(r < lx) return 0;
	if(seg[node] < x) return 0;
	if(l == r) return l;

	int m = (l+r)/2;

	int p = find(2*node,l,m,x,lx);
	if(p != 0) return p;
	
	return find(2*node + 1,m+1,r,x,lx);
	
}



int main(){

	fastio;

	int n,q;
	cin >> n >> q;

	frr(i,n){
		cin >> v[i];
		update(1,1,n,i,v[i]);
	}

	fr(i,q){
		int op;
		cin >> op;
		if(op == 1){
			int j,val;
			cin >> j >> val;
			j++;
			update(1,1,n,j,val);
		}
		else{
			int k,lx;
			cin >> k >> lx;
			lx++;
			
			cout << find(1,1,n,k,lx) - 1 << endl;
			
		}
	}

}
