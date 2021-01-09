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

struct st{
	ll pref,suf;
	
	ll ans;
	ll sum;
};

st seg[400400];

void update(int node,int l,int r,int i,int val){
	if(i < l ||i > r) return;

	if(l == r && l == i){
		seg[node].ans = max(0,val);
		seg[node].sum = val;
		seg[node].pref = seg[node].suf = seg[node].ans;
		return;
	}

	int m = (l+r)/2;
	update(2*node,l,m,i,val);
	update(2*node + 1,m+1,r,i,val);

	seg[node].sum = seg[2*node].sum + seg[2*node + 1].sum;
	seg[node].pref = max(seg[2*node].pref,seg[2*node].sum + seg[2*node + 1].pref);
	seg[node].suf = max(seg[2*node + 1].suf,seg[2*node + 1].sum + seg[2*node].suf);
	seg[node].ans = max(seg[2*node].suf + seg[2*node + 1].pref,max(seg[2*node].ans,seg[2*node + 1].ans));
}

int main(){

	fastio;
	int n,q;
	cin >> n >> q;

	frr(i,n){
		int a;
		cin >> a;
		update(1,1,n,i,a);
	}

	cout << seg[1].ans << endl;

	fr(i,q){
		int j,a;
		cin >> j >> a;
		j++;
		update(1,1,n,j,a);
		cout << seg[1].ans << endl;
	}
	

}
