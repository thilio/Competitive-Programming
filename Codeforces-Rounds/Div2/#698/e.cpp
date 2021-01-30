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

vii perg;
int seg[800800];
int lazy[800800];

void unlazy(int node,int l,int r){
	if(lazy[node] == -1) return;
	if(l != r){
		lazy[2*node] = lazy[node];
		lazy[2*node + 1] = lazy[node]; 
	}
	if(lazy[node] == 0){
		seg[node] = 0;
	}
	else{
		seg[node] = (r - l  + 1);
	}

	lazy[node] = -1;

}

void update(int node,int l,int r,int a,int b,int val){
	unlazy(node,l,r);

	if(b < l || a > r) return;
	if(a <= l && r <= b){
		lazy[node] = val;
		unlazy(node,l,r);
		return;
	}

	int m = (l + r)/2;
	update(2*node,l,m,a,b,val);
	update(2*node + 1,m + 1,r,a,b,val);

	seg[node] = seg[2*node] + seg[2*node + 1];
}

int query(int node,int l,int r,int a,int b){
	unlazy(node,l,r);

	if(b < l || a > r) return 0;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;

	return query(2*node,l,m,a,b) + query(2*node + 1,m + 1,r,a,b);
}


int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n,q;
		cin >> n >> q;

		string s,f;
		getline(cin,s);
		getline(cin,s);
		getline(cin,f); 


		perg.clear();
		frr(i,q){
			int a,b;
			cin >> a >> b;
			perg.pb(mp(a,b));
		}
		reverse(all(perg));

		frr(i,4*n) lazy[i] = -1;
		update(1,1,n,1,n,0);

		fr(i,n){
			if(f[i] == '1'){
				update(1,1,n,i + 1,i + 1,1);
			}
		}

		bool ok = true;

		for(auto x : perg){
			
			
			int sz = x.snd - x.fst + 1;
			int soma = query(1,1,n,x.fst,x.snd);
			
			if(2*soma == sz) ok = false;
			if(2*soma < sz){
				update(1,1,n,x.fst,x.snd,0);
			}
			if(2*soma > sz){
				update(1,1,n,x.fst,x.snd,1);
			}

		}

		fr(i,n){
			int x = query(1,1,n,i+1,i+1);
			char c = '0' + x;
			if(c != s[i]) ok = false;
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

}
