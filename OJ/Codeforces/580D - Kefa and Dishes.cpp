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

ll memo[20][1123456];
int bonus[20][20];
int peso[20];
int n,m,k;

ll pd(int mask,int last){
	if(__builtin_popcount(mask) == m)
		return (0);

	ll &pdm = memo[last][mask];
	
	if (pdm!= -1ll){
		return pdm;
	}

	ll mx = 0;

	fr(i,n){
		ll aux = 0;
		if((mask & (1 << i)) == 0){
			aux = pd((mask|1<<i),i) + peso[i] + bonus[last + 1][i + 1];
		}
		mx = max(mx,aux);
	}

	pdm = mx;

	return (pdm);

}

int main(){

	fastio;
	
	cin >> n;
	cin >> m;
	cin >> k;
	
	fr(i,n){
		cin >> peso[i];
	}

	fr(i,k){
		int a,b,g;
		cin >> a >> b >> g;
		bonus[a][b] = g;
	}
	ms(memo,-1);

	ll ans;
	ans = 0;
	fr(i,n){
		ans = max(ans,pd((1<<i),i) + peso[i]);
	}

	cout << ans << endl;

}
