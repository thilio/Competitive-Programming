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

int main(){

	fastio;
	string s;
	ll n;
	cin >> n;
	getline(cin,s);
	getline(cin,s);
	bool bonus = false;
	if(s[0] == s[n-1]) bonus = true;

	int i = 0;
	while(s[i] == s[0] && i<n){
		i++;
	}

	ll l = i;

	i = n-1;
	while(s[i] == s[n-1] && i>=0){
		i--;
	}

	ll r = n - 1 - i;

	if(l==n){
		ll ans= n;
		ans = n*(n-1);
		ans = ans/2;
		ans%=MOD;
		cout << ans<<endl;
		return 0;
	}

	ll ans = l + r + 1;

	if(bonus){
		ans+= l*r;
		ans%= MOD;
	}

	ans%=MOD;

	cout << ans << endl;

}
