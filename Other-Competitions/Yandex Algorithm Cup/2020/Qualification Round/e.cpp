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

ll v[200200];
ll seg[800800];

ll mapa[200200];

vector<pll> vv;

void update(int node,int l,int r,int pos,int val){
	if(pos < l || pos > r) return;
	if(l == r && pos == l){
		seg[node] = val;
		return;
	}

	int m = (l + r)/2;

	update(2*node,l,m,pos,val);
	update(2*node + 1,m + 1,r,pos,val);

	seg[node] = seg[2*node] + seg[2*node + 1];
 }

 ll query(int node,int l,int r,int a,int b){
 	if(b < l || a > r) return 0;
 	if(a <= l && r <= b){
 		return seg[node];
 	}

 	int m = (l + r)/2;

 	return query(2*node,l,m,a,b) + query(2*node + 1,m + 1,r,a,b);
 }

int main(){

	fastio;

	int n;
	cin >> n;

	frr(i,n){
		cin >> v[i];
		vv.pb(mp(v[i],i));
	}

	sort(all(vv));

	for(int  i = 0; i < vv.size(); i++){
		mapa[vv[i].snd] = i + 1; 
	}



	ll ans = 0;

	frr(i,n){
		ans += query(1,1,n,mapa[i],n);
		cout << ans << ' ';
		update(1,1,n,mapa[i],v[i]);
	}

	gnl;

}
