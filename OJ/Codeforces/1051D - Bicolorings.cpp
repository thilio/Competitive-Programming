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
const int MOD =  998244353;
int m[4][4];
ll n,k;

ll memo[1002][2004][4];

ll pd(int ind,int comp,int mask){
	if (comp > k) return 0;
	if(ind == n){
		if(comp == k) return 1;
		return 0;
	}

	ll &pdm = memo[ind][comp][mask];
	if(pdm!= -1) return pdm;

	pdm = 0;
	fr(i,4){
		pdm+= pd(ind + 1,comp + m[mask][i],i);
		pdm = pdm%MOD;
	}

	return pdm;

}

int main(){

	fastio;

	cin >> n >> k;
	ms(memo,-1);
	fr(i,4) m[i][i] = 0;

	m[0][1] = 1;
	m[0][2] = 1;
	m[0][3] = 1;

	m[1][0] = 0;
	m[1][2] = 2;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 2;
	m[2][3] = 0;

	m[3][0] = 1;
	m[3][1] = 1;
	m[3][2] = 1;

	ll ans;

	ans = pd(1,1,0);
	ans = ans%MOD;
	ans += pd(1,2,1);
	ans = ans%MOD;
	ans += pd(1,2,2);
	ans = ans%MOD;
	ans += pd(1,1,3);
	ans = ans%MOD;

	cout << ans << endl;

}
