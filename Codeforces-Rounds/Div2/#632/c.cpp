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

ll sum[200100];
ll prox[200100];
map<ll,ll> m;
int main(){

	fastio;
	int T;
	
	T = 1;
	while(T--){
		ll n;
		cin >> n;
		sum[0] = 0ll;
		m[0] = n+1ll;

		frr(i,n){
			ll a;
			cin >> a;
			sum[i] = a + sum[i-1];
			m[sum[i]] = n+1;
		}

		for(int i = n; i >= 0; i--){
			prox[i] = m[sum[i]];
			if(i!=n){
				prox[i] = min(prox[i],prox[i+1]);
			}
			m[sum[i]] = i;
		}

		ll ans = 0ll;

		for(int i = 0ll; i<=n;i++){
			ans += prox[i] - i - 1ll;
		}

		cout << ans << endl;
		
	
	}

}
