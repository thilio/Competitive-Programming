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

vi pa, im, v;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		pa.clear();
		im.clear();
		v.clear();

		int n;
		cin >> n;
		fr(i, n){
			int x;
			cin >> x;
			if(x%2) im.pb(x);
			else pa.pb(x);
		}

		for(auto x: pa) v.pb(x);
		for(auto x: im) v.pb(x);


		ll ans = 0;
		fr(i, n){
			for(int j = i + 1; j < n; j++){
				if(__gcd(v[i], 2*v[j]) > 1) ans++;
			}
			//dbg(ans);
		}

		cout << ans << endl;
	}

}
