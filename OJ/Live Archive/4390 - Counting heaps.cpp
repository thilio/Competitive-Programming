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

int memo[500500];
vi adj[500500];
int pri[500500];
int mul[500500];

void dfs(int v){
	memo[v] = 1;


	for(auto x:adj[v]){
		dfs(x);
		memo[v] += memo[x];
	}
}
void primos(){
	pri[1] = 1;

	for(int i = 2; i <= 500000;i++){
		if(pri[i] == 0){
			pri[i] = i;
			for(int j = i; j <= 500000;j += i){
				if(pri[j] == 0) pri[j] = i;
			}
		}
	} 

}

void decomp(int n){

	while(n!=1){
		int x = pri[n];
		mul[x]++;
		n /= x;
	}

}

void neg(int n){

	while(n!=1){
		int x = pri[n];
		mul[x]--;
		n /= x;
	}

}

int main(){

	fastio;
	int T;
	cin >> T;
	primos();
	while(T--){
		int n,m;
		cin >> n >> m;

		if(n == 1){
			cout << 1 << endl;
			continue;
		}

		frr(i,n) adj[i].clear();

		for(int i =2; i <=n ;i++){
			int x;
			cin >> x;
			adj[x].pb(i);
		}

		dfs(1);

		for(int i =2;i < n;i++ ){
			decomp(i);
		}
		for(int i = 2; i<= n; i++){
			neg(memo[i]);
		}

		ll ans = 1ll;

		for(int j = 2; j <= 500000;j++){
			while(mul[j] != 0){
				ans *= j;
				mul[j]--;
				ans %= m;
			}
		}

		cout << ans << endl;

	}

}
