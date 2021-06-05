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

int n, m;
int E[100100];
vector<pll> loja[100100];
ll dp[100100];

int bb(int i, int s){

	int l = i;
	int r = n + 1;
	int best = i;
	while(l <= r){
		int m = (l + r)/2;
		ll delta = E[m - 1] - E[i - 1];
		if(s >= delta){
			best = m;
			l = m + 1;
		}
		else r = m - 1;
	}

	return best;
}

int main(){

	fastio;
	cin >> n >> m;
	frr(i, n) cin >> E[i];
	frr(i, n) E[i] += E[i - 1];

	frr(i, m){
		int x, s, c;
		cin >> x >> s >> c;
		loja[x].pb({s, c});
	}

	multiset<pair<ll, ll >> S;
	multiset<ll> val;

	S.insert({1, 0});
	val.insert(0);

	for(int i = 1; i <= n + 1; i++){
		if(val.empty()){
			dp[n + 1] = -1;
			break;
		}
		dp[i] = (*val.begin());
//		dbg(dp[i]);

		for(auto x: loja[i]){
			int k = bb(i, x.fst);
			S.insert({k, dp[i] + x.snd});
			val.insert(dp[i] + x.snd);
		}

		while(!S.empty()){
			auto it = S.begin();
			pll a = (*it);
			if(a.fst > i) break;
			val.erase(val.find(a.snd));
			S.erase(it);
		}
		//dbg(S.size());
		//dbg(val.size());
	}

	cout << dp[n + 1] << endl;

}
