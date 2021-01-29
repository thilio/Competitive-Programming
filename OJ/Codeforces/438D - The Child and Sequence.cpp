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
pll seg_max[1000000];
ll seg_sum[1000000];
ll v[100100];

pll merge_max(pll a, pll b){
	if(a.snd == b.snd){
		return(mp(min(a.fst,b.fst),a.snd));
	}
	if(b.snd > a.snd) return b;
	return a;
}

void build_max(int node,int l,int r){
	if(l == r){
		seg_max[node] = mp(l,v[l]);
		return;
	}

	int mid = (l + r)/2;

	build_max(2*node,l,mid);
	build_max(2*node + 1,mid + 1,r);
	seg_max[node] = merge_max(seg_max[2*node],seg_max[2*node + 1]);
}

void build_sum(int node,int l,int r){
	if(l == r){
		seg_sum[node] = v[l];
		return;
	}

	int mid = (l + r)/2;

	build_sum(2*node,l,mid);
	build_sum(2*node + 1,mid + 1,r);
	seg_sum[node] = (seg_sum[2*node] + seg_sum[2*node + 1]);
}

void update_max(int node,int l,int r,int id,int val){
	if(l == r){
		v[l] = val;
		seg_max[node] = mp(id,val);
		return;
	}

	int mid = (l + r)/2;
	if(l <= id && id <= mid) update_max(2*node,l,mid,id,val);
	else update_max(2*node + 1,mid+1,r,id,val);

	seg_max[node] = merge_max(seg_max[2*node],seg_max[2*node + 1]);
}

void update_sum(int node,int l,int r,int id,int val){
	if(l == r){
		v[l] = val;
		seg_sum[node] = val;
		return;
	}

	int mid = (l + r)/2;
	if(l <= id && id <= mid) update_sum(2*node,l,mid,id,val);
	else update_sum(2*node + 1,mid+1,r,id,val);

	seg_sum[node] = (seg_sum[2*node] + seg_sum[2*node + 1]);
}

pll query_max (int node,int l,int r,int a,int b){
	if(a > r || b < l) return mp(-1,-1);
	if(l >= a && r <= b) return seg_max[node];

	int mid = (l + r)/2;

	return merge_max(query_max(2*node,l,mid,a,b),query_max(2*node + 1,mid+1,r,a,b));
}

ll query_sum (int node,int l,int r,int a,int b){
	if(a > r || b < l) return 0;
	if(l >= a && r <= b) return seg_sum[node];

	int mid = (l + r)/2;

	return (query_sum(2*node,l,mid,a,b) + query_sum(2*node + 1,mid+1,r,a,b));
}


int main(){

	fastio;
	ll n,m;
	cin>> n >> m;
	frr(i,n) cin >> v[i];
	build_sum(1,1,n);
	build_max(1,1,n);

	fr(i,m){
		int op;
		cin >> op;
		if(op == 1){
			int l,r;
			cin >> l >> r;
			cout << query_sum(1,1,n,l,r) <<endl;
		}
		if(op == 2){
			int l,r,x;
			cin >> l >> r >> x;
			pll y = query_max(1,1,n,l,r);
			while(y.snd >= x){
				update_sum(1,1,n,y.fst,y.snd % x);
				update_max(1,1,n,y.fst,y.snd % x);
				y = query_max(1,1,n,l,r);
			}

		}
		if(op == 3){
			int id,val;
			cin >> id >> val;
			update_sum(1,1,n,id,val);
			update_max(1,1,n,id,val);
		}
	}

}
