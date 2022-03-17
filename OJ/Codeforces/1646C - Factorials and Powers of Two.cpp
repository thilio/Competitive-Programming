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

ll fat[20];
ll pot[60];

ll solve(ll n, ll mf){	

	ll ans = __builtin_popcountll(n);

	for(int j = mf + 1; fat[j] <= n; j++){
		ans = min(ans, solve(n - fat[j], j) + 1);
	}

	return ans;
}

int main(){

	fastio;

	int T;
	cin >> T;

	fat[0] = 1;
	for(ll i = 1; i <= 15; i++) fat[i] = i*fat[i - 1];
	for(ll i = 0; i <= 50; i++) pot[i] = 1ll << i;

	while(T--){
		ll n;
		cin >> n;

		cout << solve(n, -1) << endl;
	}

}
