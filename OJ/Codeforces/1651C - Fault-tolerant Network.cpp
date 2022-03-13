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
vector<ll> a, b;

ll al, ar, bl, br;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		a.clear();
		b.clear();
		cin >> n;

		fr(i, n){
			int x; cin >> x; a.pb(x);
		}

		fr(i, n){
			int x; cin >> x; b.pb(x);
		}

		al = ar = bl = br = llINF;

		for(int i = 0; i < n ; i++){
			al = min(al, abs(b[i] - a[0]));
			ar = min(ar, abs(b[i] - a[n - 1]));

			bl = min(bl, abs(a[i] - b[0]));
			br = min(br, abs(a[i] - b[n - 1]));
		}

		ll ans = llINF;

		// two connections

		ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
		ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));

		// three connection

		ans = min(ans, abs(a[0] - b[0]) + ar + br);
		ans = min(ans, abs(a[0] - b[n - 1]) + ar + bl);
		ans = min(ans, abs(a[n - 1] - b[0]) + al + br);
		ans = min(ans, abs(a[n - 1] - b[n - 1]) + al + bl);

		// four connections

		ans = min(ans, al + ar + bl + br);

		cout << ans << endl;

	}

}
