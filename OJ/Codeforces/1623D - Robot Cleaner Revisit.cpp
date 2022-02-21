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
const ll MOD = 1e9+7;

int n, m;
int si, sj;
int ei, ej;
int di, dj;
int ati, atj;

ll p;

vector<pii> cycle;

void reset(){
	cycle.clear();
}

ll fast(ll b, ll e){
	if(e == 0) return 1;

	ll ans = fast(b, e / 2);
	ans = (ans * ans)%MOD;
	if(e&1) ans = (ans * b)%MOD;

	return ans;
}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		reset();

		cin >> si >> sj >> ei >> ej;
		cin >> p;
		ati = si; atj = sj;

		di = dj = 1;

		int t = 0;

		do{
			t++;
			cycle.pb({ati, atj});
			ati += di; atj += dj;

			if(ati == 0){
				ati = 2;
				di = -di;
			}
			else if(ati == n + 1){
				ati = n - 1;
				di = -di;
			}

			if(atj == 0){
				atj = 2;
				dj = -dj;
			}
			else if(atj == m + 1){
				atj = m - 1;
				dj = -dj;
			}

		}while(t < 4*(n - 1)*(m - 1));

		reverse(all(cycle));

		ll pb = (1 - p*fast(100, MOD - 2) + 100ll*MOD)%MOD;

		ll u = 0;
		ll v = 1;

		for(auto x: cycle){
			if(x.fst == ei || x.snd == ej){
				u = (pb*(u + 1))%MOD;
				v = (pb*v)%MOD;
			}
			else{
				u = (u + 1)%MOD;
			}

			//dbg(u); dbg(v);
		}

		assert(v != 1);

		ll ans = (u*fast((1 - v + MOD)%MOD, MOD - 2))%MOD;

		cout << ans << endl;


	}
}
