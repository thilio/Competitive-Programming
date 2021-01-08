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
vector<ll> divi;

void dd (ll n){
	for(ll i = 1; i*i <= n;i++){
		if (n%i == 0){
			divi.pb(i);
			if(n/i != i)
				divi.pb(n/i);
		}
	}
}

int main(){

	fastio;
	ll n;
	cin >> n;

	dd(n);

	//divi.pb(n);
	//divi.pb(1ll);

	vector<ll> ans;

	fr(i,divi.size()){
		ll k;
		k = n/divi[i];
		ll r = divi[i];
		ll aux;

		aux = k*(2 + (k-1)*r)/2;
		ans.pb(aux);
	}
	sort(all(ans));
	fr(i,ans.size())
		cout << ans[i] <<' ';

	gnl;
}

