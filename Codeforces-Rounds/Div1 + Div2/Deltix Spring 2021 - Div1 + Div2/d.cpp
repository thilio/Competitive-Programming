#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(long long int i=0;i<n;i++)
#define frr(i,n)	for(long long int i=1;i<=n;i++)

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, p;

ll mus[200200];

int v[200200];

int ran(){
	return uniform_int_distribution<int>(1, n)(rng);
}

ll tent(int k){
	//dbg(k);
	ms(v, 0);
	int ct;
	frr(i, n){
		int mask = 0;
		ct = 0;
		fr(j, m){
			ll a = (1ll << j);
			if((mus[i]&a) && (mus[k]&a)){
				mask += (1ll << ct);
			}
			if(mus[k]&a) ct++;
		}
		//dbg(mask);
		v[mask]++;
	}

	fr(j, (1ll << ct)){
		int s = j;
		while(s > 0){
			if(s != j) v[s] += v[j];
			s = (s - 1)&j;
		}
		if(j != 0) v[0] += v[j];
	}

	int ans = 0;
	fr(j, (1ll << ct)){
		if(v[j] >= (n + 1)/2){
			if(__builtin_popcount(j) > __builtin_popcount(ans)) ans = j;
		}
	}

	//dbg(ans);
	ll a = 0;
	ct = 0;
	fr(j, m){
		if((1ll << j)&mus[k]){
			if(ans&(1ll << ct)) a += (1ll << j);
			ct++;
		}
	}
	//dbg(a);
	return a;
}

void print(ll a){
	fr(j, m){
		if((1ll << j)&a) cout << 1;
		else cout << 0;
	}
	gnl;
}

int main(){

	fastio;
	cin >> n >> m >> p;

	ll ans = 0;

	frr(i, n){
		string s;
		cin >> s;
		ll mask = 0;
		fr(j, m){
			if(s[j] == '1') mask += (1ll << j);
		}
		mus[i] = mask;
	}

	frr(i, 50){ // ESSA PORRA TAMBRM
		ll resp = tent(ran()); // MUDAR ESSA PORRA
		if(__builtin_popcountll(resp) > __builtin_popcountll(ans)) ans = resp; 
	}

	print(ans);


}
