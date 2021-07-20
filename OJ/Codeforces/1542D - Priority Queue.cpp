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
const int MOD = 998244353;

ll v[1010];
int n;
int j;
ll memo[600][600];


void dp_pre(){

	for(int i = 0; i < 600; i++){
		memo[0][i] = 0;
	}
	memo[0][0] = 1;

	for(int i = 1; i < j; i++){
		for(int k = 0; k < 600; k++){
			if(k > i){
				memo[i][k] = 0;
				continue;
			} 
			memo[i][k] = memo[i - 1][k];
			if(v[i] < 0){
				memo[i][k] = (memo[i][k] + memo[i - 1][k + 1])%MOD;
				if(k == 0) memo[i][k] = (memo[i][k] + memo[i - 1][k])%MOD;
			}
			else if(v[i] <= v[j]){
				if(k != 0) memo[i][k] = (memo[i][k] + memo[i - 1][k - 1])%MOD;
			}
			else{
				memo[i][k] = (memo[i][k] + memo[i - 1][k])%MOD; 
			}
		}
	}

}

ll dp_pos(int ind, int men){
	if(ind == n + 1){
		return 1;
	}

	ll& pdm = memo[ind][men];
	if(pdm != -1) return pdm;

	pdm = 0;
	if(v[ind] < 0){
		pdm = dp_pos(ind + 1, men);
		if(men > 0){
			pdm += dp_pos(ind + 1, men - 1);
		}

		pdm %= MOD;
		return pdm;
	}
	else{
		pdm = dp_pos(ind + 1, men);
		if(v[ind] < v[j]){
			pdm += dp_pos(ind + 1, men + 1);
		}
		if(v[ind] >= v[j]){
			pdm += dp_pos(ind + 1, men);
		}
		pdm %= MOD;
		return pdm;
	}
}

int main(){

	fastio;
	cin >> n;

	frr(i, n){
		char c; int x;
		cin >> c;
		if(c == '+'){
			cin >> x;
			v[i] = x;
		}
		else{
			v[i] = -1;
		}
	}

	ll ans = 0;

	frr(i, n){
		if(v[i] > 0){
			j = i;
			//dbg(i);
			ms(memo, -1);

			
			dp_pre();

			
			fr(k, j){
				ll y = dp_pos(j + 1, k);
				ll x = memo[j - 1][k];
				//cout << i << ' ' << k << ' ' << x  << ' ' << y << endl;
				x = (x*y)%MOD;
				ans = (ans + v[i]*x)%MOD;
				//dbg(memo[1][0]);
				
			}
			
		}
	}

	cout << ans << endl;
}
