#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(ll i=0;i<n;i++)
#define frr(i,n)	for(ll i=1;i<=n;i++)

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

vector<ll> v;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		v.clear();
		fr(i, n){
			ll d;
			cin >> d;
			v.pb(d);
		}

		ll ans = 0;
		sort(all(v));
		ll sum = 0;

		for(ll i = 1; i < n; i++){
			ll x = v[i];
			ll termo = v[i] - v[i - 1];
			termo -= x*i - sum;
			ans += termo;
			sum += x; 
		}

		cout << ans << endl;
	}

}
