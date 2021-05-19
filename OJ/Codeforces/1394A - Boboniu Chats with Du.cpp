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

ll n, d, m;

int main(){

	fastio;

	cin >> n >> d >> m;

	vector<ll> b, s;
	vector<ll> bsum, ssum;

	fr(i, n){
		ll x;
		cin >> x;
		if(x <= m) s.pb(x);
		else b.pb(x);
	}

	sort(all(b));
	sort(all(s));
	reverse(all(b));
	reverse(all(s));

	bsum.resize(b.size());
	ssum.resize(s.size());

	fr(i, b.size()){
		if(i == 0) bsum[i] = b[i];
		else bsum[i] = bsum[i - 1] + b[i];
	}
	fr(i, s.size()){
		if(i == 0) ssum[i] = s[i];
		else ssum[i] = ssum[i - 1] + s[i];
	}

	ll ans = 0;
	if(s.size() > 0) ans = ssum[s.size() - 1];

	for(ll x = 1; x <= b.size(); x++){
		ll tent = bsum[x - 1];
		ll days = n;
		days -= (x - 1)*(d + 1) + 1;
		if(days < 0) continue;
		days = min((ll)s.size(), days);
		if(days > 0) tent += ssum[days - 1];
		ans = max(ans, tent);
	}

	cout << ans << endl;

}
