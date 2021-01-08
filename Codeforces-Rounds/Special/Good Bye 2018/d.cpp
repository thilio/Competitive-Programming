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

ll fat[1123456];

ll fast(int bas,int p){
	if(p == 0) return 1ll;
	ll ans = fast(bas,p/2);

	ans*=ans;
	ans%=MOD;

	if(p%2) ans*=bas;
	ans%= MOD;

	return ans;
}

ll inv(ll k){
	return fast(k,MOD-2);
}

ll ffat(){
	fat[0] = 1;
	frr(i,1000010){
		fat[i] = i*fat[i-1];
		fat[i] %= MOD;
	}
}

int main(){

	fastio;

	ll n;
	cin >> n;
	ffat();

	ll ans = fat[n];

	ll aux;
	for (ll k = 2;k<n;k++){
		aux = fat[n];
		aux*= inv(fat[n-k-1]);
		aux%=MOD;
		aux*=inv(n-k+1);
		aux%=MOD;

		aux*= (k-1);
		aux%=MOD;

		ans += aux;
		ans%=MOD;
	}

	cout << ans <<endl;

}
