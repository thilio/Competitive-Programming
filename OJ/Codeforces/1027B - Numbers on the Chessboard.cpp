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
ll n,q;

int main(){

	fastio;
	
	cin >> n >> q;
	fr(i,q){
		ll a,b;
		cin >> a >> b;

		if (n%2 == 0){
			ll ans = ((n + 1)/2)*(a-1) + (b+1)/2;
			if((a+b)%2) ans += (n*n + 1)/2;
			cout << ans << endl;
		}
		else{
			ll ans = 0;
			ans += (a/2)*n;
			if(a%2 == 0){ 
				ans -= (n+1)/2;
				if(b%2 == 0) ans++;

			}

			ans += (b + 1)/2;

			if((a + b)%2) ans += (n*n + 1)/2;

			cout << ans <<endl;

		}
	

	}

}
