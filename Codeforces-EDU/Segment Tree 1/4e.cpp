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
int n,q;
int ct;

void update(int node,int l,int r,int i ,int val){
	if(i < l || i > r) return;
	if(l == r && i == l){
		seg[node] = val;
		return;
	}

	int m = (l + r)/2;
	update(2*node,l,m,i,val);
	update(2*node + 1,m+1,r,i,val);

	seg[node] = min(seg[2*node],seg[2*node + 1]);
}

void query(int node,int l,int r,int a,int b,int p){
	if(r < a || l > b) return;
	if(l == r){
		if(seg[node] <= p){
			ct++;
			seg[node] = INF;
		}
		return;
	}

	int m = (l + r)/2;

	if(seg[2*node] <= p) query(2*node,l,m,a,b,p);
	if(seg[2*node + 1] <= p) query(2*node + 1,m+1,r,a,b,p);

	seg[node] = min(seg[2*node],seg[2*node + 1]);
}

int main(){

	fastio;

	cin >> n >> q;

	frr(i,n) update(1,1,n,i,INF);

	fr(i,q){
		int op;
		cin >> op;

		if(op == 1){
			int j,h;
			cin >> j >> h;
			j++;
			update(1,1,n,j,h);
		}
		if(op == 2){
			int a,b,p;
			cin >> a >> b >> p;
			a++;

			ct = 0;
			query(1,1,n,a,b,p);

			cout << ct << endl;
		}
	}

}
