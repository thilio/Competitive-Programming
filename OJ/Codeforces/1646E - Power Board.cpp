#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
//#define endl '\n'
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

int n, m;

ll dp[30];
bool freq[20000100];
bool marked[1000100];

int main(){

	fastio;

	cin >> n >> m;

	set<ll> S;
	for(ll i = 1; i <= 20; i++){
		dp[i] = dp[i - 1];
		for(ll j = 1; j <= m; j++){
			if(!freq[i*j]){
				freq[i*j] = true;
				dp[i]++;
			}
		}
//		dp[i] = S.size();
	}


	ll ans = 1;

	for(ll i = 2; i <= n; i++){
		if(marked[i]) continue;

		ll k = 1;
		ll at = i*i;
		marked[i] = true;
		while(at <= n){
			k++;
			marked[at] = true;
			at *= i;
		}

		ans += dp[k];
	}

	cout << ans << endl;

}
