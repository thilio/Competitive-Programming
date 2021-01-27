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

ll n,k;
vector<ll> v;
int m[100100];

int is(ll a){
	int l,r;
	l=0;
	r=n-1;
	while(l <= r){
		int m = (l+r)/2;
		if(v[m] == a) return m;
		if(v[m] > a) r = m-1;
		if(v[m] < a) l = m + 1;
	}

	return -1;
	
}

int main(){

	fastio;
	cin >> n >> k;
	if(k==1){
		cout << n << endl;
		return 0;
	}
	fr(i,n){
		ll a;
		cin >> a;
		v.pb(a);
	}

	sort(all(v));

	ll ans = 0;

	fr(i,n){
		if(m[i] == 1) continue;
		m[i] = 1;
		ll p = 0ll;
		ll x = v[i];

		ll aux = is(x);
		while(aux != -1){
			m[aux]=1;
			x*=k;
			aux = is(x);
			p++;
		}
		//dbg(p);

		ans += (p+1)/2;
	}

	cout << ans << endl;
}
