#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ran(int N){
	return uniform_int_distribution<int>(1, N)(rng);
}

ll v[200200];
int n;

ll tent(ll x){
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] < x) ans += x - v[i];
		else ans += min(v[i]%x, x - v[i]%x); 
		
	}
	return ans;
}

ll go2(ll k){
	if(k == 0 || k == 1) return llINF;

	ll ans = tent(k);
	for(ll i = 2; i*i <= k; i++){
		if(k%i == 0){
			ans = min(tent(i), ans);
		}
		while(k%i == 0) k /= i;
	}
	if(k != 1) ans = min(ans, tent(k));
	return ans;
}

ll go(int i){
	ll a = go2(v[i] - 1);
	ll b = go2(v[i]);
	ll c = go2(v[i] + 1);

	return min(a, min(b, c));
}

int main(){

	fastio;
	cin >> n;

	frr(i, n) cin >> v[i];

	//dbg(tent(3));


	ll ans = INF;
	frr(i, 20){
		int x = ran(n);
		ans = min(ans, go(x));
		//if(go(x) == 0) dbg(x);
	}

	cout << ans << endl;
}
