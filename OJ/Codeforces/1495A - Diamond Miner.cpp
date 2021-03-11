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
vector<ll> miner, mine;

int main(){

	fastio;

	cout << setprecision(15) << fixed;
	int T;
	cin >> T;
	while(T--){
		ll x, y;
		int n;
		cin >> n;

		miner.clear();
		mine.clear();

		frr(i,2*n){
			cin >> x >> y;
			if(x == 0){
				miner.pb(abs(y));
			}
			else{
				mine.pb(abs(x));
			}
		}

		sort(all(mine));
		sort(all(miner));

		long double ans = 0;

		fr(i,n){
			long double a, b;
			a = mine[i];
			b = miner[i];
			ans += hypot(a,b);
		}

		cout << ans << endl;
	}
}
