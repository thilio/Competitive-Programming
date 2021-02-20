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

ll n,m,q;
pair<ll,ll> v[100100][2];
ll cidade[100100];
pair<ll,ll> update[100100];

vector<ll> comp;
map<ll,ll> m_comp;

struct segtree{
	int seg[4000400];

	segtree(){};

	void init(int tam){
		fr(i, 4*tam + 4){
			seg[i] = 0;
		}
	}

	void update(int node, int l, int r,int pos){
		if(pos < l || pos > r) return;
		if(l == r){
			seg[node]++;
			return;
		}
		int m = (l + r)/2;
		update(2*node,l,m,pos);
		update(2*node + 1, m + 1, r, pos);
		seg[node] = seg[2*node] + seg[2*node + 1];
	}

	int query(int node, int l,int r,int a,int b){
		if(b < l || a > r) return 0;
		if(a <= l &&  r <= b) return seg[node];

		int m = (l + r)/2;

		return query(2*node,l,m,a,b) + query(2*node + 1,m + 1,r,a,b);
	}

};
struct segtree ini[2], fim[2];

int read(){
	comp.clear();
	m_comp.clear();

	cin >> n;

	fr(i,n){
		cin >> v[i][0].fst >> v[i][0].snd;
		comp.pb(v[i][0].fst);
		comp.pb(v[i][0].snd);
	}

	cin >> m;
	fr(i,m){
		cin >> v[i][1].fst >> v[i][1].snd;
		comp.pb(v[i][1].fst);
		comp.pb(v[i][1].snd);
	}

	cin >> q;
	fr(i,q){
		int cid;
		int x,y;

		cin >> cid >> x >> y;
		cidade[i] = cid - 1;
		update[i] = mp(x,y);
		comp.pb(x);
		comp.pb(y);
	}

	sort(all(comp));

	int ct = 1;
	for(auto x : comp){
		if(!m_comp.count(x)){
			m_comp[x] = ct++;
		}
	}

	fr(i,n){
		v[i][0].fst = m_comp[v[i][0].fst];
		v[i][0].snd = m_comp[v[i][0].snd];
	}
	fr(i,m){
		v[i][1].fst = m_comp[v[i][1].fst];
		v[i][1].snd = m_comp[v[i][1].snd];
	}
	fr(i,q){
		update[i].fst = m_comp[update[i].fst];
		update[i].snd = m_comp[update[i].snd];
	}

	return ct;

}
int main(){

	fastio;
	int T;
	cin >> T;
	int caso = 1;

	while(T--){
		int sz = read();
		ini[0].init(sz);
		ini[1].init(sz);
		fim[0].init(sz);
		fim[1].init(sz);

		ll ans = n*m;

		//dbg(ans);

		fr(i,n){
			ini[0].update(1,0,sz,v[i][0].fst);
			fim[0].update(1,0,sz,v[i][0].snd);
		}

		fr(i,m){
			pii at = v[i][1];
			int q1 = fim[0].query(1,0,sz,0, at.fst - 1);
			int q2 = ini[0].query(1,0,sz, at.snd + 1, sz);
			ini[1].update(1,0,sz,v[i][1].fst);
			fim[1].update(1,0,sz,v[i][1].snd);
			ans -= q1;
			ans -= q2;

		}
		cout << "Case " << caso++ << ": ";
		cout << ans << endl;

		fr(i,q){
			int cid = cidade[i];

			if(cid == 0) ans += m;
			else ans += n;
			if(cid == 0) n++;
			else m++;

			pll at = update[i];

			int q1 = fim[1 - cid].query(1,0,sz,0, at.fst - 1);
			int q2 = ini[1 - cid].query(1,0,sz, at.snd + 1, sz);

			ans -= q1;
			ans -= q2;

			ini[cid].update(1,0,sz,at.fst);
			fim[cid].update(1,0,sz,at.snd);
			cout << ans << endl;
		}


	}

}
