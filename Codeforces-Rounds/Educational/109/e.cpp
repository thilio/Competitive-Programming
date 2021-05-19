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
const int MOD = 998244353;

int n, m;

vector<ll> p[100100];

ll fast(ll b, ll e){
	if(e == 0) return 1;
	ll ans = fast(b, e/2);
	ans = (ans*ans)%MOD;
	if(e&1) ans = (ans*b)%MOD;
	return ans;
}

ll inv(ll a){
	return fast(a, MOD - 2);
}

ll solve(int j){
	ll prob = 1;
	for(int i = 0; i < n; i++){
		//if(p[j][i] > n) continue;
		ll termo = (p[j][i] - 1 - i);
		if(termo <= 0) return 1;
		termo = (termo*inv(n - i))%MOD;
		//dbg(termo);
		//dbg(n - i);
		prob = (prob*termo)%MOD;
	}
	return 1 - prob + MOD;
}

int main(){

	fastio;
	cin >> n >> m;

	fr(i, n){
		fr(j, m){
			int x;
			cin >> x;
			p[j].pb(x);
		}
	}

	fr(j, m) sort(all(p[j]));

	ll ans = 0;

	//dbg(inv(3));

	fr(j, m){
		ans = (ans + solve(j))%MOD;
		//dbg(solve(j));
		//dbg(ans);
	}

	cout << ans << endl;
}
