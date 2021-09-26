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
const int MOD = 998244353;

ll pot[2000200];

ll fast(ll b, ll e){
	if(e == 0) return 1;
	ll ans = fast(b, e/2);
	ans = (ans*ans)%MOD;
	if(e&1) ans = (ans*b)%MOD;
	return ans;
}

ll sum(ll l, ll r){
	if(l > r) return 0;

	ll a = pot[r + 1] - 1;
	ll b = pot[l] - 1;

	return (a - b + MOD)%MOD;
}

int main(){

	fastio;

	ll n, d;
	cin >> n >> d;
	n--;

	ll inv2 = fast(2, MOD - 2);

	pot[0] = 1;
	frr(i, 2000100) pot[i] = (pot[i - 1]*2ll)%MOD;

	ll ans = 0;

	for(int i = 0; i <= d/2; i++){
		ll termo = 0;
		if(i == 0){
			termo = sum(d, n);
		}
		else{
			termo += sum(d - 1, n + i - 1);
		}
		if(2*i == d){
			termo = (termo*inv2)%MOD;
		}

		ans = (termo + ans)%MOD;
	}
	ans = (ans*2)%MOD;
	cout << ans << endl;



}
