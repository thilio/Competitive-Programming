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

int n;
ll h[300200];
ll b[300200];
int lft[300200];
ll dp[300200];

ll seg[1300300];

void update(int node, int l, int r, int pos, ll val){
	if(pos < l || pos > r) return;
	if(l == r){
		seg[node] = val;
		return;
	}

	int m = (l + r)/2;
	update(2*node, l , m, pos, val);
	update(2*node + 1, m + 1, r, pos, val);
	seg[node] = max(seg[2*node], seg[2*node + 1]);
}

ll query(int node, int l, int r, int a, int b){
	if(a > r || b < l) return -llINF;
	if(a <= l && r <= b) return seg[node];

	int m = (l + r)/2;

	return max(query(2*node,l , m, a ,b), query(2*node + 1, m + 1, r, a, b));
}

void pre(){
	stack<int> P;
	frr(i, n) dp[i] = -llINF;

	frr(i, n){
		while(!P.empty() && h[P.top()] > h[i]){
			P.pop();
		}
		if(P.empty()) lft[i] = 0;
		else lft[i] = P.top();
		P.push(i);
	}
}

int main(){

	fastio;

	cin >> n;

	frr(i, n) cin >> h[i];
	frr(i, n) cin >> b[i];

	pre();

	for(int i = 1; i <= n; i++){
		if(lft[i] != 0) dp[i] = dp[lft[i]];

		dp[i] = max(dp[i], query(1, 0, n, lft[i], i - 1) + b[i]);
		update(1,0,n,i,dp[i]);
	}

	cout << dp[n] << endl;

}
