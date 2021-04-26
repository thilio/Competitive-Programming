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

int dig(ll x){
	int k = 0;
	while(x != 0){
		k++;
		x /= 10;
	}
	return k;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		ll a,b,c;
		cin >> a >> b >> c;
		ll na,nb,nc;
		na = nb = nc = 1;

		while(dig(nc) != c){
			nc *= 2ll;
			na *= 2ll;
			nb *= 2ll;
		}

		while(dig(na) != a){
			na *= 3ll;
		}
		while(dig(nb) != b){
			nb *= 5ll;
		}

		cout << na << ' ' << nb << endl;

		//dbg(__gcd(na, nb));

	}

	

}
