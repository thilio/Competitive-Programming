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

long double dp[2][102][10002];
int n;
int a[110];
int b[110];
long double soma;

void pd(){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 102; j++){
			for(int k = 0; k < 10002; k++){
				dp[i][j][k] = -INF;
			}
		}
	}

	dp[1][1][a[n - 1]] = b[n - 1];
	

	dp[1][0][0] = 0;

	for(int i = n - 2; i >= 0; i--){
		for(int k = 0; k <= n; k++){
			for(int cap = 0; cap <= 10000; cap++){
				long double &pdm = dp[0][k][cap];
				pdm = dp[1][k][cap];
				if(a[i] <= cap) pdm = max(pdm, b[i] + dp[1][k - 1][cap - a[i]]);
			}
		}
		for(int k = 0; k <= n; k++){
			for(int cap = 0; cap <= 10000; cap++){
				dp[1][k][cap] = dp[0][k][cap];
			}
		}
	}
}

int main(){

	fastio;
	cin >> n;

	cout << setprecision(12) << fixed;

	fr(i, n) cin >> a[i] >> b[i];
	fr(i, n) soma += b[i];

	pd();

	frr(i, n){
		long double best = 0;

		for(int cap = 1; cap <= 10000; cap++){
			long double tem = dp[1][i][cap];
			if(tem < 0) continue;
			best = max(best, min((long double)cap, tem + 0.5*(soma - tem)));
		}
		cout << best << ' ';
	}
	gnl;


}
