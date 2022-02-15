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
const int MOD = 1e9+7;

int n;

ll memo[120][120];
int v[120];

int p[120];

void reset(){
	frr(i, n) frr(j, n) memo[i][j] = -1;
	frr(i, n + 2) p[i] = v[i] = 0;
}

ll dp(int l, int r){
	if(l > r) return 0;

	ll& pdm = memo[l][r];
	if(pdm != -1) return pdm;

	pdm = 0;

	int mex = 0;

	for(int k = l; k <= r; k++){
		dp(k + 1, r);
	}

	for(int i = 0; i <= r - l + 2; i++) p[i] = 0;

	for(int k = l; k <= r; k++){
		p[min(v[k], n + 2)] = 1;
		while(p[mex] != 0) mex++;

		pdm = max(pdm, 1 + mex + dp(k + 1, r));
	}

	return pdm;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		reset();
		frr(i, n) cin >> v[i];

		ll ans = 0;

		frr(i, n){
			for(int j = i; j <= n; j++){
				ans += dp(i, j);

				//dbg(dp(i, j));
			}
		}

		cout << ans << endl;


	}

}
