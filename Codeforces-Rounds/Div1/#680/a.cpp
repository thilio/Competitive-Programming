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

map<int, int> m;
ll p, q;

ll tent(ll x, ll f){
	ll resp = p;
	while(resp%x == 0) resp /= x;

	fr(i, f - 1) resp *= x;
	return resp;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> p >> q;
		if(p%q != 0){
			cout << p << endl;
		}
		else{
			ll ans = 1;
			for(int i = 2; i*i <= q; i++){
				if(q%i == 0){
					int ct = 0;
					while(q%i == 0){
						q /= i;
						ct++;
					}
					ans = max(ans, tent(i, ct));
				}
			}

			if(q != 1) ans = max(ans, tent(q, 1));

			cout << ans << endl;
		}
	}

}
