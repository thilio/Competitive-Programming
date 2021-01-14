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

int n;
string s,t;
int sufs[27][2010];
int suft[27][2010];
int memo[2010][2010];

int dp(int i ,int j){
	if(j < 0) return 0;
	if(i < 0) return 0;

	int& pdm = memo[i][j];
	if(pdm != -1) return pdm;

	pdm = 1 + dp(i-1,j);

	if(s[i] == t[j]){
		pdm = min(pdm, dp(i-1,j-1));
	}

	char c = t[j];
	if(sufs[c-'a'][i+1] > suft[c-'a'][j+1]) pdm = min(pdm,dp(i,j-1));

	return pdm;
}

void clear(){

	fr(i,n+1){
		fr(j,27) sufs[j][i] = suft[j][i] = 0;
	}
	fr(i,n){
		fr(j,n){
			memo[i][j] = -1;
		}
	}

}
int main(){

	fastio;
	int T;
	cin >> T;

	while(T--){
		cin >> n;
		getline(cin,s);
		getline(cin,s);
		getline(cin,t);

		clear();

		for(int i = n-1;i >= 0;i--){
			fr(j,27){
				sufs[j][i] = sufs[j][i+1];
				suft[j][i] = suft[j][i+1];
			}

			sufs[s[i] - 'a'][i]++;
			suft[t[i] - 'a'][i]++;
		}

		bool ok = true;

		fr(j,27){
			if(sufs[j][0] != suft[j][0]) ok = false;
		}

		if(!ok){
			cout << -1 << endl;
			continue;
		}

		cout << dp(n-1,n-1) << endl;


	}


}
