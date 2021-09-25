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
vector<ll> v;

ll sum;

int main(){

	fastio;

	int n;
	cin >> n;
	fr(i, n){
		ll a; cin >> a; v.pb(a);
	}
	sort(all(v));
	for(auto x: v) sum += x;

	int m;
	cin >> m;

	fr(i, m){
		ll x, y; cin >> x >> y;

		auto it = lower_bound(all(v), x);

		if(it == v.end()){
			//cout << "!!! \n";
			--it;
			ll val = *(it);
			cout << x - val + max(y - (sum - val), 0ll) << endl;
		}
		else if(it == v.begin()){
			//cout << "??? \n";
			ll val = *(it); 
			cout << max(y - (sum - val), 0ll) << endl;
		}
		else{
			//cout << "$$$ \n";
			ll val = *(it);
			ll op1 = max(y - (sum - val), 0ll);
			--it;
			val = *(it);
			ll op2 = (x - val) + max(y - (sum - val), 0ll);
			cout << min(op1, op2) << endl;
		}

	}


}
