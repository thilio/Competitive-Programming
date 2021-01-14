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

int main(){

	fastio;
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		n--;

		if(n == 1ll){
			cout << "1\n" << "0\n";
			continue;
		}

		vector<ll> ans;
		ans.clear();
		ans.pb(1ll);

		for(ll i = 1; i <= 60; i++){
			if((ans[i-1]<<1) >= n){
				ans.pb(n);
				break;
			}

			if((ans[i-1] << 1) <= n/2){
				ans.pb(ans[i-1] << 1);
				n-= (ans[i-1] << 1);
			}
			else{
				ans.pb(n/2);
				n -= (n/2);
			}
		}

		cout << ans.size() - 1 << endl;
		frr(i,ans.size() - 1) cout << ans[i] - ans[i-1] << ' ';
		gnl;



	}

}
