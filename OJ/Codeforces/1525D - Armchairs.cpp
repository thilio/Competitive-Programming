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

vi ff, ee;
int nf, ne;

ll memo[5050][5050];

ll dp(int i, int j){
	if(i == nf) return 0;
	if(j == ne) return INF;

	ll& pdm = memo[i][j];
	if(pdm != -1) return pdm;

	pdm = dp(i, j + 1);
	pdm = min(pdm, abs(ff[i] - ee[j]) + dp(i + 1, j + 1));
	return pdm; 
}

int main(){

	fastio;

	int n;

	cin >> n;
	frr(i, n){
		int x;
		cin >> x;
		if(x) ff.pb(i);
		else ee.pb(i);
	}
	nf = ff.size();
	ne = ee.size();

	ms(memo, -1);

	cout << dp(0, 0) << endl;

}
