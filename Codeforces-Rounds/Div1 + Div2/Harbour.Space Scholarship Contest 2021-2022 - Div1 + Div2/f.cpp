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
const ll N = 300200;

ll bit[2*N];
int n;
ll v[N + 300];
ll s[N + 300], t[N + 300];

void modify(int x, ll val){
	while(x <= 2*N){
		bit[x] += val;
		x += (x&(-x));
	}
}

void modify(int l, int r, ll val){
	modify(r + 1, -val);
	modify(l, val);
}

ll sum(int x){
	ll ans = 0;
	while(x > 0){
		ans += bit[x];
		x -= (x&(-x));
	}
	return ans;
}

ll sum(int l, int r){
	return sum(r) - sum(l - 1);
}


int main(){

	fastio;
	cin >> n;
	frr(i, n) cin >> v[i];

	s[0] = 0;

	for(ll i = 1; i <= n; i++){
		s[i] = s[i - 1] + (i - 1)*v[i] + sum(v[i]);

		ll k = v[i];
		while(k <= N){
			modify(k, k + v[i] - 1, -k);
			k += v[i];
		}

	}

	t[0] = 0;
	ll soma = 0;

	fr(i, 2*N) bit[i] = 0;

	for(ll i = 1; i <= n; i++){
		t[i] = t[i - 1] + soma;
		soma += v[i];

		ll k = v[i];
		while(k <= N){
			t[i] -= k*sum(k, k + v[i] - 1);
			k += v[i];
		}
		modify(v[i], 1);
	}

	frr(i, n) cout << s[i] + t[i] << ' ';
	gnl;

}
