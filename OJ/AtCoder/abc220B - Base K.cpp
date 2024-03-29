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

ll trans(ll x, ll k){
	ll ans = 0;
	ll base = 1;

	while(x != 0){
		ans += base*(x%10);
		base *= k;
		x/=10;
		//dbg(ans);
	}

	return ans;
}

int main(){

	fastio;

	ll a, b ,k;
	cin >> k >> a >> b;

	//dbg(trans(a, k));

	cout << trans(a, k)*trans(b, k) << endl;

}
