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

int seg[400400];
int v[100100];
void update(int node,int l,int r,int i,int val){
	if(i < l || i > r) return;
	if(l == r && l == i){
		seg[node] = val;
		return;
	}

	int m = (l+r)/2;

	update(2*node,l,m,i,val);
	update(2*node+1,m+1,r,i,val);

	seg[node] = seg[2*node] + seg[2*node + 1];
}

int query(int node,int l,int r,int x){
	if(l == r) return l;

	int m = (l + r)/2;

	if(seg[2*node + 1] > x) return query(2*node + 1,m+1,r,x);
	return query(2*node,l,m,x - seg[2*node + 1]);

}

int main(){

	fastio;

	int n;
	cin >> n;

	vi ans;

	frr(i,n){
		cin >> v[i];
		update(1,1,n,i,1);
	}

	for(int i = n ; i > 0; i--){
		int x = v[i];
		int k = query(1,1,n,x);
		ans.pb(k);
		update(1,1,n,k,0);
	}
	reverse(all(ans));

	fr(i,n) {
		cout << ans[i] << ' ';
	}
	gnl;

}
