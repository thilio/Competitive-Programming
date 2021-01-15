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

ll solve(ll n){
	if(n < 2) return 0;
	if(n == 2) return 1;

	ll l = 0;
	ll r = n;

	ll best = -1;

	while(l <= r){
		ll m = (l + r)/2;

		if(m*(3*m + 1) <= 2*n){
			best = m;
			l = m + 1;
		}
		else r = m-1;

	}

	return 1ll + solve(n - (best*(3*best + 1))/2);

}



int main(){

	fastio;
	int T;
	cin >> T;

	while(T--){
		ll n;
		cin >> n;
		cout << solve(n) << endl;
	}

}
