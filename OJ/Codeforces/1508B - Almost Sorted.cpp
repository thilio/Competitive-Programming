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

ll f(ll x){
	if(x == 0) return 1;
	return (1ll << (x - 1));
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		ll n, k;
		cin >> n >> k;
		vi ans;

		if(n <= 61 && k > f(n)){
			cout << -1 << endl;
			continue;
		}

		int i = 1;

		while(i <= n){
			if ((n - i) >= 61 || f(n - i) >= k){
				ans.pb(i);
				i++;
				continue;
			}

			ll sum = f(n - i);
			for(int j = i + 1; j <= n; j++){
				sum += f(n - i - (j - i));
				if(sum >= k){
					//dbg(j);
					for(int l = j; l >= i; l--) ans.pb(l);
					k -= sum;
					k += f(n - i - (j - i));
					i = j + 1;
					break;
				}
			}
			
			
		}

		for(auto x: ans) cout << x << ' ';
		gnl;

	}

}
