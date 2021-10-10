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

int n;

ll dp[4000][4000];
int a[4000];
int b[4000];

ll range(int i, int l, int r){
	if(l > r) return 0;
	ll ans = dp[i][r];
	//dbg(ans);
	if(l != 0) ans = (ans - dp[i][l - 1] + MOD)%MOD;
	return ans;
}

int main(){

	fastio;

	cin >> n;

	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];

	for(int i = a[n - 1]; i <= b[n - 1]; i++){
		dp[n - 1][i] = 1;
	}
	for(int i = 1; i <= 3000; i++){
		dp[n - 1][i] = (dp[n - 1][i - 1] + dp[n - 1][i])%MOD;
	}

	for(int i = n - 2; i >= 0; i--){
		for(int j = a[i]; j <= b[i]; j++){
			dp[i][j] = range(i + 1, max(j, a[i + 1]), b[i + 1]);
			//dbg(dp[i][j]);
		}

		for(int j = 1; j <= 3000; j++){
			dp[i][j] = (dp[i][j] + dp[i][j - 1])%MOD;
		}
	}

	cout << dp[0][3000] << endl;


}
