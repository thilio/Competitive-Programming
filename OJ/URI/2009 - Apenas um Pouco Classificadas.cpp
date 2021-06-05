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

ll n, q;

ll dp[5050][5050];

void pd(){
	dp[1][0] = 1;

	for(int i = 2; i <= n; i++){
		for(int k = 0; k < i; k++){
			dp[i][k] = (k + 1)*dp[i - 1][k];
			if(k > 0) dp[i][k] += (i - k)*dp[i - 1][k - 1];
			dp[i][k] %= MOD;
		}
	}
}

int main(){

	fastio;
	cin >> n >> q;
	pd();

	frr(j, q){
		int x;
		cin >> x;
		x = min(5000, x);
		ll ans = 0;
		fr(i, x){
			ans += dp[n][i];
			ans %= MOD;
		}
		cout << ans;
		if(j != q) cout << ' ';
	}
	gnl;
}
