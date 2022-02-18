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

int n, l, k;
int d[505];
int a[505];

ll memo[505][505];

ll dp(int pos, int remove){
	if(pos == n) return 0;

	ll &pdm = memo[pos][remove];
	if(pdm != -1) return pdm;

	int j = 0;
	int est = pos;

	pdm = INF;
	ll t = 0;
	ll vel = a[pos];

	while(j <= remove && est < n){
		t += (d[est + 1] - d[est])*vel;
		pdm = min(pdm, t + dp(est + 1, remove - j));
		j++;	
		est++;
	}

	return pdm;
}

int main(){

	fastio;
	cin >> n >> l >> k;

	ms(memo, -1);

	fr(i, n) cin >> d[i];
	fr(i, n) cin >> a[i];

	d[n] = l;

	cout << dp(0, k) << endl;
}
