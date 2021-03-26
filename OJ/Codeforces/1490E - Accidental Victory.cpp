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
vi ans;
int n;

bool ok(int ind){
	ll sum = 0;

	fr(i, ind + 1) sum += v[i].fst;

	for(int i = ind + 1; i < n; i++){
		if(v[i].fst > sum) return false;
		sum += v[i].fst;
	}

	return true;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		
		cin >> n;
		v.clear();

		frr(i, n){
			ll x;
			cin >> x;
			v.pb(mp(x, i));
		}

		sort(all(v));

		int l = 0;
		int r = n - 1;

		int best = -1;

		while(l <= r){
			int m = (l + r)/2;

			if(ok(m)){
				best = m;
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}

		ans.clear();

		for(int i = best; i < n; i++){
			ans.pb(v[i].snd);
		}

		sort(all(ans));
		cout << ans.size() << endl;
		for(auto x: ans) cout << x << ' ';
		gnl;



	}

}
