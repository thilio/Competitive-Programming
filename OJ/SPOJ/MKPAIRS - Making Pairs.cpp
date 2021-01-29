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
ll a[1010],b[1010];
ll sa[1010],sb[1010];
ll dp[1010][1010];
vector<pll> lin[1010];
vector<pll> col[1010];
vector<double> rel_lin[1010];
vector<double> rel_col[1010];

void add_lin(ll i, ll sl, ll cf){
	ll n = lin[i].size();
	if(n == 0){
		lin[i].pb(mp(sl,cf));
		rel_lin[i].pb(-INF);
		return;
	}
	else{
		while(n!=0){
			pll reta = lin[i][n-1];
			if(reta.fst == sl){
				if(reta.snd >= cf) return;
				else{
					lin[i].pop_back();
					rel_lin[i].pop_back();
					n--;
				}
			}
			else{
				double inter_x = (double)(cf - reta.snd)/(double)(reta.fst - sl);
				if(inter_x <= rel_lin[i][n-1]){
					lin[i].pop_back();
					rel_lin[i].pop_back();
					n--;
				}
				else{
					lin[i].pb(mp(sl,cf));
					rel_lin[i].pb(inter_x);
					break;
				}
			}
		}
	}

}

void add_col(ll i, ll sl, ll cf){
	int n = col[i].size();
	if(n == 0){
		col[i].pb(mp(sl,cf));
		rel_col[i].pb(-INF);
		return;
	}
	else{
		while(n!=0){
			pll reta = col[i][n-1];
			if(reta.fst == sl){
				if(reta.snd >= cf) return;
				else{
					col[i].pop_back();
					rel_col[i].pop_back();
					n--;
				}
			}
			else{
				double inter_x = (double)(cf - reta.snd)/(double)(reta.fst - sl);
				if(inter_x <= rel_col[i][n-1]){
					col[i].pop_back();
					rel_col[i].pop_back();
					n--;
				}
				else{
					col[i].pb(mp(sl,cf));
					rel_col[i].pb(inter_x);
					break;
				}
			}
		}
	}

}
ll query_lin(ll i,ll x){
	if(rel_lin[i].size() == 0) return 0;
	auto it = upper_bound(all(rel_lin[i]),x);
	it--;

	int j = (int)(it - rel_lin[i].begin());

	pll ret = lin[i][j];
	return ret.fst*x + ret.snd;

}


ll query_col(ll i,ll x){
	if(rel_col[i].size() == 0) return 0;
	auto it = upper_bound(all(rel_col[i]),x);
	it--;

	int j = (int)(it - rel_col[i].begin());
	
	pll ret = col[i][j];
	return ret.fst*x + ret.snd;
	
}


int32_t main(){

	fastio;

	cin >> n;

	frr(i,n){
		cin >> a[i];
		sa[i] = a[i] + sa[i-1];
	}
	frr(i,n){
		cin >> b[i];
		sb[i] = b[i] + sb[i-1];
	}

	frr(i,n){
		dp[i][1] = a[i]*b[1]- sa[i-1]*sa[i-1];
		dp[1][i] = a[1]*b[i] - sb[i-1]*sb[i-1];
	}


	for(int i = 2; i <= n ; i++){
		for(int j = 2; j <= n ;j++){
			add_col(j-1,2*sa[i-1],dp[i-1][j-1] - sa[i-1]*sa[i-1]);
			add_lin(i-1,2*sb[j-1],dp[i-1][j-1] - sb[j-1]*sb[j-1]);
			dp[i][j] = a[i]*b[j];
			dp[i][j] += max(query_lin(i-1,sb[j-1]) - (sb[j-1]*sb[j-1]),query_col(j-1,sa[i-1]) - (sa[i-1]*sa[i-1]));	
		}
	}

	ll ans = 0;

	for(int i = 1;i <= n; i++){
		for(int j = 1; j<= n; j++){
			ans = max(ans,dp[i][j] - (sa[n] - sa[i])*(sa[n] - sa[i]) - (sb[n] - sb[j])*(sb[n] - sb[j]));
		}
	}

	cout << ans << endl;



}
