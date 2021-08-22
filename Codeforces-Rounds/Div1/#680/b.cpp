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
const int MOD = 998244353;

ll fat[300300];
ll C;
ll n;

ll fexp(ll b, ll e){
	if(e == 0) return 1;
	ll ans = fexp(b, e/2);
	ans = (ans * ans)%MOD;
	if(e&1) ans = (ans * b)%MOD;
	return ans;
}

ll inv(ll x){
	return fexp(x, MOD - 2);
}

void precomp(){
	fat[0] = 1;
	for(ll i = 1; i <= 2*n; i++){
		fat[i] = (i*fat[i - 1])%MOD;
	}

	ll i = inv(fat[n]);

	C = fat[2*n];
	C = (C*i)%MOD;
	C = (C*i)%MOD;
}
	
int main(){

	fastio;
	cin >> n;

	precomp();

	//frr(i, 100) dbg(fat[i]);

	vector<ll> v;
	frr(i, 2*n){
		ll x;
		cin >> x;
		v.pb(x);
	}

	sort(all(v));

	ll sum = 0;

	fr(i, 2*n){
		if(i < n) sum -= v[i];
		else sum += v[i];
	}

	sum %= MOD;

	sum = (sum*C)%MOD;

	cout << sum << endl;


}
