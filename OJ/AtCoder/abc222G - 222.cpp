#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

int phi(int m){
	int ans = m;
	for(ll i = 2; i*i <= m; i++){
		if(m % i == 0){
			while(m%i == 0) m/= i;
			ans -= ans/i;
		}
		
	}
	if(m > 1){
		ans -= ans/m;
	}

	return ans;
}

vector<int> div(int n){
	vector<int> ans;
	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			ans.pb(i);
			ans.pb(n/i);
		}
	}
	
	sort(all(ans));
	return ans;
}

ll fast(ll base, int e, ll m){
	if(e == 0) return 1;
	ll ans = fast(base, e/2, m);
	ans = (ans*ans)%m;
	if(e&1) ans = (ans*base)%m;
	return ans;
}

int solve(int k){
	int m = 9*k;
	if(m%2 == 0) m /= 2;
	//dbg(phi(m));
	for(auto x: div(phi(m))){
		if(fast(10, x, m) == 1) return x;
	}
	return -1;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int k;
		cin >> k;
		cout << solve(k) << endl;
	}

}
