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
const ll MOD = 998244353;
const int N = 440; 

int c[30];
int n;
ll dp[2][N][N][3][3];
ll dp_res[N][N];
ll dp_sum[N][N];

int main(){

	fastio;

	cin >> n;
	fr(i, 26) cin >> c[i];

	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			for(int k = 0; k < 26; k++){
				if(i == k) continue;
				int zero = (i == 0) + (j == 0) + (k == 0);
				int one = (i == 1) + (j == 1) + (k == 1);
				dp[0][zero][one][min(2,j)][min(2,k)]++;
			}
		}
	}


	for(int i = 4; i <= n; i++){
		for(int j = 0; j <= i; j++){
			for(int k =0; k <= i; k++){
				for(int l = 0; l < 3; l++){
					for(int m = 0; m < 3; m++){
						ll & pdm = dp[1][j][k][l][m];
						pdm = 0;
						int zero = (l == 0) + (m == 0);
						int ones = (l == 1) + (m == 1);
						if(j < zero || k < ones) continue;
						for(int z = 0; z < 3; z++){
							if(z != m)
								pdm += dp[0][j - (m == 0? 1:0)][k - (m == 1? 1: 0)][z][l]*(m == 2? 24: 1);
							else if(z == 2){
								pdm += dp[0][j][k][z][l]*(23);
							}
							pdm %= MOD;
						}

					}
				}
			}
		}

		for(int j = 0; j <= i; j++){
			for(int k =0; k <= i; k++){
				for(int l = 0; l < 3; l++){
					for(int m = 0; m < 3; m++){
						dp[0][j][k][l][m] = dp[1][j][k][l][m];
						dp[1][j][k][l][m] = 0;
					}
				}
			}
		}
	}

	for(int j = 0; j <= n; j++){
		for(int k = 0; k <= n; k++){
			for(int l = 0; l < 3; l++){
				for(int m = 0; m < 3; m++){
					dp_res[j][k] += dp[0][j][k][l][m];
					dp_res[j][k] %= MOD;
				}
			}
		}
	}

	for(int j = 0; j <= n; j++){
		for(int k = 0; k <= n; k++){
			dp_sum[j][k] = dp_res[j][k];
			if(j != 0) dp_sum[j][k] += dp_sum[j - 1][k];
			if(k != 0) dp_sum[j][k] += dp_sum[j][k - 1];
			dp_sum[j][k] %= MOD;
			dp_sum[j][k] += 3*MOD;
			if(j != 0 && k != 0) dp_sum[j][k] -= dp_sum[j - 1][k - 1];
			dp_sum[j][k] %= MOD;
		}
	}

	ll ans = dp_sum[n][n];

	for(int j = 0; j < 26; j++){
		ll quebra_j = MOD + dp_sum[n][n] - dp_sum[c[j]][n];
		ans += 3*MOD - quebra_j;
		ans %= MOD;
		for(int k = j + 1; k < 26; k++){
			ll quebra_jk = 2*MOD + dp_sum[n][n] - dp_sum[c[j]][n] - dp_sum[n][c[k]] + dp_sum[c[j]][c[k]];
			ans = ans + quebra_jk;
			ans %= MOD;
		}
	}

	cout << ans << endl;





}
