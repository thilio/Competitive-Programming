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
const ll MOD = 1e9+7;

ll sum[40];
ll qtos[40];
int n;
ll pd[33][33];
ll bino[33][33];

void precomp(){
	for(int i = 0; i <= 32; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 || j == i){
				bino[i][j] = 1;
			}
			else{
				bino[i][j] = (bino[i-1][j - 1] + bino[i-1][j])%MOD;
			}
		}
	}
}

ll bin(ll n, ll k){
	return bino[n][k];
}

void dp(ll lim){
	ms(pd,0);
  
  if(lim < 0) return;

	if(lim&1){
		pd[0][1] = 1;
    pd[0][0] = 1;
	}
  else{
  	pd[0][1] = 1;
  }

	for(ll bit = 1; bit <= 30; bit++){
		for(ll f = 0; f <= 30; f++){
			if((lim&(1ll << bit)) == 0){
				if(f == 0){
					pd[bit][f] = 0;
				}
				else
					pd[bit][f] = pd[bit - 1][f - 1];
			}
			else{
				pd[bit][f] = pd[bit - 1][f];
				if(f != 0){
					pd[bit][f] = (pd[bit][f] + bin(bit, f - 1))%MOD;
				}
			}
		}
	}
}

int main(){

	fastio;
	cin >>  n;
	precomp();

	fr(i,n){
		int op;
		cin >> op;
		if(op == 1){
			int l,r;
			cin >> l >> r;
			ll ans = 0;
			for(int i = l; i < r; i++){
				ans = (ans + sum[i])%MOD;
			}
			cout << ans << endl;
		}
		else{
			ll l,r,x;
			cin >> l >> r >> x;

			dp(r - 1);
			for(int i = 0; i <= 30; i++) qtos[i] = pd[29][i];

			dp(l - 1);
			for(int i = 0; i <= 30; i++) qtos[i] = (qtos[i] + MOD - pd[29][i])%MOD;

			for(int i = 0; i <= 30; i++) sum[i] = (sum[i] + qtos[i]*x)%MOD;
		}
	}


}
