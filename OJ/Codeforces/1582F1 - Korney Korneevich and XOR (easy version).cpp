#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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
const int N = (1 << 9);

int dp[600][2];

int main(){

	fastio;

	int n;
	cin >> n;

	dp[0][0] = 0;
	for(int i = 1; i < (1 << 9); i++) dp[i][0] = INF;

	frr(i, n){
		int x;
		cin >> x;

		for(int i = 0; i < N; i++){
			dp[i][1] = dp[i][0];
		}

		for(int i = 0; i < (1 << 9); i++){
			if(dp[i][0] < x){
				dp[i^x][1] = min(dp[i^x][1], x);
			}
		}

		for(int i = 0; i < N; i++){
			dp[i][0] = dp[i][1];
		}
	}

	vi ans;

	for(int i = 0; i < N; i++){
		if(dp[i][0] < INF) ans.pb(i);
	}

	cout << ans.size() << endl;
	for(auto x: ans) cout << x << ' ';
		gnl;

}
