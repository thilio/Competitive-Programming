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

vector<pll> v;
int mn[200200];
int n, m;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		v.clear();
		cin >> n >> m;
		ll sum = 0;
		ll mx = -llINF;

		frr(i, n){
			ll x;
			cin >> x;
			sum += x;
			if(mx < sum) mx = sum;
			v.pb(mp(sum, i));
		}


		sort(all(v));
		for(int i = n - 1; i >= 0; i--){
			mn[i] = v[i].snd;
			if(i != n - 1) mn[i] = min(mn[i], mn[i + 1]);
		}


		ll full = sum;

		frr(i, m){
			ll x;
			cin >> x;

			if(x <= mx){
				auto it = upper_bound(all(v), mp(x, -1ll));
				int pos = it - v.begin();
				ll a = mn[pos];
				cout << a - 1 << ' ';
			}
			else if(full <= 0){
				cout << -1 << ' ';
			}
			else{
				ll dif = x - mx;
				ll cycle = dif/full;
				if(dif%full != 0) cycle++;

				ll ans = cycle*n;
				x -= cycle*full;

				auto it = upper_bound(all(v), mp(x, -1ll));
				int pos = it - v.begin();
				ll a = mn[pos];
				cout << a - 1 + ans << ' ';

			}
		}
		gnl;

	}

}
