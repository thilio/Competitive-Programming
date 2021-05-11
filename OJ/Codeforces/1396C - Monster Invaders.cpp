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

ll n, r1,r2,r3, d;
ll a[1000100];

ll memo[1000100][2];

ll dp(int i, int b){
	ll &pdm = memo[i][b];
	if(pdm != -1) return pdm;

	if(i == n){
		if(b == 0){
			ll aa = (a[i] + 1)*r1 + 2*d + r1;
			ll bb = a[i]*r1 + r3;
			ll cc = r2 + 2*d + r1;
			pdm = min(aa, min(bb, cc));
		}
		if(b == 1){
			ll aa = (a[i] + 1)*r1 + r1 + r1 + 2*d;
			ll bb = r2 + r1 + r1 + 2*d;
			ll cc = a[i]*r1 + r3 + d + r1;
			pdm = min(min(aa, bb), cc);
		}
		return pdm;

	}

	if(b == 0){
		ll aa = (a[i] + 1)*r1 + dp(i + 1, 1);
		ll bb = a[i]*r1 + r3 + dp(i + 1, 0);
		ll cc = r2 + dp(i + 1, 1);
		pdm = min(aa, min(bb, cc)) + d;
	}
	if(b == 1){
		ll aa = (a[i] + 1)*r1 + r1 + r1 + 2*d + dp(i + 1, 0);
		ll bb = r2 + r1 + r1 + 2*d + dp(i + 1, 0);
		pdm = min(aa, bb) + d;
	}

	return pdm;
}

int main(){

	fastio;

	cin >> n >> r1 >> r2 >> r3 >> d;
	frr(i, n) cin >> a[i];
	ms(memo, -1);

	cout <<	dp(1, 0) << endl;


}
