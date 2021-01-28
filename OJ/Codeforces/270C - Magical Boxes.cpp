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

int solve(ll sz,ll qtd){
	if(qtd == 1ll) return (sz + 1);

	ll resp = sz;
	while(qtd != 1ll){
		qtd = (qtd + 3)/4;
		resp++;
	}

	return resp;
}

int main(){

	fastio;

	int n;
	cin >> n;

	ll ans = -1;
	fr(i,n){
		long long k,a;
		cin >> k >> a;
		ll x = solve(k,a);
		if(x >  ans) ans = x;
		//dbg(ans);
	}

	cout << ans << endl;

}
