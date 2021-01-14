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
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

vll a;
vll b;
vll c;

ll A;
ll B;
ll C;

int main(){

	fastio;
	int T;
	cin >> T;
	
	while(T--){
		a.clear();
		b.clear();
		c.clear();
		
		ll n;
		cin >> n;

		ll d = n;
		while(d%3 != 1) d--;

		ll pot = 1ll;

		while(4*pot <= d) pot*= 4;

		ll dif = d - pot;
		ll pad = (pot/4)*3;
		a.pb(0);
		a.pb(1);

		while(pad >= 3){
			ll k = dif/pad;

			if(k == 0){
				a.pb(0);
				a.pb(0);
			}
			if(k == 1){
				a.pb(0);
				a.pb(1);
			}
			if(k == 2){
				a.pb(1);
				a.pb(0);
			}
			if(k == 3){
				a.pb(1);
				a.pb(1);
			}

			dif %= pad;
			pad/=4;

		}

		fr(i,a.size()/2){
			pll aux;
			aux.fst = a[2*i];
			aux.snd = a[2*i + 1];

			if(aux.fst == 0 && aux.snd == 0){
				b.pb(0);
				b.pb(0);
			}
			if(aux.fst == 0 && aux.snd == 1){
				b.pb(1);
				b.pb(0);
			}
			if(aux.fst == 1 && aux.snd == 0){
				b.pb(1);
				b.pb(1);
			}
			if(aux.fst == 1 && aux.snd == 1){
				b.pb(0);
				b.pb(1);
			}

			c.pb(aux.fst^b[2*i]);
			c.pb(aux.snd^b[2*i + 1]);
		}

		ll x = 1;

		A = B = C = 0;

		for(int i = a.size() - 1; i>= 0; i--){
			A += a[i]*x;
			B += b[i]*x;
			C += c[i]*x;

			x = x << 1;

		}

		if(n%3 == 0) cout << C << endl;
		if(n%3 == 2) cout << B << endl;
		if(n%3 == 1) cout << A << endl;
	}

}
