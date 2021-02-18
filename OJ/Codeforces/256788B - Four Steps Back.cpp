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

int perm[100100];
vi adj[100100];
int qtos[100100];
int vis[100100];
int tam;

ll dp[100100];

void dfs(int v){
	vis[v] = 1;
	tam++;

	for(auto x: adj[v]){
		if(!vis[x]) dfs(x);
	}
}

ll pd(ll y, ll z){
	fr(i,z + 1) dp[i] = 0;
	if(y%2 == 0){
		dp[0] = 1;
		for(ll i = 4; i <= z; i+= 4){
			dp[i] = (y*y*y)%MOD;
			dp[i] *= ((i - 1)*(i - 2)*(i - 3))%MOD;
			dp[i] %= MOD;
			dp[i] *= dp[i - 4];
			dp[i] %= MOD;
		}
		return dp[z];
	}
	else{
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 1 + y;
		dp[3] = 1 + 3*y;

		for(ll i = 4; i <= z; i++){
			dp[i] = (y*y*y)%MOD;
			dp[i] *= ((i - 1)*(i - 2)*(i - 3))%MOD;
			dp[i] %= MOD;
			dp[i] *= dp[i - 4];
			dp[i] %= MOD;

			dp[i] += (((i - 1)*y)%MOD)*dp[i - 2];
			dp[i] %= MOD;

			dp[i] += dp[i - 1];
			dp[i] %= MOD;
		}
		return dp[z];
	}
}


int main(){

	fastio;
	int n;
	cin >> n;

	fr(i,n) cin >> perm[i];

	fr(i,n){
		adj[i].pb(perm[i]);
	}

	fr(i,n){
		if(!vis[i]){
			tam = 0;
			dfs(i);
			qtos[tam]++;
		}
	}

	ll ans = 1;

	for(int i = 1; i <= n; i++){
		if(qtos[i] == 0) continue;
		ans *= pd(i, qtos[i]);
		ans %= MOD;
	}

	cout << ans << endl;

}
