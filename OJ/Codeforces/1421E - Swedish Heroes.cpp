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

vector<pll> v;

int special(int n,int k){
	if(n%2 == 0 && k == (n/2)) return 0;
	if(n%2 == 1){
		if(k == ((n - 1)/2)) return 2;
		if(k == ((n + 1)/2)) return 1;
	}

	return -1;
}

int main(){

	fastio;

	int n;
	cin >> n;

	if(n == 1){
		cin >> n;
		cout << n << endl;
		return 0;

	}

	frr(i,n){
		ll x;
		cin >> x;
		v.pb({x,i});
	}

	sort(all(v));

	ll sum = 0;
	for(auto x: v) sum += x.fst;

	ll ans = -llINF;

	for(int k = 0; k <= n; k++){
		//dbg(sum);

		if((k + n)%3 == 1 && special(n,k) < 0){
			if(sum > ans)
				ans = sum;
		}
		else if((k + n)%3 == 1){
			bool spe = true;
			if(special(n,k) == 0){
				fr(i,k){
					if((v[i].snd%2) != (v[0].snd%2) ) spe = false;
				}
			}
			if(special(n,k) == 1){
				fr(i,k){
					if(v[i].snd%2 == 0) spe = false;
				}
			}
			if(special(n,k) == 2){
				fr(i,k){
					if(v[i].snd%2 == 1) spe = false;
				}
			}
			if(spe){
				sum += 2*v[k-1].fst;
				sum -= 2*v[k].fst;
			}

			ans = max(ans,sum);

			if(spe){
				sum -= 2*v[k-1].fst;
				sum += 2*v[k].fst;	
			}
		}

		if(k != n) sum -= 2*v[k].fst;
	}

	cout << ans << endl;



}
