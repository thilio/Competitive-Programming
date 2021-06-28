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

int c[200];
ll b[200];
int n;
ll x;

ll memo[120][10010];

ll pd(ll i, ll sum){
	if(i == n + 1) return 1;

	ll& pdm = memo[i][sum];
	if(pdm != -1) return pdm;

	pdm = 0;

	for(int j = 0; j <= c[i]; j++){
		if(sum + j >= i*x + b[i]){
			pdm = (pdm + pd(i + 1, sum + j))%MOD;
		}
	}

	return pdm;
}


int main(){

	fastio;

	cin >> n;

	frr(i, n) cin >> c[i];
	for(int i = 2; i <= n; i++) cin >> b[i];

	for(int i = 1; i <= n; i++) b[i] += b[i - 1];
	for(int i = 1; i <= n; i++) b[i] += b[i - 1];
	
	cin >> x >> x;
	ms(memo, -1);
	cout << pd(1, 0) << endl; 

}
