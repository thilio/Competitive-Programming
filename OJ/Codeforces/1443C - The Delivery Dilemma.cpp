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
ll a[200200];
ll b[200200];

bool ok (ll x){
	ll sum = 0;

	fr(i,n){
		if(a[i] > x) sum += b[i];
	}

	if(sum <= x) return true;
	return false;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;

		fr(i,n) cin >> a[i];
		fr(i,n) cin >> b[i];

		ll l = 1;
		ll r = MOD;

		ll best = -1;

		while(l <= r){
			ll m = (l + r)/2;

			if(ok(m)){
				best = m;
				r = m - 1;
			}
			else l = m + 1;
		}

		cout << best << endl;
	}

}
