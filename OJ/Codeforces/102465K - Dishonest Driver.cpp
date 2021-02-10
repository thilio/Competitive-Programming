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
string s;
int rep[800][800];
int dp[800][800];

bool eq(int s1,int s2, int sz){
	fr(i,sz){
		if(s[s1 + i] != s[s2 + i]) return false;
	}
	return true;
}

void go(){
	fr(i,800) fr(j,800) dp[i][j] = n + 1;
	for(int sz = 1; sz <= n; sz++){
		for(int l = 0; l <= n - sz; l++){
			int r = l + sz - 1;
			if(sz == 1){
				dp[l][r] = 1;
			}
			else{
				for(int i = l; i < r; i++){
					int atsz = i - l + 1;
					//if(l == 0 && r == 1) dbg(dp[k][r]);
					if(sz%atsz == 0 && rep[l][i] >= sz/atsz) dp[l][r] = min(dp[l][i], dp[l][r]);
					else dp[l][r] = min(dp[l][r], sz);
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
				}
			}
		}
	}

}

int main(){

	fastio;

	cin >> n;
	getline(cin,s);
	getline(cin,s);

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int sz = j - i + 1;
			int k = i;
			int ct = 0;
			while(k + sz <= n){
				if(eq(i,k,sz)) ct++;
				else break;
				k+=sz;
			}
			rep[i][j] = ct;
		}
	}

	go();

	//dbg(dp[0][1]);
	cout << dp[0][n - 1] << endl;
}
