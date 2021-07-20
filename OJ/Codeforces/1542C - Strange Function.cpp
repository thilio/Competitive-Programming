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

ll mmc(ll a, ll b){
	return a*b/__gcd(a, b);
}
ll divi(ll a, ll n){
	return n/a;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;

		ll m = 1;
		ll ans = 0;
		for(ll i = 2; i <= 100; i++){
			ll d_mmc = divi(m, n);
			m = mmc(m, i);
			ll d_eu = divi(m, n);

			ll term = (d_mmc - d_eu)*i;
			ans = (ans + term)%MOD;
		}

		cout << ans << endl;
	}

}
