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
int n,m;
int sz[100100],id[100100];
int f[100100];
vi are;

int find(int p){
	if(id[p] == p) return p;
	return id[p] = find(id[p]);
}

int merge(int p,int q){
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
	pii ed[100100];
	vii are;

	frr(i,m){
		cin >> ed[i].fst >> ed[i].snd;
	}
	int q;
	cin >> q;

	fr(i,q){
		int a;
		cin >> a;
		are.pb(ed[a]);
		f[a] = 1;
	}
	reverse(all(are));

	frr(i,n){
		sz[i] = 1;
		id[i] = i;
	}

	int ans = n;

	frr(i,m){
		if(!f[i])
			ans -= merge(ed[i].fst,ed[i].snd);
	}

	vi res;
	res.pb(ans);
	fr(i,are.size() -1){
		ans -= merge(are[i].fst,are[i].snd);
		res.pb(ans);	
	}



	reverse(all(res));

	fr(i,res.size())
		cout <<res[i]<<' ';

	gnl;
}
