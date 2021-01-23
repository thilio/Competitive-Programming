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

ll bit[100];
ll e[500100];
ll o[500100];

ll sum;

ll v[500100];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		fr(i,60) bit[i] = 0;
		sum = 0;

		fr(i,n){
			ll x;
			cin >> x;
			v[i] = x;
			int k = 0;
			while(k < 60){
				if(x&1) bit[k]++;
				x /= 2;
				k++;
			}
			sum = (sum + v[i])%MOD;
		}
		ll ans = 0;

		fr(j,n){
			o[j] = 0;
			fr(i,60){
				ll k = 1ll<<i;
				if(v[j]&k){
					o[j] = (o[j] + n*((k)%MOD))%MOD;
				}
				else{
					o[j] = (o[j] + bit[i]*((k)%MOD))%MOD;
				}
			}
		}

		fr(j,n){
			e[j] = sum;
			e[j] = (e[j] + n*(v[j]%MOD))%MOD;
			e[j] = (e[j] + MOD - o[j])%MOD;
		}

		fr(j,n){
			ans = (ans + o[j]*e[j])%MOD;
		}

		cout << ans << endl;


	}

}
