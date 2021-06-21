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
const ll M1 = 1e9+7;
const ll M2 = 999997967;
const ll P1 = 31;
const ll P2 = 37;

int n, k;
string s;
set<pii> S;
ll H1[100100], H2[100100];

ll fast(ll b, ll e, ll M){
	if(e == 0) return 1;
	ll ans = fast(b, e/2, M);
	ans = (ans*ans)%M;
	if(e&1) ans = (ans*b)%M;
	return ans;
}

ll inv(ll a, ll m){
	return fast(a, m - 2, m);
}

void solve(){
	S.clear();

	fr(i, n){
		ll letra = s[i] - 'a' + 1;
		H1[i] = letra*fast(P1, i, M1);
		H2[i] = letra*fast(P2, i, M2);
		H1[i] %= M1;
		H2[i] %= M2;
		if(i != 0){
			H1[i] = (H1[i] + H1[i - 1])%M1;
			H2[i] = (H2[i] + H2[i - 1])%M2;
		}
	}

	for(int i = 0; i + k <= n; i++){
		pll a = {H1[i + k - 1], H2[i + k - 1]};
		if(i != 0){
			a.fst = (a.fst + M1 - H1[i - 1])%M1;
			a.snd = (a.snd + M2 - H2[i - 1])%M2;
		}
		ll p1 = inv(P1, M1);
		ll p2 = inv(P2, M2);

		ll ip1 = fast(p1, i, M1);
		ll ip2 = fast(p2, i, M2);

		a.fst = (a.fst*ip1)%M1;
		a.snd = (a.snd*ip2)%M2;

		S.insert(a);
	}

	cout << S.size() << endl;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		cin >> s;
		solve();
	}

}
