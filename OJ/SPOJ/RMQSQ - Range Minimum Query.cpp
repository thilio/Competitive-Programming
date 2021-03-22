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

const int N = 200100;
const int LOGN = 20;

int lg[N];
int st[N][LOGN];
int v[N];
int n, q;

void build(){
	lg[1] = 0;
	for(int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

	for(int i = 0; i < n; i++) st[i][0] = v[i];

	for(int j = 1; j <= lg[n]; j++){
		for(int i = 0; i + (1 << j) <= n; i++){
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r){ // minimum element in v[l, ..., r] 
	int j = lg[r - l + 1];
	return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main(){
	fastio;
	
	cin >> n;

	for(int i = 0; i < n; i++) cin >> v[i];
	build();

	cin >> q;

	fr(i,q){
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}

}
