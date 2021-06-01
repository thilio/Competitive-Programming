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
const int MOD =  998244353;

int prime[2001000];
ll acum = 0;
int n;

void pre(){
	for(int i = 2; i <= n; i++){
		if(prime[i] == 0){
			for(int j = i; j <= n; j += i){
				prime[j] = i;
			}
		}
	}
}

int fac(int x){
	ll div = 1;
	while(x != 1){
		ll k = prime[x];
		ll ct = 0;
		while(x%k == 0){
			ct++;
			x/=k;
		}
		div *= (ct + 1);
	}
	return div;
}

int main(){

	fastio;

	cin >> n;
	n *= 2;
	pre();

	//dbg(fac(3));
	ll ans = 0;
	for(int i = 2; i <= n; i+= 2){
		ans = fac(i/2);
		
		ans = (ans + acum)%MOD;
		acum = (ans + acum)%MOD;
		//dbg(ans);
		//dbg(acum);
	}

	cout << ans << endl;

}
