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

int k1,k2,k3;
int n;
int v[200100];
int memo[200200][4];

int dp(int ind,int who){
	if(ind > n) return 0;

	int& pdm = memo[ind][who];

	if(pdm != -1) return pdm;

	pdm = INF;
	if(who < 3) pdm = dp(ind,who+1);

	if(who == v[ind]) pdm = min(pdm,dp(ind+1,who));
	if(who != v[ind]) pdm = min(pdm,1 + dp(ind+1,who));

	return pdm; 
}

int main(){

	fastio;
	cin >> k1 >> k2 >> k3;
	n = k1 + k2 + k3;

	ms(memo,-1);

	fr(i,k1){
		int a;
		cin >> a;
		v[a] = 1;
	}

	fr(i,k2){
		int a;
		cin >> a;
		v[a] = 2;
	}

	fr(i,k3){
		int a;
		cin >> a;
		v[a] = 3;
	}

	cout << dp(1,1) << endl;


}
