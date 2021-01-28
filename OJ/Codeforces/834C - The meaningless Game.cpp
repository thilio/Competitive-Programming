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

ll pw(ll x){

	double l = 0.0;
	double r = x;
	double m;
	fr(i,100){
		m = (l+r)/2;

		if(m*m*m <= x) l = m;
		else r = m;

	}

	return m;
}

ll sq(ll x){
	ll p = floor(pw(x));
	p--;

	while(p*p*p < x) p++;

	return p;
}

int main(){

	fastio;

	int n;
	cin >> n;

	fr(i,n){
		ll a;

		ll b;

		cin >> a >> b;

		ll x = sq(a*b);

		bool ok = true;

		if(x*x*x != a*b) ok = false;

		if(a%x || b%x) ok = false;

		if(ok) cout << "yes\n";
		else cout << "no\n";
	}

}
