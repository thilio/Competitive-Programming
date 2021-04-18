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
vi filhos[200200];
ll v[200100],aux[400400];
ll seg[1800800],lazy[1800800];
map<int,pii> m;

int t = 1;

void dfs(int v){
	m[v].fst = t++;
	for(auto x : filhos[v]){
		dfs(x);
	}
	m[v].snd = t++;
}

void unlazy(int node,ll l,ll r){
	if(lazy[node]%2 == 0) return;
	seg[node] = ((r - l)+1) - seg[node];
	if(l!=r){
		lazy[2*node] += 1;
		lazy[2*node + 1] += 1;
	}

	lazy[node] = 0;
}

void build(int node,int l,int r){
	if(l==r){
		seg[node] = aux[l];
		return;
	}

	int lc = 2*node;int rc= lc + 1;
	int mid = (l+r)/2;
	build(lc,l,mid);
	build(rc,mid+1,r);

	seg[node] = seg[lc] + seg[rc];
}

void update(int node,ll l,ll r,int a,int b){
	int lc = 2*node;int rc = lc + 1;int mid = (l+r)/2;
	unlazy(node,l,r);

	if(r < a || b < l || l > r) return;

	if(l>=a && r <= b){
		seg[node] = ((r - l)+1) - seg[node];
		if(l!=r){
			lazy[lc]++;
			lazy[rc]++;
		}
	}

	else{
		update(lc,l,mid,a,b);
		update(rc,mid+1,r,a,b);
		seg[node] = seg[lc] + seg[rc];
	}
}

ll query (int node,int l,int r,int a,int b){
	int lc = 2*node;int rc = lc+1;int mid = (l+r)/2;
	unlazy(node,l,r);

	if(r < a || b < l || l > r) return 0ll ;

	if (l >= a && r <= b) return seg[node];

	return (query(lc,l,mid,a,b) + query(rc,mid+1,r,a,b));

}



int main(){

	fastio;
	int n;
	cin >> n;
	fr(i,n-1){
		int a;
		cin >> a;
		filhos[a].pb(i+2);
	}

	frr(i,n){
		cin >> v[i];
	}


	dfs(1);


	frr(i,n){
		if(v[i] == 1){
			aux[m[i].fst]++;
			aux[m[i].snd]++;
		}
	}

	build(1,1,2*n);
	int q;
	cin >> q;
	fr(i,q){
		string s;
		cin >> s;
		int a;
		cin >> a;
		if(s[0]=='g'){
			cout << query(1,1,2*n,m[a].fst,m[a].snd)/2<<endl;
		}
		else{
			update(1,1,2*n,m[a].fst,m[a].snd);
		}
	}



}
