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
int a;
vi v;
ll F[1ll << 21];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		ms(F, 0);
		cin >> n;
		v.clear();
		fr(i, n){cin >> a; F[a]++; v.pb(a);}

		for(int i = 0; i < 20; i++){
			for(int mask = 0; mask < (1ll << 20); mask++){
				if(mask&(1ll << i)) F[mask] += F[mask^(1ll << i)];
			}
		}

		ll ans = 0;
		for(auto x: v) ans += F[x];
			cout << ans << endl;

	}

}
