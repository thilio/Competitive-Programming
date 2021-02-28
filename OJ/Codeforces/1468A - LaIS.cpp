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

vi nxt[500200];
int n;
int v[5005000];
int seg[2000200];

int dp[500200];

void reset(){
	fr(i,n + 3){
		nxt[i].clear();
		v[i] = 0;
		dp[i] = 0;
	}

	frr(i,4*n + 6) seg[i] = 0;

}

void next(){
	stack<int> P;
	while(!P.empty()) P.pop();

	fr(i,n){
		while(!P.empty() && v[i] >= v[P.top()]) P.pop();
		if(!P.empty()) nxt[P.top()].pb(i);
		P.push(i);
	}
}

void update(int node,int l,int r,int pos,int val){
	if(pos < l || pos > r) return;
	if(l == r){
		seg[node] = val;
		return;
	}

	int m = (l + r)/2;
	update(2*node,l,m,pos,val);
	update(2*node + 1,m + 1,r,pos,val);

	seg[node] = max(seg[2*node], seg[2*node + 1]);
}

int query(int node,int l,int r,int a,int b){
	if(b < l || a > r) return 0;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;

	int q1 = query(2*node,l,m,a,b);
	int q2 = query(2*node + 1, m + 1, r,a,b);

	return max(q1,q2); 
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		reset();

		fr(i,n){
			cin >> v[i];
		}
		next();

		fr(i,n){
			for(auto x: nxt[i]){
				dp[x] = max(dp[x], query(1,1,n,1,v[x]) + 2);
			}

			dp[i] = max(dp[i], query(1,1,n,1,v[i]) + 1);
		//	dbg(dp[i]);
			update(1,1,n,v[i],dp[i]);
		}



		cout << query(1,1,n,1,n) << endl;
	}

}
