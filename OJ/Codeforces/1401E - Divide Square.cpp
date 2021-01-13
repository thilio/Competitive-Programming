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

int seg[4004040];
int n,m;
vector<pair<int,pii>> hori;
vector<pii> vertup;
vector<pii> vertdown;

void update(int node,int l,int r,int j ,int val){
	if(j < l || j > r) return;
	if(l == r){
		seg[node] += val;
		return;
	}
	int m = (l + r)/2;
	update(2*node,l,m,j,val);
	update(2*node + 1,m + 1,r,j,val);

	seg[node] = seg[2*node] + seg[2*node + 1];
}

int query(int node,int l,int r,int a,int b){
	if(b < l ||a > r) return 0;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;
	return query(2*node,l,m,a,b) + query(2*node + 1,m + 1,r,a,b);
}

int main(){

	fastio;
	cin >> n >> m;

	ll ans = 1;

	fr(i,n){
		pair<int,pii> aux;
		cin >> aux.fst >> aux.snd.fst >> aux.snd.snd;
		hori.pb(aux); 
		if(aux.snd.fst == 0 && aux.snd.snd == 1000000) ans++;
	}

	sort(all(hori));

	fr(i,m){
		int x,l,r;
		cin >> x >> l >> r;

		if(l == 0){
			pii aux;
			aux.fst = r;
			aux.snd = x;
			vertup.pb(aux);
		}
		else{
			pii aux;
			aux.fst = l;
			aux.snd = x;
			vertdown.pb(aux);
		}

		if(l == 0 && r == 1000000) ans++;
	}

	sort(all(vertup));
	sort(all(vertdown));
	reverse(all(vertdown));
	int k = 0;
	

	for(auto x: vertup){
		while(k < n && hori[k].fst <= x.fst){
			update(1,0,1000000,hori[k].snd.fst, 1);
			if(hori[k].snd.snd < 1000000){
				update(1,0,1000000,hori[k].snd.snd + 1, -1);
			}
			k++;
		}

		ans += query(1,0,1000000, 0, x.snd);
	}

	for(int i = 0; i < 4004040; i++) seg[i] = 0;

	reverse(all(hori));
	k = 0;
	for(auto x: vertdown){
		while(k < n && hori[k].fst >= x.fst){
			update(1,0,1000000,hori[k].snd.fst, 1);
			if(hori[k].snd.snd < 1000000){
				update(1,0,1000000,hori[k].snd.snd + 1, -1);
			}
			k++;
		}

		ans += query(1,0,1000000, 0, x.snd);
	}

	cout << ans << endl;
}
