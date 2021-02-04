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
ll n;
ll c[100100];
ll memo[100100];
ll a[100100];
ll b[100100];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		frr(i,n){
			cin >> c[i];
		}
		frr(i,n) cin >> a[i];
		frr(i,n) cin >> b[i];

		memo[1] = -INF;

		for(int i = 2; i <= n; i++){
			if(a[i] == b[i]){
				memo[i] = (c[i] - 1) + 2;
			}

			if(a[i] < b[i]){
				memo[i] = (c[i] - 1) + (b[i] - a[i]) + 2;
				memo[i] = max(memo[i], (c[i] - 1) + 2 + (a[i] - 1) + (c[i - 1] - b[i]) + memo[i - 1] - c[i - 1] + 1);
			}

			if(b[i] < a[i]){
				memo[i] = (c[i] - 1) + (a[i] - b[i]) + 2;
				memo[i] = max(memo[i], (c[i] - 1) + 2 + (b[i] - 1) + (c[i - 1] - a[i]) + memo[i - 1] - c[i - 1] + 1);
			}
		}

		ll best = 0;
		frr(i,n) best = max(best,memo[i]);
		//frr(i,n) dbg(memo[i]);
		cout << best << endl;
 	}

}
