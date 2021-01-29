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
int m,n;
pii v[100100];
int id[100100];
int sz[100100];

int find(int p){
	if(p == id[p]) return p;
	return (id[p] = find(id[p]));
}

int un (int p,int q){
	p = find(p);
	q = find(q);
	if(p == q) return 0;
	if(sz[p] > sz[q]) swap(p,q);
	id[p] = q;
	sz[q] += sz[p];
	return 1;
}

int main(){

	fastio;
	cin >> n >> m;
	frr(i,m){
		cin >> v[i].fst >> v[i].snd;
	}

	frr(i,n){
		id[i] = i;
		sz[i] = 1;
	}

	int q;
	cin >> q;

	int res = n;

	set<int> s;
	vi ac;
	fr(i,q){
		int a;
		cin >> a;
		s.insert(a);
		ac.pb(a);
	}

	frr(i,m){
		if(s.find(i) == s.end()){
			res -= un(v[i].fst,v[i].snd);
		}
	}

	//dbg(res);

	vi ans;
	ans.pb(res);

	reverse(all(ac));

	fr(i,q-1){
		int at = ac[i];
		res -= un(v[at].fst,v[at].snd);
		ans.pb(res);
	}

	reverse(all(ans));



	fr(i,q){
		cout << ans[i] << ' ';
	}

	gnl;




}
