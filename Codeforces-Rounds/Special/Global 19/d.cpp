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

vector<ll> a, b;
ll n;

ll memo[10100][120];
ll sum[120];

void reset(){
	fr(i, 10100){
		frr(j, n + 1) memo[i][j] = -1;
	}
	frr(i,n) sum[i] = 0;
}

ll dp(int sump, int i){
	if(i > n) return 0;

	ll &pdm = memo[sump][i];

	if(pdm != -1) return pdm;

	pdm = 0;

	ll suma, sumb;
	if(i == 0){
		suma = sumb = 0;
	}
	else{
		suma = sump;
		sumb = sum[i - 1] - sump;
	}

	pdm = min(
			a[i]*suma + b[i]*sumb + dp(suma + a[i], i + 1),
			a[i]*sumb + b[i]*suma + dp(suma + b[i], i + 1)
		);

	return pdm;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		a.clear(); b.clear();

		cin >> n;

		reset();
		a.pb(0);
		b.pb(0);

		sum[0] = 0;

		frr(i, n){
			int x; cin >> x;
			a.pb(x);
			sum[i] += x;
		}
		frr(i, n){
			int x; cin >> x;
			b.pb(x);
			sum[i] += x;
		}

		frr(i, n) sum[i] += sum[i - 1];


		if(n == 1){
			cout << 0 << endl;
			continue;
		}

		ll ans = 0;

		for(auto x: a) ans += x*x;
		for(auto x: b) ans += x*x;

		//dbg(dp(0 , 1));


		cout << ans*(n - 1) + 2*dp(0, 1) << endl;


	}

}
