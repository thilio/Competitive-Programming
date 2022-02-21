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
vector<ll> save;
vector<ll> buf;
int n;

void reset(){
	v.clear();
	save.clear();
	buf.resize(n, 0);
}

bool tent(ll m){
	fr(i, n) buf[i] = 0;
	v = save;
	for(int i = n - 1; i > 1; i--){
		if(v[i] + buf[i] < m) return false;
		ll final = max(m - buf[i], 0ll);
		ll doar = v[i] - final;

		doar /= 3;

		buf[i - 1] += doar;
		buf[i - 2] += 2*doar;
	}

	if(v[1] + buf[1] >= m && v[0] + buf[0] >= m) return true;
	return false;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
	
		cin >> n;

		reset();

		fr(i, n){
			int x; cin >> x;
			v.pb(x);
		}
		save = v;

		int l = 1;
		int r = 1000000000;

		int best = -1;

		while(l <= r){
			int m = (l + r)/2;
			if(tent(m)){
				best = m;
				l = m + 1;
			}
			else
				r = m - 1;
		}

		cout << best << endl;
	}

}
