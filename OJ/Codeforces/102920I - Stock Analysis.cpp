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
typedef tuple<ll,ll,ll,ll> tup;

const int INF = 0x3f3f3f3f;
const ll llINF = 1e18;
const int MOD = 1e9+7;
const int N = 2020;

ll bit[N][N];
ll v[N];

void update(int x, int y, ll v){
	for(int i = x; i < N; i += (i&-i)){
		for(int j = y; j < N; j += (j&-j)){
			bit[i][j] = max(bit[i][j], v);
		}
	}
}

ll query(int x, int y){
	ll a = -llINF;
	for(int i = x; i > 0; i -= (i&-i)){
		for(int j = y; j > 0; j -=(j&-j)){
			a = max(a, bit[i][j]);
		}
	}
	return a;
}

vector<tup> ev;

ll ans[200200];

int main(){

	fastio;

	int n,q;
	cin >> n >> q;
	frr(i,n) cin >> v[i];

	frr(i,n){
		ll soma = 0;
		for(int j = i; j <= n; j++){
			soma += v[j];
			ev.pb({soma, 0, i, j});
		}
	}

	frr(i,q){
		ll l,r,u;
		cin >> l >> r >> u;
		ev.pb({u,i,l,r});
	}

	sort(all(ev));


	fr(i,N) fr(j, N) bit[i][j] = -llINF;

	for(auto x: ev){
		ll sum, type, l, r;
		tie(sum, type, l , r) = x;

		//if(sum == 8) dbg(query(N - 2 ,5)); 

		if(type == 0){
			update(n - l + 1, r, sum);
		}
		else{
			ans[type] = query(n - l + 1, r);
		}
	}


	frr(i,q){
		if(ans[i] == -llINF) cout << "NONE" << endl;
		else cout << ans[i] << endl;
	}



}
