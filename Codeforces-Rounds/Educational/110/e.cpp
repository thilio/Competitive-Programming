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

int q;
ll a[300300];
ll c[300300];
int memo[300300][20];

int bb(int v){
	int u = v;
	for(int i = 19; i >= 0; i--){
		if(a[memo[u][i]] > 0) u = memo[u][i];
	}
	return u;
}

int main(){

	fastio;

	cin >> q >> a[0] >> c[0];

	fr(i, 20) memo[i][0] = 0;

	frr(i, q){
		int op;
		cin >> op;

		if(op == 1){
			cin >> memo[i][0] >> a[i] >> c[i];
			frr(j, 19) memo[i][j] = memo[memo[i][j - 1]][j - 1];
		}
		else{
			ll v, w;
			cin >> v >> w;
			ll ans = 0;
			ll resp = 0;
			while(w > 0 && a[v] > 0){
				int u = bb(v);
				ll mn = min(a[u], w);
				ans += mn*c[u];
				resp += mn;
				a[u] -= mn;
				w -= mn;
			}
			cout << resp << ' ' << ans << endl;
		}
	}

}
