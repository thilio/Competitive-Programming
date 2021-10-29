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

int n;
vector<ll> v[3];

ll point_best(ll val, ll j){
	auto it = upper_bound(all(v[j]), val);

	ll a, b;
	a = b = llINF; 
	if(it != v[j].end()) a = (*it) - val;
	if(it != v[j].begin()){
		it--;
		b = val - (*it);
	}
	return min(a, b);
}

ll vector_best(ll i, ll j, ll& best){
	ll b = llINF;
	for(auto x: v[i]){
		if(b > point_best(x, j)){
			best = x;
			b = point_best(x, j);
		}
	}
	return b;
}

int main(){

	fastio;

	//dbg(point_best(3, 0));

	cin >> n;

	frr(i, 2*n){
		ll x; char c;
		cin >> x >> c;
		if(c == 'R') v[0].pb(x);
		if(c == 'B') v[1].pb(x);
		if(c == 'G') v[2].pb(x);
	}

	sort(all(v[0])); sort(all(v[1])); sort(all(v[2]));

	if(v[0].size()%2 == 0 && v[1].size()%2 == 0 && v[2].size()%2 == 0){
		cout << 0 << endl;
		return 0;
	}
	else if(v[0].size()%2 != 0){
		if(v[1].size()%2 == 0) swap(v[0], v[1]);
		else swap(v[0], v[2]);
	}

	ll aux, best1, best2;
	ll ans = vector_best(1, 2, aux);

	ll a = vector_best(0, 1, best1);
	ll b = vector_best(0, 2, best2);


	if(best1 != best2) ans = min(ans, a + b);

	cout << ans << endl;


}
