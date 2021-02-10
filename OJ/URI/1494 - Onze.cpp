#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(ll i=0;i<n;i++)
#define frr(i,n)	for(ll  i=1;i<=n;i++)

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
ll n;
ll k;
ll freq[10];
ll dp[200][200][13]; // dp[i][j][r]: # de maneiras de colocar i em posições pares, j em ímpares e deixar resto r
ll fat[1010];
ll fatinv[1010];


ll fast(ll base, ll exp){
	if(exp == 0) return 1;
	ll ans = fast(base,exp/2);
	ans = (ans*ans)%MOD;
	if(exp&1) ans = (ans*base)%MOD;
	return ans;
}

ll invmod(ll a){
	return fast(a,MOD - 2);
}

void fact(){
	fat[0] = 1;
	for(ll i = 1; i <= 1000; i++){
		fat[i] = (i*fat[i - 1])%MOD;
	}
	for(ll i = 0; i <= 1000; i++) fatinv[i] = fast(fat[i], MOD - 2); 
}

ll bin(ll a,ll b){
	if(a < b) return 0;
	ll ans = fat[a];
	ans = (ans*(fatinv[b]))%MOD;
	ans = (ans*(fatinv[a - b]))%MOD;
	return ans;
}


ll go(int aa){
	ms(dp,0);

	dp[0][0][0] = 1ll;

	int npar = n/2;
	int nimp = (n + 1)/2;
	int tot = 0;

	for(int d = 0; d < 10; d++){
		if(freq[d] == 0) continue;

		for(int i = 0; i <= tot; i++){
			int j = tot - i;
			for(int r = 0; r < 11; r++){
				for(int l = 0; l <= freq[d]; l++){
					ll &aux = dp[i + l][j + freq[d] - l][(r - l*d + (freq[d] - l)*d + 100*11)%11];
					aux += ((bin(npar - i,l)*bin(nimp - j, freq[d] - l)%MOD)*dp[i][j][r])%MOD;
					aux %= MOD;
				}
			}
		}

		tot += freq[d];
	}
	

	if(n%2 == 1) return dp[npar][nimp][aa];
	else return dp[npar][nimp][11 - aa];
}

int main(){

	fastio;
	string s;
	fact();

	while(cin >> s){
		fr(i,10) freq[i] = 0;
		n = s.size();

		fr(i,n){
			freq[s[i] - '0']++;
		}

		ll ans = 0;
		n--;

		for(int i = 1;i <= 9; i++){
			if(freq[i] > 0){
				freq[i]--;
				ans = (ans + go(i))%MOD;
				freq[i]++;
			}
		}

		cout << ans << endl;
	}

}
