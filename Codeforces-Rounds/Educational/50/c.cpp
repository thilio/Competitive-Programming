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

ll dp(ll k,ll pot, ll men,ll fal){
	if(fal == 0) return 1;
	if(pot == -1) return 1;

	ll dig = k/(pow(10,pot));
	dig %= 10;

	if(men == 1){
		return 9*dp(k,pot-1,men,fal-1) + dp(k,pot-1,men,fal);
	}

	if(dig == 0){
		return dp(k,pot-1,men,fal);
	}

	ll aux = 1;

	aux = dp(k,pot-1,1,fal);

	//dbg(aux);
	//olar;

	frr(i,dig){
		if(i < dig){
			aux += dp(k,pot-1,1,fal-1);
		}
		else
			aux += dp(k,pot-1,0,fal-1);
	}
	//dbg(aux);

	return aux;
}

ll quat(ll k){
	return dp(k,18,0,3);
}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		ll l,r;
		cin >> l >> r;
		cout << quat(r) - quat(l-1) << endl;
	}

}
