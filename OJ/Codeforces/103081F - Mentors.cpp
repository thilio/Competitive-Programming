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

ll r, n, MOD;
ll dp[2040][2040];

ll pd(){
	dp[1][1] = 1;

	for(int i = 2; i <= r; i++){
		for(ll a = 1; a <= i; a++){
			ll b = i + 1 - 2*a;
			if(b < 0) continue;
			dp[i][a] = a*dp[i - 1][a];
			dp[i][a] += (b + 1)*dp[i - 1][a - 1];
			dp[i][a] %= MOD;
		}
	}

	for(int i = r + 1; i <= n; i++){
		for(ll a = 1; a <= i; a++){
			ll b = i + 1 - 2*a;
			if(b < 0) continue;
			dp[i][a] = (a - 1)*dp[i - 1][a];
			dp[i][a] += (b + 1)*dp[i - 1][a - 1];
			dp[i][a] %= MOD;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans = (dp[n][i] + ans)%MOD;
	}
	return ans;

}

int main(){

	fastio;
	cin >> r >> n >> MOD;
	r = n + 1 - r;
	//MOD = INF;
	cout << pd() << endl;
}
