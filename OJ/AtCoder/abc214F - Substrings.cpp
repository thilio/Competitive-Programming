#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define endl '\n'
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

string s;
string t;
int n;
ll dp[200200];
ll dp_sum[200200];
int last[200200];
int show[200200][26];

void pre(){
	for(int i = 1; i <= n; i++){
		last[i] = show[i - 1][s[i] - 'a'];
		fr(j, 26) show[i][j] = show[i - 1][j];
		show[i][s[i] - 'a'] = i;
	}
}

int main(){

	fastio;

	cin >> t;
	n = t.size();
	s.pb('$');
	for(auto x: t) s.pb(x);

	pre();

	dp[0] = 1;
	dp_sum[0] = 1;
	dp[1] = 1;
	dp_sum[1] = 2;

	for(int i = 2; i <= n; i++){
		if(last[i] == i - 1){
			dp[i] = dp[i - 2];
			if(i == 2) dp[i] = 0;
		}
		else{
			if(last[i] == 0) dp[i] = dp_sum[i - 2];
			else if(last[i] == 1) dp[i] = (dp_sum[i - 2] - 1 + MOD)%MOD;
			else dp[i] = (dp_sum[i - 2] - dp_sum[last[i] - 2] + MOD)%MOD;
		}
		dp_sum[i] = (dp_sum[i - 1] + dp[i])%MOD;
	}

	cout << (dp_sum[n] - 1 + MOD)%MOD << endl;

}
